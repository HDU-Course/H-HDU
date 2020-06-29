
  #include "stdlib.h"
  #include "math.h"
  #include "stdio.h"
  int agjdn(a,b,n,m)
  int n,m;
  double a[],b[];
  { int *js,l,k,i,j,is,p,q;
    double d,t;
    js=malloc(n*sizeof(int));
    l=1;
    for (k=0;k<=n-1;k++)
      { d=0.0;
        for (i=k;i<=n-1;i++)
          for (j=k;j<=n-1;j++)
            { t=fabs(a[i*n+j]);
              if (t>d) { d=t; js[k]=j; is=i;}
            }
        if (d+1.0==1.0) l=0;
        else
          { if (js[k]!=k)
              for (i=0;i<=n-1;i++)
                { p=i*n+k; q=i*n+js[k];
                  t=a[p]; a[p]=a[q]; a[q]=t;
                }
            if (is!=k)
              { for (j=k;j<=n-1;j++)
                  { p=k*n+j; q=is*n+j;
                    t=a[p]; a[p]=a[q]; a[q]=t;
                  }
                for (j=0;j<=m-1;j++)
                  { p=k*m+j; q=is*m+j;
                    t=b[p]; b[p]=b[q]; b[q]=t;
                  }
              }
          }
        if (l==0)
          { free(js); printf("fail\n");
            return(0);
          }
        d=a[k*n+k];
        for (j=k+1;j<=n-1;j++)
          { p=k*n+j; a[p]=a[p]/d;}
        for (j=0;j<=m-1;j++)
          { p=k*m+j; b[p]=b[p]/d;}
        for (j=k+1;j<=n-1;j++)
          for (i=0;i<=n-1;i++)
            { p=i*n+j;
              if (i!=k)
                a[p]=a[p]-a[i*n+k]*a[k*n+j];
            }
        for (j=0;j<=m-1;j++)
        for (i=0;i<=n-1;i++)
          { p=i*m+j;
            if (i!=k)
              b[p]=b[p]-a[i*n+k]*b[k*m+j];
          }
      }
    for (k=n-1;k>=0;k--)
      if (js[k]!=k)
        for (j=0;j<=m-1;j++)
          { p=k*m+j; q=js[k]*m+j;
            t=b[p]; b[p]=b[q]; b[q]=t;
          }
    free(js);
    return(1);
  }

