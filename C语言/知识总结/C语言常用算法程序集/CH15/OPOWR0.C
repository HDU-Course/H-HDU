
  #include "stdio.h"
  #include "opowr.c"
  main()
  { int n;
    double x,y,u,v;
    x=2.0; y=2.0;
    printf("\n");
    for (n=-3; n<=3; n=n+3)
      { opowr(x,y,n,&u,&v);
        printf(" n=%3d    %13.7e +j %13.7e\n",n,u,v);
      }
    printf("\n");
  }

