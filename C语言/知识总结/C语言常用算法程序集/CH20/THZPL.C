
  #include "dos.h"
  #include "stdlib.h"
  #include "stdio.h"
  void thzpl(num,row,col,code,color,xor,fp)
  int num,row,col,code,color,xor;
  FILE *fp;
  { int x,y,i,j,k,kk,m;
    unsigned char t,*p;
    void p8();
    k=(num+1)*(num+1)*8;
    p=malloc(k*sizeof(unsigned char));
    fseek(fp,k*code*sizeof(unsigned char),SEEK_SET);
    fread(p,sizeof(unsigned char),k,fp);
    x=row; m=0; kk=(num+1)*8;
    for (i=0; i<kk; i++)
      { y=col;
        for (j=0; j<=num; j++)
          { t=p[m]; m=m+1;
            p8(x,y,t,color,xor);
            y=y+8;
          }
        x=x+1;
      }
    free(p); return;
  }

  static void p8(row,col,t,color,xor)
  int row,col,color,xor;
  unsigned char t;
  { unsigned char p[8]={128,64,32,16,8,4,2,1};
    unsigned char q;
    int i,j;
    for (i=0; i<=7; i++)
      { q=p[i]&t; j=col+i;
        if (q==0) POINT(row,j,0,xor);
        else POINT(row,j,color,xor);
      }
  }

