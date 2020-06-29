
  #define POINT rtv62
  #include "rtv62.c"
  #include "sline.c"
  #include "sful1.c"
  #include "rmode.c"
  main()
  { rmode(0x62);
    sful1(170,320,140,100,60,120,4);
    sful1(170,320,140,100,180,240,4);
    sful1(170,320,140,100,300,360,4);
  }

