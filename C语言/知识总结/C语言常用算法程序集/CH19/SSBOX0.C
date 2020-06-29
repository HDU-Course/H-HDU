
  #define POINT rtv62
  #include "rtv62.c"
  #include "rmode.c"
  #include "ssbox.c"
  main()
  { rmode(0x62);
    ssbox(30,50,80,90,2,0,1);
    ssbox(100,100,200,150,4,1,1);
  }

