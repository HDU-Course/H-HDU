
  #include "stdio.h"
  #include "kkfwt.c"
  main()
  { int i;
    double p[8],x[8];
    for (i=0; i<=7; i++) p[i]=i+1;
    kkfwt(p,8,3,x);
    printf("\n");
    for (i=0; i<=7; i++)
      printf("x(%2d)=%e\n",i,x[i]);
    printf("\n");
  }

