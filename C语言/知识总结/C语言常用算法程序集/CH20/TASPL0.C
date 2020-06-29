
  #define POINT rtv5f
  #include "rtv5f.c"
  #include "rmode.c"
  #include "taspl.c"
  #include "stdio.h"
  main()
  { static char p1[10]={'0','1','2','3','4',
                         '5','6','7','8','9'};
    static char p2[10]={'a','b','c','d','e',
                        'A','B','C','D','E'};
    int i,row,col,color;
    FILE *fp;
    if ((fp=fopen("asci","r+b"))==NULL)
      { printf("cannot open asci !\n");
        exit(0);
      }
    rmode(0x5f);
    row=80; col=100; color=1;
    for (i=0; i<=4; i++)
      { taspl(i,row,col,color,1,p1,10,fp);
        row=row+60; color=color+1;
        taspl(i,row,col,color,1,p2,10,fp);
        row=row+60; color=color+1;
      }
    fclose(fp);
  }

