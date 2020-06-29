
  #define POINT rtv62
  #include "rtv62.c"
  #include "rmode.c"
  #include "scubc.c"
  main()
  { int i;
    double b,c,d;
    rmode(0x62);
    d=0.001; c=-0.1; b=0.5;
    for (i=0; i<=3; i++)
      scubc(170,320,b,c,d,100,i*90,i+1,1);
  }

