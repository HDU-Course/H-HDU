  
  void sscls(row1,col1,row2,col2)
  int row1,col1,row2,col2;
  { int i,j,t;
    extern int POINT();
    for (i=row1; i<=row2; i++)
      { for (j=col1; j<=col2; j++)
          { t=POINT(i,j,-1,0); 
            POINT(i,j,t,1);
          }
      }
    return;
  }

