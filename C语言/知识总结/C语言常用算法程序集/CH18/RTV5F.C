
  #include "dos.h"
  int rtv5f(row,col,color,xor)
  int row,col,color,xor;
  { int bp,i,j,k;
    long int ix,k46=65536L;
    unsigned char far *ptr;
    static unsigned char x[8]={128,64,32,16,8,4,2,1};
    unsigned char t,a,b,c,d;
    if (col<0||col>1023||row<0||row>767) return(0);
    ptr=(unsigned char far *)0xA0000000;
    bp=col%8; 
    ix=(long)row*128L+(long)(col/8);
    k=ix/k46; ix=ix-(long)k*k46;
    a=k;
    outportb(0x03C4,0x0E);
    outportb(0x03C5,a^0x02);
    t=x[bp];
    if (color<0) xor=1;
    if (xor!=0)
      { outportb(0x03CE,5); outportb(0x03CF,0);
        outportb(0x03CE,4); outportb(0x03CF,0);
        a=*(ptr+ix)&t;
        if (a!=0) a=1;
        outportb(0x03CE,4); outportb(0x03CF,1);
        b=*(ptr+ix)&t;
        if (b!=0) b=2;
        outportb(0x03CE,4); outportb(0x03CF,2);
        c=*(ptr+ix)&t;
        if (c!=0) c=4;
        outportb(0x03CE,4); outportb(0x03CF,3);
        d=*(ptr+ix)&t;
        if (d!=0) d=8;
        a=a|b|c|d;
      }
    if (color<0)
      { color=(int)a; return(color);}
    outportb(0x03CE,5); outportb(0x03CF,2);
    color=color%127;
    outportb(0x03CE,8); outportb(0x03CF,t);
    outportb(0x03C4,2); outportb(0x03C5,255);
    if (xor!=0)
      { t=*(ptr+ix); t=a^color; *(ptr+ix)=t;}
    else
      { t=*(ptr+ix); *(ptr+ix)=color;}
    outportb(0x03CE,8); outportb(0x03CF,255);
    outportb(0x03CE,5); outportb(0x03CF,0);
    return(color);
  }

