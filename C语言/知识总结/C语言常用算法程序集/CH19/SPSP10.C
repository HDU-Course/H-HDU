
  #define POINT rtv62
  #include "rtv62.c"
  #include "sline.c"
  #include "spsp1.c"
  #include "rmode.c"
  main()
  { rmode(0x62);
    spsp1(100,150,-70,70,-100,100,850,
           650,300,5,5,2,1);
  }

  double persp1f(x,y)
  double x,y;
  { double z,a,b;
    a=10.0; b=15.0;
    z=(-x*x/(a*a))+(y*y)/(b*b);
    return(z);
  }

