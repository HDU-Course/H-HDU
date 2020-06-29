
  #include "stdlib.h"
  int jcplx(n,m,a,b,alpha,eps,x,xx,k)
  int n,m,k;
  double a[],b[],alpha,eps,x[],xx[];
  { extern double jcplxf();
    extern void jcplxs();
    double rn();
    int r,g,i,j,it,kt,jt,kk;
    double fj,fr,fg,z,rr,*c,*d,*w,*xt,*xf;
    c=malloc(m*sizeof(double));
    d=malloc(m*sizeof(double));
    w=malloc(m*sizeof(double));
    xt=malloc(n*sizeof(double));
    xf=malloc(n*sizeof(double));
    rr=0.0;
    for (i=0; i<=n-1; i++)
      xx[i*n*2]=x[i];
    xx[n*n*2]=jcplxf(x,n);
    for (j=1; j<=2*n-1; j++)
      { for (i=0; i<=n-1; i++)
	  { xx[i*n*2+j]=a[i]+(b[i]-a[i])*rn(&rr);
            x[i]=xx[i*n*2+j];
          }
        it=1;
        while (it==1)
          { it=0; r=0; g=0;
            while ((r<n)&&(g==0))
              { if ((a[r]<=x[r])&&(b[r]>=x[r])) r=r+1;
                else g=1;
              }
            if (g==0)
              { jcplxs(n,m,x,c,d,w);
                r=0;
                while ((r<m)&&(g==0))
                  { if ((c[r]<=w[r])&&(d[r]>=w[r])) r=r+1;
                    else g=1;
                  }
              }
            if (g!=0)
              { for (r=0; r<=n-1; r++)
                  { z=0.0;
                    for (g=0; g<=j-1; g++)
                      z=z+xx[r*n*2+g]/(1.0*j);
                    xx[r*n*2+j]=(xx[r*n*2+j]+z)/2.0;
                    x[r]=xx[r*n*2+j];
                  }
                it=1;
              }
            else xx[n*n*2+j]=jcplxf(x,n);
          }
      }
    kk=1; it=1;
    while (it==1)
      { it=0;
        fr=xx[n*n*2]; r=0;
        for (i=1; i<=2*n-1; i++)
          if (xx[n*n*2+i]>fr)
            { r=i; fr=xx[n*n*2+i];}
        g=0; j=0; fg=xx[n*n*2];
        if (r==0)
          { g=1; j=1; fg=xx[n*n*2+1];}
        for (i=j+1; i<=2*n-1; i++)
          if (i!=r)
            if (xx[n*n*2+i]>fg)
              { g=i; fg=xx[n*n*2+i];}
        for (i=0; i<=n-1; i++)
          { xf[i]=0.0;
            for (j=0; j<=2*n-1; j++)
              if (j!=r)
                xf[i]=xf[i]+xx[i*n*2+j]/(2.0*n-1.0);
            xt[i]=(1.0+alpha)*xf[i]-alpha*xx[i*n*2+r];
          }
        jt=1;
        while (jt==1)
          { jt=0;
            z=jcplxf(xt,n);
            while (z>fg)
              { for (i=0; i<=n-1; i++)
                  xt[i]=(xt[i]+xf[i])/2.0;
                z=jcplxf(xt,n);
              }
            j=0;
            for (i=0; i<=n-1; i++)
              { if (a[i]>xt[i])
                  { xt[i]=xt[i]+0.000001; j=1;}
                if (b[i]<xt[i])
                  { xt[i]=xt[i]-0.000001; j=1;}
              }
            if (j!=0) jt=1;
            else
              { jcplxs(n,m,xt,c,d,w);
                j=0; kt=1;
                while ((kt==1)&&(j<m))
                  { if ((c[j]<=w[j])&&(d[j]>=w[j])) j=j+1;
                    else kt=0;
                  }
                if (j<m)
                  { for (i=0; i<=n-1; i++)
                      xt[i]=(xt[i]+xf[i])/2.0;
                    jt=1;
                  }
              }
          }
        for (i=0; i<=n-1; i++)
          xx[i*n*2+r]=xt[i];
        xx[n*n*2+r]=z;
        fr=0.0; fg=0.0;
        for (j=0; j<=2*n-1; j++)
          { fj=xx[n*n*2+j];
            fr=fr+fj/(2.0*n);
            fg=fg+fj*fj;
          }
        fr=(fg-2.0*n*fr*fr)/(2.0*n-1.0);
        if (fr>=eps)
          { kk=kk+1;
            if (kk<k) it=1;
          }
      }
    for (i=0; i<=n-1; i++)
      { x[i]=0.0;
        for (j=0; j<=2*n-1; j++)
          x[i]=x[i]+xx[i*n*2+j]/(2.0*n);
      }
    z=jcplxf(x,n); x[n]=z;
    free(c); free(d); free(w);
    free(xt); free(xf);
    return(kk);
  }

  static double rn(rr)
  double *rr;
  { int m;
    double y,s,u,v;
    s=65536.0; u=2053.0; v=13849.0;
    *rr=u*(*rr)+v; m=*rr/s; *rr=*rr-m*s;
    y=*rr/s;
    return(y);
  }

