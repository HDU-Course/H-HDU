
  #include "stdlib.h"
  #include "math.h"
  int jjsim(n,d,u,v,x,eps,k,xx,f)
  int n,k;
  double d,u,v,x[],eps,xx[],f[];
  { int r,g,i,j,l,kk;
    double nn,fe,fr,fl,fg,ft,ff,fs;
    double *xt,*xf,*xe;
    extern double jjsimf();
    xt=malloc(n*sizeof(double));
    xf=malloc(n*sizeof(double));
    xe=malloc(n*sizeof(double));
    kk=0; nn=1.0*n;
    fr=sqrt(nn+1.0);
    fl=d*(fr-1.0)/(1.414*nn);
    fg=d*(fr+nn-1.0)/(1.414*nn);
    for(i=0; i<=n-1; i++)
    for(j=0; j<=n; j++)
       xx[i*(n+1)+j]=0.0;
    for(i=1; i<=n; i++)
    for(j=0; j<=n-1; j++)
       xx[j*(n+1)+i]=fl;
    for(i=1; i<=n; i++)
       xx[(i-1)*(n+1)+i]=fg;
    for(i=0; i<=n; i++)
      { for(j=0; j<=n-1; j++)
           { xt[j]=xx[j*(n+1)+i]; }
        f[i]=jjsimf(xt,n);
      }
    ft=1.0+eps;
    while ((kk<k)&&(ft>eps))
      { kk=kk+1;
        fr=f[0]; fl=f[0]; r=0; l=0;
        for (i=1; i<=n; i++)
          { if (f[i]>fr) { r=i; fr=f[i];}
            if (f[i]<fl) { l=i; fl=f[i];}
          }
        g=0; fg=f[0];
        j=0;
        if (r==0) { g=1; fg=f[1]; j=1;}
        for (i=j+1; i<=n; i++)
          if ((i!=r)&&(f[i]>fg))
            { g=i; fg=f[i];}
        for (j=0; j<=n-1; j++)
          { xf[j]=0.0;
            for (i=0; i<=n; i++)
              if (i!=r)
                xf[j]=xf[j]+xx[j*(n+1)+i]/nn;
            xt[j]=2.0*xf[j]-xx[j*(n+1)+r];
          }
        ft=jjsimf(xt,n);
        if (ft<f[l])
          { for (j=0; j<=n-1; j++)
              xf[j]=(1.0+u)*xt[j]-u*xf[j];
            ff=jjsimf(xf,n);
            if (ff<f[l])
              { for (j=0; j<=n-1; j++)
                  xx[j*(n+1)+r]=xf[j];
                f[r]=ff;
              }
            else
              { for (j=0; j<=n-1; j++)
                  xx[j*(n+1)+r]=xt[j];
                f[r]=ft;
              }
          }
        else
          { if (ft<=f[g])
              { for (j=0; j<=n-1; j++)
                  xx[j*(n+1)+r]=xt[j];
                f[r]=ft;
              }
            else 
              { if (ft<=f[r])
                  { for (j=0; j<=n-1; j++)
                      xx[j*(n+1)+r]=xt[j];
                    f[r]=ft;
                  }
                for (j=0; j<=n-1; j++)
                  xf[j]=v*xx[j*(n+1)+r]+(1.0-v)*xf[j];
                ff=jjsimf(xf,n);
                if (ff>f[r])
                  for (i=0; i<=n; i++)
                    { for (j=0; j<=n-1; j++)
                        { xx[j*(n+1)+i]=(xx[j*(n+1)+i]+
					xx[j*(n+1)+l])/2.0;
                          x[j]=xx[j*(n+1)+i]; xe[j]=x[j];
                        }
                      fe=jjsimf(xe,n); f[i]=fe;
                    }
                else
                  { for (j=0; j<=n-1; j++)
                      xx[j*(n+1)+r]=xf[j];
                    f[r]=ff;
                  }
              }
          }
        ff=0.0; ft=0.0;
        for (i=0; i<=n; i++)
          { ff=ff+f[i]/(1.0+nn);
            ft=ft+f[i]*f[i];
          }
        ft=(ft-(1.0+n)*ff*ff)/nn;
      }
    for (j=0; j<=n-1; j++)
      { x[j]=0.0;
        for (i=0; i<=n; i++)
          x[j]=x[j]+xx[j*(n+1)+i]/(1.0+nn);
        xe[j]=x[j];
      }
    fe=jjsimf(xe,n); x[n]=fe;
    free(xt); free(xf); free(xe);
    return(kk);
  }

