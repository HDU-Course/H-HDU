
  #include "dos.h"
  int rtv5d(row,col,color,xor)
  int row,col,color,xor;
  { long int ix,kk,k64=65536L;
    unsigned char far *ptr=
             (unsigned char far *)0xA0000000;
    unsigned char t,a;
    int k;
    if (col<0||col>639||row<0||row>479) return(0);
    ix=(long)row*640L+(long)col;
    kk=ix/k64; ix=ix-kk*k64; 
    k=kk; a=k;
    outportb(0x03C4,0x0E);
    outportb(0x03C5,a^0x02);
    t=*(ptr+ix);
    if (color<0) { color=(int)t; return(color);}
    if (xor!=0)
      { a=color; t=t^a; }
    else t=color;
    *(ptr+ix)=t;
    return(color);
  }

