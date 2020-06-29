
  #include "stdio.h"
  #include "math.h"
  #include "eslq3.c"
  main()
  { int i,j;
    double u,v,w;
    static double x[6],y[5],z[6][5];
    for (i=0;i<=5;i++) x[i]=0.2*i;
    for (j=0;j<=4;j++) y[j]=0.25*j;
    for (i=0;i<=5;i++)
      for (j=0;j<=4;j++)
        z[i][j]=exp(-(x[i]-y[j]));
    printf("\n");
    u=0.9; v=0.8;
    w=eslq3(x,y,z,6,5,u,v);
    printf("x=%7.3f,   y=%7.3f,    z(x,y)=%e\n",u,v,w);
    u=0.3; v=0.9;
    w=eslq3(x,y,z,6,5,u,v);
    printf("x=%7.3f,   y=%7.3f,    z(x,y)=%e\n",u,v,w);
    printf("\n");
  }

