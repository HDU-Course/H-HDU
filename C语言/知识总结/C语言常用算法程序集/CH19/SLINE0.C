
  #define POINT rtv62
  #include "rtv62.c"
  #include "rmode.c"
  #include "sline.c"
  main()
  { rmode(0x62);
    sline(0,0,0,319,4,1);
    sline(0,319,199,319,4,1);
    sline(199,319,199,0,4,1);
    sline(199,0,0,0,4,1);
    sline(199,319,0,0,4,1);
    sline(0,319,199,0,4,1);
  }

