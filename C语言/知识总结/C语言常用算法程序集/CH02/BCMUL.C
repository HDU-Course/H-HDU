
  void bcmul(ar,ai,br,bi,m,n,k,cr,ci)
  int m,n,k;
  double ar[],ai[],br[],bi[],cr[],ci[];
  { int i,j,l,u,v,w;
    double p,q,s;
    for (i=0; i<=m-1; i++)
    for (j=0; j<=k-1; j++)
      { u=i*k+j;
        cr[u]=0.0; ci[u]=0.0;
        for (l=0; l<=n-1; l++)
          { v=i*n+l; w=l*k+j;
            p=ar[v]*br[w];
            q=ai[v]*bi[w];
            s=(ar[v]+ai[v])*(br[w]+bi[w]);
            cr[u]=cr[u]+p-q;
            ci[u]=ci[u]+s-p-q;
          }
      }
    return;
  }

