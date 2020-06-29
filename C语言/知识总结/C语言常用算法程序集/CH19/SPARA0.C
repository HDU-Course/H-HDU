
  #define POINT rtv62
  #include "rtv62.c"
  #include "rmode.c"
  #include "spara.c"
  main()
  { int i,color;
    rmode(0x62);
    color=1;
    for (i=0; i<=11; i++)
      { spara(170,320,100,100,i*30,color,1);
        color=color+1;
      }
  }

