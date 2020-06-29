
  #define POINT rtv62
  #include "rtv62.c"
  #include "sline.c"
  #include "saxis.c"
  #include "rmode.c"
  main()
  { rmode(0x62);
    saxis(10,10,1,15,20,0,4,1);
    saxis(30,10,1,15,20,1,4,0);
    saxis(50,10,1,15,20,-1,4,1);
    saxis(60,50,-1,15,15,0,2,1);
    saxis(60,100,-1,15,15,1,2,0);
    saxis(60,150,-1,15,15,-1,2,1);
  }

