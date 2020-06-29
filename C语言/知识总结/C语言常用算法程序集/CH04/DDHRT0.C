
  #include "math.h"
  #include "stdio.h"
  #include "ddhrt.c"
  main()
  { int i,n;
    static int m=6;
    static double x[6];
    n=ddhrt(-2.0,5.0,0.2,0.000001,x,m);
    printf("M=%d\n",n);
    for (i=0; i<=n-1; i++)
      printf("x(%d)=%13.7e\n",i,x[i]);
    printf("\n");
  }

  double ddhrtf(x)
  double x;
  { double z;
    z=(((((x-5.0)*x+3.0)*x+1.0)*x-7.0)*x+7.0)*x-20.0;
    return(z);
  }

