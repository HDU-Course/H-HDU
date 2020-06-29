
  #include "stdio.h"
  #include "gtnr1.c"
  main()
  { int i,j;
    double t,h,y[3];
    y[0]=1.0; y[1]=0.0; y[2]=-1.0;
    t=0.0; h=0.001;
    printf("\n");
    printf("t=%6.3f\n",t);
    for (i=0; i<=2; i++)
      printf("y(%d)=%e  ",i,y[i]);
    printf("\n");
    for (i=0; i<=9; i++)
      { gtnr1(t,h,3,y);
        t=t+h;
        printf("t=%6.3f\n",t);
        for (j=0; j<=2; j++)
          printf("y(%d)=%e  ",j,y[j]);
        printf("\n");
      }
    printf("\n");
  }

  void gtnr1f(t,y,n,d)
  int n;
  double t,y[],d[];
  { t=t; n=n;
    d[0]=-21.0*y[0]+19.0*y[1]-20.0*y[2];
    d[1]=19.0*y[0]-21.0*y[1]+20.0*y[2];
    d[2]=40.0*y[0]-40.0*y[1]-40.0*y[2];
    return;
  }

