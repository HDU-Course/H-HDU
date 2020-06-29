
  #include "stdlib.h"
  #include "stdio.h"
  int acgas(ar,ai,n,br,bi)
  int n;
  double ar[],ai[],br[],bi[];
  { int *js,l,k,i,j,is,u,v;
    double p,q,s,d;
    js=malloc(n*sizeof(int));
    for (k=0;k<=n-2;k++)
      { d=0.0;
        for (i=k;i<=n-1;i++)
        for (j=k;j<=n-1;j++)
          { u=i*n+j;
            p=ar[u]*ar[u]+ai[u]*ai[u];
            if (p>d) {d=p;js[k]=j;is=i;}
          }
        if (d+1.0==1.0)
          { free(js); printf("err**fail\n");
            return(0);
          }
        if (is!=k)
          { for (j=k;j<=n-1;j++)
              { u=k*n+j; v=is*n+j;
                p=ar[u]; ar[u]=ar[v]; ar[v]=p;
                p=ai[u]; ai[u]=ai[v]; ai[v]=p;
              }
            p=br[k]; br[k]=br[is]; br[is]=p;
            p=bi[k]; bi[k]=bi[is]; bi[is]=p;
          }
        if (js[k]!=k)
          for (i=0;i<=n-1;i++)
            { u=i*n+k; v=i*n+js[k];
              p=ar[u]; ar[u]=ar[v]; ar[v]=p;
              p=ai[u]; ai[u]=ai[v]; ai[v]=p;
            }
        v=k*n+k;
        for (j=k+1;j<=n-1;j++)
          { u=k*n+j;
            p=ar[u]*ar[v]; q=-ai[u]*ai[v];
            s=(ar[v]-ai[v])*(ar[u]+ai[u]);
            ar[u]=(p-q)/d; ai[u]=(s-p-q)/d;
          }
        p=br[k]*ar[v]; q=-bi[k]*ai[v];
        s=(ar[v]-ai[v])*(br[k]+bi[k]);
        br[k]=(p-q)/d; bi[k]=(s-p-q)/d;
        for (i=k+1;i<=n-1;i++)
          { u=i*n+k;
            for (j=k+1;j<=n-1;j++)
              { v=k*n+j; l=i*n+j;
                p=ar[u]*ar[v]; q=ai[u]*ai[v];
                s=(ar[u]+ai[u])*(ar[v]+ai[v]);
                ar[l]=ar[l]-p+q;
                ai[l]=ai[l]-s+p+q;
              }
            p=ar[u]*br[k]; q=ai[u]*bi[k];
            s=(ar[u]+ai[u])*(br[k]+bi[k]);
            br[i]=br[i]-p+q; bi[i]=bi[i]-s+p+q;
          }
      }
    u=(n-1)*n+n-1;
    d=ar[u]*ar[u]+ai[u]*ai[u];
    if (d+1.0==1.0)
      { free(js); printf("err**fail\n");
        return(0);
      }
    p=ar[u]*br[n-1]; q=-ai[u]*bi[n-1];
    s=(ar[u]-ai[u])*(br[n-1]+bi[n-1]);
    br[n-1]=(p-q)/d; bi[n-1]=(s-p-q)/d;
    for (i=n-2;i>=0;i--)
    for (j=i+1;j<=n-1;j++)
      { u=i*n+j;
        p=ar[u]*br[j]; q=ai[u]*bi[j];
        s=(ar[u]+ai[u])*(br[j]+bi[j]);
        br[i]=br[i]-p+q;
        bi[i]=bi[i]-s+p+q;
      }
    js[n-1]=n-1;
    for (k=n-1;k>=0;k--)
      if (js[k]!=k)
        { p=br[k]; br[k]=br[js[k]]; br[js[k]]=p;
          p=bi[k]; bi[k]=bi[js[k]]; bi[js[k]]=p;
        }
    free(js);
    return(1);
  }

