
  #include "stdio.h"
  #include "gtnr2.c"
  main()
  { int i,j;
    double t,h,y[3],z[3][101];
    y[0]=1.0; y[1]=0.0; y[2]=-1.0;
    t=0.0; h=0.001;
    gtnr2(t,h,3,y,101,z);
    printf("\n");
    for (i=0; i<=100; i=i+10)
      { t=i*h;
        printf("t=%6.3f\n",t);
        for (j=0; j<=2; j++)
          printf("y(%d)=%e  ",j,z[j][i]);
        printf("\n");
      }
    printf("\n");
  } 

  void gtnr2f(t,y,n,d)
  int n;
  double t,y[],d[];
  { t=t; n=n;
    d[0]=-21.0*y[0]+19.0*y[1]-20.0*y[2];
    d[1]=19.0*y[0]-21.0*y[1]+20.0*y[2];
    d[2]=40.0*y[0]-40.0*y[1]-40.0*y[2];
    return;
  }

