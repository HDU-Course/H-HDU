
  #include "stdio.h"
  #include "lgam2.c"
  #include "lgam1.c"
  main()
  { int i,j;
    double y,s,t;
    static double a[3]={0.5,5.0,50.0};
    static double x[3]={0.1,1.0,10.0};
    printf("\n");
    for (i=0; i<=2; i++)
    for (j=0; j<=2; j++)
      { s=a[i]; t=x[j];
        y=lgam2(s,t);
        printf("gamma(%4.1f,%4.1f)=%e\n",a[i],x[j],y);
      }
    printf("\n");
  }


