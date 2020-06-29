
  #define POINT rtv62
  #include "stdio.h"
  #include "rmode.c"
  #include "rtv62.c"
  main()
  { int k,row,col,color;
    rmode(0x62);
    for (row=0; row<=500; row++)
      { color=0;
        for (col=0; col<=500; col++)
          { POINT(row,col,color,0);
            color=color+1;
          }
      }
    for (row=0; row<=250; row++)
    for (col=0; col<=250; col++)
      { k=POINT(row,col,-1,0);
        POINT(row+251,col+251,k,1);
        POINT(row+251,col,k,1);
        POINT(row,col+251,k,0);
      }
   }

