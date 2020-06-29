
  #include "stdio.h"
  #include "hpir1.c"
  #include "math.h"
  main()
  { int i;
    double x[20],y[20],a[6],dt[3];
    for (i=0; i<=19; i++)
      { x[i]=0.1*i;
        y[i]=x[i]-exp(-x[i]);
      }
    hpir1(x,y,20,a,6,dt);
    printf("\n");
    for (i=0; i<=5; i++)
      printf("a(%2d)=%e\n",i,a[i]);
    printf("\n");
    for (i=0; i<=2; i++)
      printf("dt(%2d)=%e  ",i,dt[i]);
    printf("\n\n");
  }

