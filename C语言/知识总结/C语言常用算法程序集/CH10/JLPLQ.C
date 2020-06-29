  
  #include "stdlib.h"
  int jlplq(a,b,c,m,n,x)
  int m,n;
  double a[],b[],c[],x[];
  { int i,mn,k,j,l,*js;
    double s,z,dd,y,*p,*d;
    extern int brinv();
    extern void brmul();
    js=malloc(m*sizeof(int));
    p=malloc(m*m*sizeof(double));
    d=malloc(m*(m+n)*sizeof(double));
    for (i=0; i<=m-1; i++) js[i]=n+i;
    mn=m+n; s=0.0;
    while (1==1)
      { for (i=0; i<=m-1; i++)
          for (j=0; j<=m-1; j++)
            p[i*m+j]=a[i*mn+js[j]];
        l=brinv(p,m);
        if (l==0)
          { x[n]=s; free(js); free(p);
            free(d); return(l);
          }
        brmul(p,a,m,m,mn,d);
        for (i=0; i<=mn-1; i++) x[i]=0.0;
        for (i=0; i<=m-1; i++)
          { s=0.0;
            for (j=0; j<=m-1; j++)
              s=s+p[i*m+j]*b[j];
            x[js[i]]=s;
          }
        k=-1; dd=1.0e-35;
        for (j=0; j<=mn-1; j++)
          { z=0.0;
            for (i=0; i<=m-1; i++)
              z=z+c[js[i]]*d[i*mn+j];
            z=z-c[j];
            if (z>dd) { dd=z; k=j;}
          }
        if (k==-1)
          { s=0.0;
            for (j=0; j<=n-1; j++)
              s=s+c[j]*x[j];
	    x[n]=s; free(js); free(p);
            free(d); return(1);
          }
        j=-1;
        dd=1.0e+20;
        for (i=0; i<=m-1; i++)
          if (d[i*mn+k]>=1.0e-20)
            { y=x[js[i]]/d[i*mn+k];
              if (y<dd) { dd=y; j=i;}
            }
        if (j==-1) 
          { x[n]=s; free(js); free(p);
            free(d); return(0);
          }
        js[j]=k;
      }
  }

