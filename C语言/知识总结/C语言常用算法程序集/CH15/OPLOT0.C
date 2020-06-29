
  #include "stdio.h"
  #include "oplot.c"
  main()
  { char xc,yc,c;
    int n,k;
    double x[50],y[50],fi,xd,yd;
    n=50; xc='+'; yc='+'; c='*';
    for (k=0; k<=n-1; k++)
      { fi=0.2*k; 
        x[k]=2.0+fi*cos(fi);
        y[k]=fi*sin(fi);
      }
    oplot(n,x,y,xc,yc,c,&xd,&yd);
  }

