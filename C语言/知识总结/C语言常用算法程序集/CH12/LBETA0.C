
  #include "stdio.h"
  #include "lbeta.c"
  #include "lgam1.c"
  main()
  { int i,j;
    double x,a0,b0,y;
    static double a[5]={ 0.5,0.5,1.0,5.0,8.0};
    static double b[5]={ 0.5,5.0,3.0,0.5,10.0};
    printf("\n");
    x=0.0;
    for (j=0; j<=5; j++)
      { printf("x=%4.2f\n",x);
        for (i=0; i<=4; i++)
          { a0=a[i]; b0=b[i];
            y=lbeta(a0,b0,x);
            printf("      B(%4.2f, %4.2f)=%12.7f\n",a0,b0,y);
          }
        x=x+0.2;
      }
    printf("\n");
  }

