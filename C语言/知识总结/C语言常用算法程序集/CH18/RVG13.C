 
  #include "dos.h"
  int rvg13(row,col,color,xor)
  int row,col,color,xor;
  { long int ix;
    unsigned char far *ptr=
             (unsigned char far *)0xA0000000;
    unsigned char t,a;
    if (col<0||col>319||row<0||row>199) return(0);
    ix=(long)row*320L+(long)col;
    t=*(ptr+ix);
    if (color<0) { color=(int)t; return(color);}
    if (xor!=0)
      { a=color; t=t^a; *(ptr+ix)=t;}
    else *(ptr+ix)=color;
    return(color);
  }

