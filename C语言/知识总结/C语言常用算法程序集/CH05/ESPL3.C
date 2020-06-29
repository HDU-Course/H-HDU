
  #include "stdlib.h"
  double espl3(x,y,n,dy,ddy,t,m,z,dz,ddz)
  int n,m;
  double x[],y[],dy[],ddy[],t[],z[],dz[],ddz[];
  { int i,j;
    double h0,y0,h1,y1,alpha,beta,u,g,*s;
    s=malloc(n*sizeof(double));
    h0=x[n-1]-x[n-2];
    y0=y[n-1]-y[n-2];
    dy[0]=0.0; ddy[0]=0.0; ddy[n-1]=0.0;
    s[0]=1.0; s[n-1]=1.0;
    for (j=1;j<=n-1;j++)
      { h1=h0; y1=y0;
        h0=x[j]-x[j-1];
        y0=y[j]-y[j-1];
        alpha=h1/(h1+h0);
        beta=3.0*((1.0-alpha)*y1/h1+alpha*y0/h0);
        if (j<n-1)
          { u=2.0+(1.0-alpha)*dy[j-1];
            dy[j]=-alpha/u;
            s[j]=(alpha-1.0)*s[j-1]/u;
            ddy[j]=(beta-(1.0-alpha)*ddy[j-1])/u;
          }
      }
    for (j=n-2;j>=1;j--)
      { s[j]=dy[j]*s[j+1]+s[j];
        ddy[j]=dy[j]*ddy[j+1]+ddy[j];
      }
    dy[n-2]=(beta-alpha*ddy[1]-(1.0-alpha)*ddy[n-2])/
            (alpha*s[1]+(1.0-alpha)*s[n-2]+2.0);
    for (j=2;j<=n-1;j++)
        dy[j-2]=s[j-1]*dy[n-2]+ddy[j-1];
    dy[n-1]=dy[0];
    for (j=0;j<=n-2;j++) s[j]=x[j+1]-x[j];
    for (j=0;j<=n-2;j++)
      { h1=s[j]*s[j];
        ddy[j]=6.0*(y[j+1]-y[j])/h1-2.0*(2.0*dy[j]+dy[j+1])/s[j];
      }
    h1=s[n-2]*s[n-2];
    ddy[n-1]=6.*(y[n-2]-y[n-1])/h1+2.*(2.*dy[n-1]+dy[n-2])/s[n-2];
    g=0.0;
    for (i=0;i<=n-2;i++)
      { h1=0.5*s[i]*(y[i]+y[i+1]);
        h1=h1-s[i]*s[i]*s[i]*(ddy[i]+ddy[i+1])/24.0;
        g=g+h1;
      }
    for (j=0;j<=m-1;j++)
      { h0=t[j];
        while (h0>=x[n-1]) h0=h0-(x[n-1]-x[0]);
        while (h0<x[0]) h0=h0+(x[n-1]-x[0]);
        i=0;
        while (h0>x[i+1]) i=i+1;
        u=h0;
        h1=(x[i+1]-u)/s[i];
        h0=h1*h1;
        z[j]=(3.0*h0-2.0*h0*h1)*y[i];
        z[j]=z[j]+s[i]*(h0-h0*h1)*dy[i];
        dz[j]=6.0*(h0-h1)*y[i]/s[i];
        dz[j]=dz[j]+(3.0*h0-2.0*h1)*dy[i];
        ddz[j]=(6.0-12.0*h1)*y[i]/(s[i]*s[i]);
        ddz[j]=ddz[j]+(2.0-6.0*h1)*dy[i]/s[i];
        h1=(u-x[i])/s[i];
        h0=h1*h1;
        z[j]=z[j]+(3.0*h0-2.0*h0*h1)*y[i+1];
        z[j]=z[j]-s[i]*(h0-h0*h1)*dy[i+1];
        dz[j]=dz[j]-6.0*(h0-h1)*y[i+1]/s[i];
        dz[j]=dz[j]+(3.0*h0-2.0*h1)*dy[i+1];
        ddz[j]=ddz[j]+(6.0-12.0*h1)*y[i+1]/(s[i]*s[i]);
        ddz[j]=ddz[j]-(2.0-6.0*h1)*dy[i+1]/s[i];
      }
    free(s);
    return(g);
  }

