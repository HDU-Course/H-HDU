
  #include "dos.h"
  int tslct(num,row,col,color,m,item)
  int num,row,col,color,m,item;
  { union REGS r;
    int row1,row2,col2,key,d,item1;
    void ssbox();
    d=(num+1)*10; col2=col+(num+1)*8;
    r.h.ah=1; int86(22,&r,&r);
    while (((r.x.flags)&0x0040)==0)
      { r.h.ah=0; int86(22,&r,&r);
        r.h.ah=1; int86(22,&r,&r);
      }
    r.h.ah=0; int86(22,&r,&r);
    key=r.h.ah;
    while (key!=28)
      { item1=item;
        switch(key)
          { case 80: item=item+1;
                     if (item>m) item=1;
                     break;
            case 72: item=item-1;
                     if (item<1) item=m;
                     break;
          }
        if (item!=item1)
          { row1=row+(item1-1)*d;
            row2=row1+d;
            ssbox(row1,col,row2,col2,color,1,1);
            row1=row+(item-1)*d; row2=row1+d; 
            ssbox(row1,col,row2,col2,color,1,1);
          }
        r.h.ah=1; int86(22,&r,&r);
        while (((r.x.flags)&0x0040)==0)
          { r.h.ah=0; int86(22,&r,&r);
            r.h.ah=1; int86(22,&r,&r);
          }
        r.h.ah=0; int86(22,&r,&r);
        key=r.h.ah;
      }
    return(item);
  }

