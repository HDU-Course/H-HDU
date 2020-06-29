
  void ssbox(row1,col1,row2,col2,color,k,xor)
  int row1,col1,row2,col2,color,k,xor;
  { int i,j;
    extern int POINT();
    for (i=row1; i<=row2; i++)
      POINT(i,col1,color,xor);
    for (i=col1+1; i<=col2-1; i++)
      POINT(row2,i,color,xor);
    for (i=row2; i>=row1; i--)
      POINT(i,col2,color,xor);
    for (i=col2-1; i>=col1+1; i--)
      POINT(row1,i,color,xor);
    if (k==0) return;
    for (i=row1+1; i<=row2-1; i++)
      for (j=col1+1; j<=col2-1; j++)
        POINT(i,j,color,xor);
    return;
  }

