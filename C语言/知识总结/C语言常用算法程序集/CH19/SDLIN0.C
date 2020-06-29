
  #define POINT rtv62
  #include "rtv62.c"
  #include "sline.c"
  #include "smull.c"
  #include "sdlin.c"
  #include "rmode.c"
  main()
  { int i,j,k;
    static int g[4][4]={ {0,0,0,10},{0,10,10,10},
                       {10,10,10,0},{10,0,0,0}};
    rmode(0x62);
    smull(0,0,g,4,4,1);
    for (i=0; i<=300; i=i+10)
      { smull(i,i,g,4,4,1);
        for (j=0; j<=30; j++)
        for (k=0; k<=10000; k++);
        smull(i+10,i+10,g,4,4,1);
        for (j=0; j<=30; j++)
        for (k=0; k<=10000; k++);
      }
    sdlin(0,0,0,639,15,4,4,0);
    sdlin(0,639,349,639,15,4,4,0);
    sdlin(349,639,349,0,15,4,4,0);
    sdlin(349,0,0,0,15,4,4,0);
    sdlin(0,0,349,639,15,4,4,0);
    sdlin(0,639,349,0,15,4,4,0);
  }

