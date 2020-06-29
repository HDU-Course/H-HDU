
  #include "math.h"
  #include "stdio.h"
  int aldle(a,n,m,c)
  int n,m;
  double a[],c[];
  { int i,j,l,k,u,v,w,k1,k2,k3;
    double p;
    if (fabs(a[0])+1.0==1.0)
      { printf("fail\n"); return(-2);}
    for (i=1; i<=n-1; i++)
      { u=i*n; a[u]=a[u]/a[0];}
    for (i=1; i<=n-2; i++)
      { u=i*n+i;
        for (j=1; j<=i; j++)
          { v=i*n+j-1; l=(j-1)*n+j-1;
            a[u]=a[u]-a[v]*a[v]*a[l];
          }
        p=a[u];
        if (fabs(p)+1.0==1.0)
          { printf("fail\n"); return(-2);}
        for (k=i+1; k<=n-1; k++)
          { u=k*n+i;
            for (j=1; j<=i; j++)
              { v=k*n+j-1; l=i*n+j-1; w=(j-1)*n+j-1;
		a[u]=a[u]-a[v]*a[l]*a[w];
              }
            a[u]=a[u]/p;
          }
      }
    u=n*n-1;
    for (j=1; j<=n-1; j++)
      { v=(n-1)*n+j-1; w=(j-1)*n+j-1;
        a[u]=a[u]-a[v]*a[v]*a[w];
      }
    p=a[u];
    if (fabs(p)+1.0==1.0)
      { printf("fail\n"); return(-2);}
    for (j=0; j<=m-1; j++)
    for (i=1; i<=n-1; i++)
      { u=i*m+j;
        for (k=1; k<=i; k++)
          { v=i*n+k-1; w=(k-1)*m+j;
            c[u]=c[u]-a[v]*c[w];
          }
      }
    for (i=1; i<=n-1; i++)
      { u=(i-1)*n+i-1;
        for (j=i; j<=n-1; j++)
          { v=(i-1)*n+j; w=j*n+i-1;
            a[v]=a[u]*a[w];
          }
      }
    for (j=0; j<=m-1; j++)
      { u=(n-1)*m+j;
        c[u]=c[u]/p;
        for (k=1; k<=n-1; k++)
          { k1=n-k; k3=k1-1; u=k3*m+j;
            for (k2=k1; k2<=n-1; k2++)
              { v=k3*n+k2; w=k2*m+j;
                c[u]=c[u]-a[v]*c[w];
              }
            c[u]=c[u]/a[k3*n+k3];
          }
      }
    return(2);
  }

