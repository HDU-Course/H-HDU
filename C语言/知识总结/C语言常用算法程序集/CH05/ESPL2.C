
  #include "stdlib.h"
  double espl2(x,y,n,dy,ddy,t,m,z,dz,ddz)
  int n,m;
  double x[],y[],dy[],ddy[],t[],z[],dz[],ddz[];
  { int i,j;
    double h0,h1,alpha,beta,g,*s;
    s=malloc(n*sizeof(double));
    dy[0]=-0.5;
    h0=x[1]-x[0];
    s[0]=3.0*(y[1]-y[0])/(2.0*h0)-ddy[0]*h0/4.0;
    for (j=1;j<=n-2;j++)
      { h1=x[j+1]-x[j];
        alpha=h0/(h0+h1);
        beta=(1.0-alpha)*(y[j]-y[j-1])/h0;
        beta=3.0*(beta+alpha*(y[j+1]-y[j])/h1);
        dy[j]=-alpha/(2.0+(1.0-alpha)*dy[j-1]);
        s[j]=(beta-(1.0-alpha)*s[j-1]);
        s[j]=s[j]/(2.0+(1.0-alpha)*dy[j-1]);
        h0=h1;
      }
    dy[n-1]=(3.0*(y[n-1]-y[n-2])/h1+ddy[n-1]*h1/
            2.0-s[n-2])/(2.0+dy[n-2]);
    for (j=n-2;j>=0;j--)
      dy[j]=dy[j]*dy[j+1]+s[j];
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
      { if (t[j]>=x[n-1]) i=n-2;
        else
          { i=0;
            while (t[j]>x[i+1]) i=i+1;
          }
        h1=(x[i+1]-t[j])/s[i];
        h0=h1*h1;
        z[j]=(3.0*h0-2.0*h0*h1)*y[i];
        z[j]=z[j]+s[i]*(h0-h0*h1)*dy[i];
        dz[j]=6.0*(h0-h1)*y[i]/s[i];
        dz[j]=dz[j]+(3.0*h0-2.0*h1)*dy[i];
        ddz[j]=(6.0-12.0*h1)*y[i]/(s[i]*s[i]);
        ddz[j]=ddz[j]+(2.0-6.0*h1)*dy[i]/s[i];
        h1=(t[j]-x[i])/s[i];
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