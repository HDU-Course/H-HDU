
  #include "math.h"
  #include "stdlib.h"
  int dngin(m,n,eps1,eps2,x,ka)
  int m,n,ka;
  double eps1,eps2,x[];
  { extern void dnginf();
    extern void dngins();
    extern int agmiv();
    int i,j,k,l,kk,jt;
    double y[10],b[10],alpha,z,h2,y1,y2,y3,y0,h1;
    double *p,*d,*pp,*dx,*u,*v,*w;
    p=malloc(m*n*sizeof(double));
    d=malloc(m*sizeof(double));
    pp=malloc(n*m*sizeof(double));
    dx=malloc(n*sizeof(double));
    u=malloc(m*m*sizeof(double));
    v=malloc(n*n*sizeof(double));
    w=malloc(ka*sizeof(double));
    l=60; alpha=1.0;
    while (l>0)
      { dnginf(m,n,x,d);
        dngins(m,n,x,p);
        jt=agmiv(p,m,n,d,dx,pp,eps2,u,v,ka);
        if (jt<0)
          { free(p); free(d); free(pp); free(w);
            free(dx); free(u); free(v); return(jt);
          }
        j=0; jt=1; h2=0.0;
        while (jt==1)
          { jt=0;
            if (j<=2) z=alpha+0.01*j;
            else z=h2;
            for (i=0; i<=n-1; i++) w[i]=x[i]-z*dx[i];
            dnginf(m,n,w,d);
            y1=0.0;
            for (i=0; i<=m-1; i++) y1=y1+d[i]*d[i];
            for (i=0; i<=n-1; i++)
              w[i]=x[i]-(z+0.00001)*dx[i];
            dnginf(m,n,w,d);
            y2=0.0;
            for (i=0; i<=m-1; i++) y2=y2+d[i]*d[i];
            y0=(y2-y1)/0.00001;
            if (fabs(y0)>1.0e-10)
              { h1=y0; h2=z;
                if (j==0) { y[0]=h1; b[0]=h2;}
                else
                  { y[j]=h1; kk=0; k=0;
                    while ((kk==0)&&(k<=j-1))
                        { y3=h2-b[k];
                          if (fabs(y3)+1.0==1.0) kk=1;
                          else h2=(h1-y[k])/y3;
                          k=k+1;
                        }
                    b[j]=h2;
                    if (kk!=0) b[j]=1.0e+35;
                    h2=0.0;
                    for (k=j-1; k>=0; k--)
                      h2=-y[k]/(b[k+1]+h2);
                    h2=h2+b[0];
                  }
                j=j+1;
                if (j<=7) jt=1;
                else z=h2;
              }
          }
        alpha=z; y1=0.0; y2=0.0;
        for (i=0; i<=n-1; i++)
          { dx[i]=-alpha*dx[i];
            x[i]=x[i]+dx[i];
            y1=y1+fabs(dx[i]);
            y2=y2+fabs(x[i]);
          }
        if (y1<eps1*y2)
          { free(p); free(pp); free(d); free(w);
            free(dx); free(u); free(v); return(1);
          }
        l=l-1;
      }
    free(p); free(pp); free(d); free(dx);
    free(u); free(v); free(w); return(0);
  }

