
  #include "stdio.h"
  #include "ghamg.c"
  main()
  { int i,j;
    double t,h,eps,y[3],z[3][11];
    y[0]=1.0; y[1]=1.0; y[2]=1.0;
    t=0.0; h=0.05; eps=0.0001;
    ghamg(t,h,3,y,eps,11,z);
    printf("\n");
    for (i=0; i<=10; i++)
      { t=i*h;
        printf("t=%7.3f\n",t);
        for (j=0; j<=2; j++)
          printf("y(%d)=%e  ",j,z[j][i]);
        printf("\n");
      }
    printf("\n");
  }

  void ghamgf(t,y,n,d)
  int n;
  double t,y[],d[];
  { t=t; n=n;
    d[0]=y[1]; d[1]=-y[0]; d[2]=y[2];
    return;
  }

