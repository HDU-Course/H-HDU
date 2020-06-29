
  #define POINT rtv62
  #include "rtv62.c"
  #include "scir1.c"
  #include "rmode.c"
  main()
  { rmode(0x62);
    scir1(170,320,140,100,0,90,4,0);
    scir1(170,320,140,100,90,180,4,0);
    scir1(170,320,140,100,180,270,4,0);
    scir1(170,320,140,100,270,360,4,0);
  }

