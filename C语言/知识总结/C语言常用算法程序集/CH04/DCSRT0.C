
  #include "math.h"
  #include "stdio.h"
  #include "dcsrt.c"
  main()
  { int i;
    static double xr[5],xi[5];
    static double ar[6]={0.1,21.33,4.9,0.0,3.0,1.0};
    static double ai[6]={-100.0,0.0,-19.0,-0.01,2.0,0.0};
    i=dcsrt(ar,ai,5,xr,xi);
    printf("\n");
    if (i>0)
      { for (i=0; i<=4; i++)
          printf("x(%d)=%13.7e j %13.7e\n",i,xr[i],xi[i]);
        printf("\n");
      }
  }

