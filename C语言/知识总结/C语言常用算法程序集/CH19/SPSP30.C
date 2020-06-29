
  #define POINT rtv62
  #include "rtv62.c"
  #include "sline.c"
  #include "spsp3.c"
  #include "rmode.c"
  main()
  { rmode(0x62);
    spsp3(100,150,5,5,70,-10,
             -8,-4,5,5,2,1);
  }

  #include "math.h"
  double persp3f(x,y)
  double x,y;
  { double z;
    z=sqrt(72.0*72.0-(x-5.0)*(x-5.0)
           -(y-5.0)*(y-5.0));
    return(z);
  }

