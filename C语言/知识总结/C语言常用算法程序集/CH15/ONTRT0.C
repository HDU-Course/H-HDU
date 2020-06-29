
  #include "stdio.h"
  #include "ontrt.c"
  main()
  { int n;
    double x,y,u[5],v[5];
    x=1.0; y=1.0;
    ontrt(x,y,5,u,v);
    printf("\n");
    for (n=0; n<=4; n++)
        printf(" n=%3d    %13.7e +j %13.7e\n",
                                 n,u[n],v[n]);
    printf("\n");
  }

