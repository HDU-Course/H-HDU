
  #include "math.h"
  #include "stdio.h"
  #include "dsrrt.c"
  main()
  { int i;
    static double xr[6],xi[6];
    static double a[7]={ -20.0,7.0,-7.0,1.0,3.0,-5.0,1.0};
    i=dsrrt(a,6,xr,xi);
    printf("\n");
    if (i>0)
      { for (i=0; i<=5; i++)
          printf("x(%d)=%13.7e j %13.7e\n",i,xr[i],xi[i]);
        printf("\n");
      }
  }

