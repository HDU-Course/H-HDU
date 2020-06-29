
  #define POINT rtv62
  #include "rtv62.c"
  #include "sline.c"
  #include "spsp2.c"
  #include "rmode.c"
  main()
  { rmode(0x62);
    spsp2(100,150,-70,70,-100,100,-10,
           -8,-4,5,5,2,1);
  }

  double persp2f(x,y)
  double x,y;
  { double z,a,b;
    a=10.0; b=15.0;
    z=(-x*x/(a*a))+(y*y)/(b*b);
    return(z);
  }

