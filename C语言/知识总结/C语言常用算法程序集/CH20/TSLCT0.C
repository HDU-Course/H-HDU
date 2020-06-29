
  #define POINT rtv5f
  #include "dos.h"
  #include "stdio.h"
  #include "rmode.c"
  #include "rtv5f.c"
  #include "thzpl.c"
  #include "thzrw.c"
  #include "tmenu.c"
  #include "ssbox.c"
  #include "tslct.c"
  main()
  { int item,flag,color=4;
    FILE *fp;
    static int a[6][10]=
        { {20,0,1,2,3,4,5,-1},
          {21,6,7,8,9,-1},
          {22,10,11,12,13,-1},
          {23,14,15,16,-1},
          {24,17,18,-1},
          {25,19,-1}
        };
    if ((fp=fopen("cclib","r+b"))==NULL)
      { printf("cannot open cclib !\n");
        exit(0);
      }
    rmode(0x5f);
    item=1; flag=1;
    item=tmenu(3,100,100,color,1,a,6,10,item,fp);
    while (flag==1)
      { item=tslct(3,100,100,color,6,item);
        switch(item)
          { case 1:  break;
            case 2:  break;
            case 3:  break;
            case 4:  break;
            case 5:  break;
            case 6: flag=0; break;
          }
        item=tmenu(3,100,100,color,1,a,6,10,item,fp);
      }
    rmode(3);
    fclose(fp);
  }

 