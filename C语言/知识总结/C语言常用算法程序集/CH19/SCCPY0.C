
  #define POINT rtv62
  #include "rmode.c"
  #include "rtv62.c"
  #include "sccpy.c"
  #include "ssbox.c"
  main()
  { rmode(0x62);
    ssbox(60,150,280,450,4,1,1);
    sccpy(170,300,50,50,60,150,1);
    sccpy(170,300,50,50,280,450,1);
  }

