 
  #include "stdio.h"
  #include "fmtml.c"
  #include "mrnd1.c"
  main()
  { static double a[3]={ 1.0,1.0,1.0};
    static double b[3]={ 2.0,2.0,2.0};
    printf("\n");
    printf("s=%e\n",fmtml(3,a,b));
    printf("\n");
  }

  double fmtmlf(n,x)
  int n;
  double x[];
  { int i;
    double f;
    f=0.0;
    for (i=0; i<=n-1; i++)
      f=f+x[i]*x[i];
    return(f);
  }

