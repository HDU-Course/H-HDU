
  int rcg04(row,col,color,xor)
  int row,col,color,xor;
  { union mask {unsigned char c[2]; int i;} bm;
    int i,bp;
    long int ix;
    unsigned char t,a;
    unsigned char far *ptr=
            (unsigned char far *)0xB8000000;
    if (col<0||col>319||row<0||row>199)  return(0);
    bp=col%4; 
    ix=(long)(row/2)*80L+
       (long)(row%2)*8192L+(long)(col/4);
    if (color>=0)
      { bm.i=0xFF3F;
        color=color%4; color<<=2*(3-bp);
        t=*(ptr+ix)|(unsigned char)0;
        if (xor==0)
          { bm.i>>=2*bp; a=t&bm.c[0]; a=a|color;}
        else a=t^color;
        *(ptr+ix)=a;
        return(color);
      }
    else
      { bm.i=3; bm.i<<=2*(3-bp);
        t=*(ptr+ix)&bm.c[0]; t>>=2*(3-bp);
        bp=(int)t;
        return(bp);
      }
  }

