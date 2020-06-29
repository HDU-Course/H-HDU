
  void smull(row,col,g,n,color,xor)
  int g[],n,row,col,color;
  { int i,j,row1,col1,row2,col2;
    extern void sline();
    j=0;
    for (i=0; i<=n-1; i++)
      { row1=g[j]+row;     col1=g[j+1]+col;
        row2=g[j+2]+row;   col2=g[j+3]+col;
        j=j+4;
        sline(row1,col1,row2,col2,color,xor);
      }
    return;
  }

