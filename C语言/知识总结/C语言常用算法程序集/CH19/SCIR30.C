
  #define POINT rtv62
  #include "rtv62.c"
  #include "scir3.c"
  #include "rmode.c"
  main()
  { rmode(0x62);
    scir3(170,320,140,100,4,1);
  }

