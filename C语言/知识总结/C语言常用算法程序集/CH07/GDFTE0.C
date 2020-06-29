
  #include "stdio.h"
  #include "gdfte.c"
  #include "atrde.c"
  main()
  { int i;
    double a,b,ya,yb,y[11];
    a=2.0; b=3.0; ya=0.0; yb=0.0;
    gdfte(a,b,ya,yb,11,y);
    printf("\n");
    for (i=0; i<=10; i++)
      printf("y(%2d)=%e\n",i,y[i]);
    printf("\n");
  }

  void gdftef(x,z)
  double x,z[4];
  { z[0]=-1.0; z[1]=0.0;
    z[2]=2.0/(x*x); z[3]=1.0/x;
    return;
  }

