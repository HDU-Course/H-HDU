
  #include "math.h"
  #include "stdio.h"
  void oplot(n,x,y,xc,yc,c,xd,yd)
  int n;
  double x[],y[],*xd,*yd;
  char xc,yc,c;
  { int i,j,k;
    double xx,yy;
    char xy[72][72];
    for (i=0; i<=71; i++)
    for (j=0; j<=71; j++) xy[i][j]=' ';
    xy[0][35]='Y';
    for (i=1; i<=71; i++) xy[i][36]=yc;
    xy[36][71]='X';
    for (j=0; j<=70; j++) xy[36][j]=xc;
    xx=0.0; yy=0.0;
    for (k=0; k<=n-1; k++)
      { if (fabs(x[k])>xx) xx=fabs(x[k]);
        if (fabs(y[k])>yy) yy=fabs(y[k]);
      }
    xx=35.0/xx; yy=35.0/yy;
    for (k=0; k<=n-1; k++)
      { i=37.0-yy*y[k]-0.5;
        j=xx*x[k]+36.0-0.5;
        xy[i][j]=c;
      }
    printf("\n");
    for (i=0; i<=71; i++)
      { for (j=0; j<=71; j++)
          printf("%c",xy[i][j]);
        printf("\n");
      }
    printf("\n");
    printf("X-scale is:%13.7e\n",xx);
    printf("Y-scale is:%13.7e\n",yy);
    printf("\n");
    *xd=xx; *yd=yy;
    return;
  }

