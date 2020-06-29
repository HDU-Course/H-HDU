
  #define POINT rtv62
  #include "rtv62.c"
  #include "sline.c"
  #include "sful2.c"
  #include "rmode.c"
  main()
  { rmode(0x62);
    sful2(170,320,140,100,4,1);
  }

