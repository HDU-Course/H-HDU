
  #include "stdlib.h"
  #include "stdio.h"
  int bcinv(ar,ai,n)
  int n;
  double ar[],ai[];
  { int *is,*js,i,j,k,l,u,v,w;
    double p,q,s,t,d,b;
    is=malloc(n*sizeof(int));
    js=malloc(n*sizeof(int));
    for (k=0; k<=n-1; k++)
      { d=0.0;
        for (i=k; i<=n-1; i++)
        for (j=k; j<=n-1; j++)
          { u=i*n+j;
            p=ar[u]*ar[u]+ai[u]*ai[u];
            if (p>d) { d=p; is[k]=i; js[k]=j;}
          }
        if (d+1.0==1.0)
          { free(is); free(js); printf("err**not inv\n");
            return(0);
          }
        if (is[k]!=k)
          for (j=0; j<=n-1; j++)
            { u=k*n+j; v=is[k]*n+j;
              t=ar[u]; ar[u]=ar[v]; ar[v]=t;
              t=ai[u]; ai[u]=ai[v]; ai[v]=t;
            }
        if (js[k]!=k)
          for (i=0; i<=n-1; i++)
            { u=i*n+k; v=i*n+js[k];
              t=ar[u]; ar[u]=ar[v]; ar[v]=t;
              t=ai[u]; ai[u]=ai[v]; ai[v]=t;
            }
        l=k*n+k;
        ar[l]=ar[l]/d; ai[l]=-ai[l]/d;
        for (j=0; j<=n-1; j++)
          if (j!=k)
            { u=k*n+j;
              p=ar[u]*ar[l]; q=ai[u]*ai[l];
              s=(ar[u]+ai[u])*(ar[l]+ai[l]);
              ar[u]=p-q; ai[u]=s-p-q;
            }
        for (i=0; i<=n-1; i++)
          if (i!=k)
            { v=i*n+k;
              for (j=0; j<=n-1; j++)
                if (j!=k)
                  { u=k*n+j;  w=i*n+j;
                    p=ar[u]*ar[v]; q=ai[u]*ai[v];
                    s=(ar[u]+ai[u])*(ar[v]+ai[v]);
                    t=p-q; b=s-p-q;
                    ar[w]=ar[w]-t;
                    ai[w]=ai[w]-b;
                  }
            }
        for (i=0; i<=n-1; i++)
          if (i!=k)
            { u=i*n+k;
              p=ar[u]*ar[l]; q=ai[u]*ai[l];
              s=(ar[u]+ai[u])*(ar[l]+ai[l]);
              ar[u]=q-p; ai[u]=p+q-s;
            }
      }
    for (k=n-1; k>=0; k--)
      { if (js[k]!=k)
          for (j=0; j<=n-1; j++)
            { u=k*n+j; v=js[k]*n+j;
              t=ar[u]; ar[u]=ar[v]; ar[v]=t;
              t=ai[u]; ai[u]=ai[v]; ai[v]=t;
            }
        if (is[k]!=k)
          for (i=0; i<=n-1; i++)
            { u=i*n+k; v=i*n+is[k];
              t=ar[u]; ar[u]=ar[v]; ar[v]=t;
              t=ai[u]; ai[u]=ai[v]; ai[v]=t;
            }
      }
    free(is); free(js);
    return(1);
  }

