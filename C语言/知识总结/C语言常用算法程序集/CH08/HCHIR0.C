
  #include "math.h"
  #include "stdio.h"
  #include "hchir.c"
  main()
  { int i;
    double x[101],y[101],a[7];
    for (i=0; i<=100; i++)
      { x[i]=-1.0+0.02*i;
        y[i]=atan(x[i]);
      }
    hchir(x,y,101,a,6);
    printf("\n");
    for (i=0; i<=5; i++)
      printf("a(%2d)=%e\n",i,a[i]);
    printf("\n");
    printf("MAX(p-f)=%e\n",a[6]);
    printf("\n");
  }

