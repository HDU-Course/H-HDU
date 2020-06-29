
  #include "dos.h"
  #include "stdlib.h"
  #include "stdio.h"
  void taspl(num,row,col,color,xor,q,n,fp)
  FILE *fp;
  int num,row,col,color,xor,n;
  char q[];
  { int y,code,j;
    void chapl();
    j=0; y=col;
    while (j<n)
      { code=q[j];
        chapl(num,row,y,code,color,xor,fp);
        y=y+8*(num+1); j=j+1;
      }
    return;
  }

  static void chapl(num,row,col,code,color,xor,fp)
  int num,row,col,code,color,xor;
  FILE *fp;
  { int x,i,j,k,m;
    unsigned char t,*p;
    void pq8();
    k=16;
    p=malloc(k*sizeof(unsigned char));
    fseek(fp,k*code*sizeof(unsigned char),SEEK_SET);
    fread(p,sizeof(unsigned char),k,fp);
    x=row; m=0;
    for (i=0; i<k; i++)
      { t=p[m]; m=m+1;
        for (j=0; j<=num; j++)
          { pq8(num,x,col,t,color,xor);
            x=x+1;
          }
      }
    free(p); return;
  }

  static void pq8(num,row,col,t,color,xor)
  int num,row,col,color,xor;
  unsigned char t;
  { unsigned char p[8]={128,64,32,16,8,4,2,1};
    unsigned char q;
    int i,j,k;
    for (i=0; i<=7; i++)
      { q=p[i]&t; j=col+i*(num+1);
        for (k=0; k<=num; k++)
          { if (q==0) POINT(row,j,0,xor);
            else POINT(row,j,color,xor);
            j=j+1;
          }
      }
  }

