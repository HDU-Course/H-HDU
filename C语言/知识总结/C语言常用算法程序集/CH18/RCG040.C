
  #define POINT rcg04
  #include "stdio.h"
  #include "rmode.c"
  #include "rcg04.c"
  main()
  { int k,row,col,color;
    rmode(0x04);
    for (row=0; row<=500; row++)
      { color=0;
        for (col=0; col<=500; col++)
          { POINT(row,col,color,0);
            color=color+1;
          }
      }
    for (row=0; row<=100; row++)
    for (col=0; col<=160; col++)
      { k=POINT(row,col,-1,0);
        POINT(row+101,col+161,k,1);
        POINT(row+101,col,k,1);
        POINT(row,col+161,k,0);
      }
   }

