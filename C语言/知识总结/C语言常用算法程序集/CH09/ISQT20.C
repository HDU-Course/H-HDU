
  #include "stdio.h"
  #include "isqt2.c"
  #include "achol.c"
  main()
  { int i;
    double a[4],v[3],dt[4];
    static double x[3][5]={ {1.1,1.0,1.2,1.1,0.9},
         {2.0,2.0,1.8,1.9,2.1},{3.2,3.2,3.0,2.9,2.9}};
    static double y[5]={10.1,10.2,10.0,10.1,10.0};
    isqt2(x,y,3,5,a,dt,v);
    printf("\n");
    for (i=0; i<=3; i++)
      printf("a(%2d)=%e\n",i,a[i]);
    printf("\n");
    printf("q=%e  s=%e  r=%e\n",dt[0],dt[1],dt[2]);
    printf("\n");
    for (i=0; i<=2; i++)
      printf("v(%2d)=%e\n",i,v[i]);
    printf("\n");
    printf("u=%e\n",dt[3]);
    printf("\n");
  }

