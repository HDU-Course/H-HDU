
  #include "math.h"
  #include "stdio.h"
  #include "dpqrt.c"
  main()
  { double x,eps;
    int k;
    x=1.0; eps=0.000001;
    k=dpqrt(&x,eps);
    printf("\n");
    printf("k=%d   x=%13.7e\n",k,x);
    printf("\n");
  }

  double dpqrtf(x)
  double x;
  { double y;
    y=x*x*(x-1.0)-1.0;
    return(y);
  }

