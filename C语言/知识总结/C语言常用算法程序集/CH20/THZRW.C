
  void thzrw(num,row,col,color,xor,q,n,fp)
  FILE *fp;
  int num,row,col,color,xor,n,q[];
  { int y,code,j,k;
    extern void thzpl();
    k=1; j=0; y=col;
    while ((j<n)&&(k>=0))
      { code=q[j]; k=-1;
        if (code>=0)
          { thzpl(num,row,y,code,color,xor,fp);
            y=y+(num+1)*8; j=j+1; k=1;
          }
      }
    return;
  }

