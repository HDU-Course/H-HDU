
  #include "stdio.h"
  #include "ggil1.c"
  main()
  { int i,j;
    double t,h,eps;
    static double q[3]={0.0,0.0,0.0};
    static double y[3]={0.0,1.0,1.0};
    t=0.0; h=0.1; eps=0.000001;
    printf("\n");
    printf("t=%7.3f\n",t);
    for (i=0; i<=2; i++)
      printf("y(%d)=%e  ",i,y[i]);
    printf("\n");
    for (j=1; j<=10; j++)
      { ggil1(t,h,y,3,eps,q);
        t=j*h;
        printf("t=%7.3f\n",t);
        for (i=0; i<=2; i++)
          printf("y(%d)=%e  ",i,y[i]);
        printf("\n");
      }
  }

  void ggil1f(t,y,n,d)
  int n;
  double t,y[],d[];
  { t=t; n=n;
    d[0]=y[1]; d[1]=-y[0]; d[2]=-y[2];
    return;
  }

