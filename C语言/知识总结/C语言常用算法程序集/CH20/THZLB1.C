
  #define POINT rtv5f
  #include "stdio.h"
  #include "rtv5f.c"
  #include "thzlb.c"
  #include "thzpl.c"
  #include "rmode.c"
  main()
  { FILE *fp;
    int i,row,col;
    thzlb(2,4,1,"cclib24","cclibb","code.txt");
    if ((fp=fopen("cclibb","r+b"))==NULL)
      { printf("cannot open cclib !\n");
        exit(0);
      }
    row=0;
    rmode(0x5f);
    for (i=0; i<=41; i++)
      { if ((i%5)==0)
          { row=row+50; col=80;}
	thzpl(5,row,col,i,4,1,fp);
        col=col+40;
      }
    fclose(fp);
  }


