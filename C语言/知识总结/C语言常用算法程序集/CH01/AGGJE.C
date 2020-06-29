
  #include "stdlib.h"
  #include "math.h"
  #include "stdio.h"
  int aggje(a,n,b)
  int n;
  double a[],b[];
  { int *js,i,j,k,is,u,v;
    double d,t;
    js=malloc(n*sizeof(int));
    for (k=0; k<=n-1; k++)
      { d=0.0;
        for (i=k; i<=n-1; i++)
        for (j=k; j<=n-1; j++)
          { t=fabs(a[i*n+j]);
            if (t>d) {d=t; js[k]=j; is=i;}
          }
        if (d+1.0==1.0)
          { free(js); printf("fail\n"); return(0);}
        if (is!=k)
          { for (j=k; j<=n-1; j++)
              { u=k*n+j; v=is*n+j;
                t=a[u]; a[u]=a[v]; a[v]=t;
              }
            t=b[k]; b[k]=b[is]; b[is]=t;
          }
        if (js[k]!=k)
          for (i=0; i<=n-1; i++)
            { u=i*n+k; v=i*n+js[k];
              t=a[u]; a[u]=a[v]; a[v]=t;
            }
        t=a[k*n+k];
        for (j=k+1; j<=n-1; j++)
          { u=k*n+j;
            if (a[u]!=0.0) a[u]=a[u]/t;
          }
        b[k]=b[k]/t;
        for (j=k+1; j<=n-1; j++)
          { u=k*n+j;
            if (a[u]!=0.0)
              { for (i=0; i<=n-1; i++)
                  { v=i*n+k;
                    if ((i!=k)&&(a[v]!=0.0))
                      { is=i*n+j;
                        a[is]=a[is]-a[v]*a[u];
                      }
                  }
              }
          }
        for (i=0; i<=n-1; i++)
          { u=i*n+k;
            if ((i!=k)&&(a[u]!=0.0))
              b[i]=b[i]-a[u]*b[k];
          }
      }
    for (k=n-1; k>=0; k--)
      if (k!=js[k])
        { t=b[k]; b[k]=b[js[k]]; b[js[k]]=t;}
    free(js);
    return(1);
  }

