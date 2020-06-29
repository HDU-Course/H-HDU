 
  #include "dos.h"
  int rtv5b(row,col,color,xor)
  int row,col,color,xor;
  { unsigned int bm;
    int bp,i,j;
    long int ix;
    unsigned char far *ptr=
              (unsigned char far *)0xA0000000;
    static unsigned char x[8]={128,64,32,16,8,4,2,1};
    unsigned char t,a,b,c,d;
    if (col<0||col>799||row<0||row>599) return(0);
    bp=col%8; bm=128; bm>>=bp;
    ix=(long)row*100L+(long)(col/8);
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
    outportb(0x03CE,8); t=bm; outportb(0x03CF,t);
    outportb(0x03C4,2);  outportb(0x03C5,255);
    if (xor!=0)
      { t=*(ptr+ix); t=a^color; *(ptr+ix)=t;}
    else
      { t=*(ptr+ix); *(ptr+ix)=color;}
    outportb(0x03CE,8); outportb(0x03CF,255);
    outportb(0x03CE,5); outportb(0x03CF,0);
    return(color);
  }

