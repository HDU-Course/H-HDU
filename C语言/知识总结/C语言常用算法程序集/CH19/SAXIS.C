
  void saxis(row,col,k,w,n,l,color,xor)
  int row,col,k,w,n,l,color,xor;
  { int x1,y1,x2,y2;
    int i,x,y;
    extern void sline();
    if (k==0) return;
    x=row; y=col;
    if (k>0)
      { if (l==0)
          { x1=row-2; x2=row+2;}
        if (l>0)
          { x1=row-2; x2=row;}
        if (l<0)
          { x1=row; x2=row+2;}
        for (i=0; i<=n-1; i++)
          { sline(x1,y,x2,y,color,xor);
            sline(x,y+1,x,y+w-1,color,xor);
            y=y+w;
          }
      }
    else
      { if (l==0)
          { y1=col-2; y2=col+2;}
        if (l>0)
          { y1=col; y2=col+2;}
        if (l<0)
          { y1=col-2; y2=col;}
        for (i=0; i<=n-1; i++)
          { sline(x,y1,x,y2,color,xor);
            sline(x+1,y,x+w-1,y,color,xor);
            x=x+w;
          }
      }
    return;
  }

