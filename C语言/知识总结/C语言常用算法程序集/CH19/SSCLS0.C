
  #define POINT rtv62
  #include "rtv62.c"
  #include "rmode.c"
  #include "spara.c"
  #include "sscls.c"
  main()
  { int i,color;
    rmode(0x62);
    color=1;
    for (i=0; i<=11; i++)
      { spara(170,320,100,100,i*30,color,1);
        color=color+1;
      }
    for (i=0; i<=10000; i++)
    for (color=0; color<=100; color++);
    sscls(70,220,270,420);
  }

