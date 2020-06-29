
  #include "stdio.h"
  #include "ggil2.c"
  main()
  { int i,j;
    double a,h,eps,t,z[3][11];
    static double y[3]={0.0,1.0,1.0};
    a=0.0; h=0.1; eps=0.000001;
    ggil2(a,h,y,3,eps,11,z);
    printf("\n");
    for (i=0; i<=10; i++)
      { t=i*h;
        printf("t=%7.3f\n",t);
        for (j=0; j<=2; j++)
          printf("y(%d)=%e  ",j,z[j][i]);
        printf("\n");
      }
  }

  void ggil2f(t,y,n,d)
  int n;
  double t,y[],d[];
  { t=t; n=n;
    d[0]=y[1]; d[1]=-y[0]; d[2]=-y[2];
    return;
  }

