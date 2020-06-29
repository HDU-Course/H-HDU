
  #include "math.h"
  #include "stdio.h"
  #include "eslgq.c"
  main()
  { int i,j;
    double u,v,w;
    static double x[11],y[11],z[11][11];
    for (i=0;i<=10;i++)
      { x[i]=0.1*i; y[i]=x[i];}
    for (i=0;i<=10;i++)
      for (j=0;j<=10;j++)
        z[i][j]=exp(-(x[i]-y[j]));
    printf("\n");
    u=0.35; v=0.65;
    w=eslgq(x,y,z,11,11,u,v);
    printf("x=%7.3f,  y=%7.3f,    z(x,y)=%e\n",u,v,w);
    u=0.45; v=0.55;
    w=eslgq(x,y,z,11,11,u,v);
    printf("x=%7.3f,  y=%7.3f,    z(x,y)=%e\n",u,v,w);
    printf("\n");
  }

