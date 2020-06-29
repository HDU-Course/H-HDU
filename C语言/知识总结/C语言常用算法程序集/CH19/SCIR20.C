
  #define POINT rtv62
  #include "rtv62.c"
  #include "sline.c"
  #include "scir2.c"
  #include "rmode.c"
  main()
  { rmode(0x62);
    scir2(170,320,140,100,0,60,4,0);
    scir2(170,320,140,100,60,120,4,0);
    scir2(170,320,140,100,120,180,4,0);
    scir2(170,320,140,100,180,240,4,0);
    scir2(170,320,140,100,240,300,4,0);
    scir2(170,320,140,100,300,360,4,0);
  }

