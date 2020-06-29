
  #define POINT rtv5f
  #include "rtv5f.c"
  #include "rmode.c"
  #include "thzpl.c"
  #include "thzrw.c"
  #include "stdio.h"
  main()
  { static int p1[10]={0,1,2,3,4,5,6,7,8,9};
    static int p2[10]={10,11,12,13,14,15,16,-1};
    int i,row,col,color;
    FILE *fp1,*fp2;
    if ((fp1=fopen("cclib","r+b"))==NULL)
      { printf("cannot open cclib !\n");
        exit(0);
      }
    if ((fp2=fopen("cclibb","r+b"))==NULL)
      { printf("cannot open cclibb !\n");
        exit(0);
      }
    rmode(0x5f);
    row=80; col=100; color=1;
    for (i=0; i<=4; i++)
      { thzrw(3,row,col,color,1,p1,10,fp1);
        row=row+60; color=color+1;
        thzrw(5,row,col,color,1,p2,10,fp2);
        row=row+60; color=color+1;
      }
  }

