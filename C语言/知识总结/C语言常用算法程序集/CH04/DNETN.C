
  #include "stdlib.h"
  #include "math.h"
  #include "stdio.h"
  int dnetn(n,eps,t,h,x,k)
  int n,k;
  double eps,t,h,x[];
  { extern void dnetnf();
    extern int agaus();
    int i,j,l;
    double am,z,beta,d,*y,*a,*b;
    y=malloc(n*sizeof(double));
    a=malloc(n*n*sizeof(double));
    b=malloc(n*sizeof(double));
    l=k; am=1.0+eps;
    while (am>=eps)
      { dnetnf(x,b,n);
        am=0.0;
        for (i=0; i<=n-1; i++)
          { z=fabs(b[i]);
            if (z>am) am=z;
          }
        if (am>=eps)
          { l=l-1;
            if (l==0)
              { free(y); free(b); free(a);
                printf("fail\n"); return(0);
              }
            for (j=0; j<=n-1; j++)
              { z=x[j]; x[j]=x[j]+h;
                dnetnf(x,y,n);
                for (i=0; i<=n-1; i++) a[i*n+j]=y[i];
                x[j]=z;
              }
            if (agaus(a,b,n)==0)
              { free(y); free(a); free(b); return(-1);}
            beta=1.0;
            for (i=0; i<=n-1; i++) beta=beta-b[i];
            if (fabs(beta)+1.0==1.0)
              { free(y); free(a); free(b);
                printf("fail\n"); return(-2);
              }
            d=h/beta;
            for (i=0; i<=n-1; i++) x[i]=x[i]-d*b[i];
            h=t*h;
          }
      }
    free(y); free(a); free(b);
    return(k-l);
  }

