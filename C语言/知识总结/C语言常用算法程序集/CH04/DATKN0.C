
  #include "math.h"
  #include "stdio.h"
  #include "datkn.c"
  main()
  { int js,k;
    double x,eps;
    eps=0.0000001; js=20; x=0.0;
    k=datkn(&x,eps,js);
    printf("\n");
    printf("k=%d  x=%13.7e\n",k,x);
    printf("\n");
  }

  double datknf(x)
  double x;
  { double y;
    y=6.0-x*x;
    return(y);
  }

