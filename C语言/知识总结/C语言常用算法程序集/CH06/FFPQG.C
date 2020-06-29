
  #include "math.h"
  double ffpqg(a,b,eps)
  double a,b,eps;
  { extern double ffpqgf();
    int m,n,k,l,j;
    double h[10],bb[10],hh,t1,s1,ep,s,x,t2,g;
    m=1; n=1;
    hh=b-a; h[0]=hh;
    t1=hh*(ffpqgf(a)+ffpqgf(b))/2.0;
    s1=t1; bb[0]=s1; ep=1.0+eps;
    while ((ep>=eps)&&(m<=9))
      { s=0.0;
        for (k=0;k<=n-1;k++)
          { x=a+(k+0.5)*hh;
            s=s+ffpqgf(x);
          }
        t2=(t1+hh*s)/2.0;
        m=m+1;
        h[m-1]=h[m-2]/2.0;
        g=t2;
        l=0; j=2;
        while ((l==0)&&(j<=m))
          { s=g-bb[j-2];
            if (fabs(s)+1.0==1.0) l=1;
            else g=(h[m-1]-h[j-2])/s;
            j=j+1;
          }
        bb[m-1]=g;
        if (l!=0) bb[m-1]=1.0e+35;
        g=bb[m-1];
        for (j=m;j>=2;j--)
           g=bb[j-2]-h[j-2]/g;
        ep=fabs(g-s1);
        s1=g; t1=t2; hh=hh/2.0; n=n+n;
      }
    return(g);
  }

