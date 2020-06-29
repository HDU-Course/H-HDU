
  #include "math.h"
  #include "stdio.h"
  #include "dcmtc.c"
  #include "mrnd1.c"
  main()
  { int m;
    double x,y,b,eps;
    x=0.5; y=0.5; b=1.0; m=10; eps=0.00001;
    dcmtc(&x,&y,b,m,eps);
    printf("\n");
    printf("z=%e +j %e\n",x,y);
    printf("\n");
  }

  double dcmtcf(x,y)
  double x,y;
  { double u,v,z;
    u=x*x-y*y+x-y-2.0;
    v=2.0*x*y+x+y+2.0;
    z=sqrt(u*u+v*v);
    return(z);
  }

