
  int tmenu(num,row,col,color,xor,q,m,n,item,fp)
  FILE *fp;
  int num,row,col,color,q[],m,n,xor,item;
  { int c[100],i,j,x,y,d,x1,y1;
    void thzrw();
    void ssbox();
    if ((item<0)||(item>m)) item=1;
    d=(num+1)*10;
    x=col; y=row;
    for (j=0; j<=m-1; j++)
      { for (i=0; i<=n-1; i++)
          c[i]=q[j*n+i];
        thzrw(num,y,x,color,xor,c,n,fp);
        y=y+d;
      }
    y=row+(item-1)*d; x=col;
    y1=y+d; x1=col+(num+1)*8;
    ssbox(y,x,y1,x1,color,1,1);
    return(item);
  }

