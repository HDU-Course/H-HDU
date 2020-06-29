
  #define POINT rtv62
  #include "rtv62.c"
  #include "sline.c"
  #include "rmode.c"
  #include "sfunc.c"
  main()
  { int i;
    rmode(0x62);
    for (i=0; i<=3; i++)
      sfunc(170,320,0,200,i*90,i+1,1);
  }

  #include "math.h"
  double fun(x)
  double x;
  { double y;
    y=50.0*sin(0.125*x);
    return(y);
  }

