
  #include "stdio.h"
  #include "ncply.c"
  #include "ocmul.c"
  main()
  { double x,y,u,v;
    static double ar[4]={2.0,2.0,1.0,2.0};
    static double ai[4]={1.0,1.0,1.0,2.0};
    printf("\n");
    x=1.0; y=1.0;
    ncply(ar,ai,4,x,y,&u,&v);
    printf("p(1.0+j1.0)=%10.7lf +j %10.7lf\n",u,v);
    printf("\n");
  }

