
  #include "stdio.h"
  #include "chhqr.c"
  #include "dqrrt.c"
  main()
  { int i,jt,n;
    static double xr[6],xi[6];
    static double a[7]={-30.0,10.5,-10.5,1.5,4.5,-7.5,1.5};
    double eps;
    eps=0.000001; jt=60; n=6;
    i=dqrrt(a,n,xr,xi,eps,jt);
    printf("\n");
    if (i>0)
      { for (i=0; i<=5; i++)
          printf("x(%d)=%13.7e  %13.7e j\n",i,xr[i],xi[i]);
        printf("\n");
      }
  }

