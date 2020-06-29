
  #define POINT rtv62
  #include "rtv62.c"
  #include "rmode.c"
  #include "spara.c"
  #include "scopy.c"  
  main()
  { int i,color;
    rmode(0x62);
    color=1;
    for (i=0; i<=11; i++)
      { spara(170,320,100,100,i*30,color,1);
        color=color+1;
      }
    scopy(50,150,300,450,0,0,0);
    scopy(0,0,200,300,150,300,0);
  }

