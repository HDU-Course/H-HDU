
  #include "stdio.h"
  #include "atlvs.c"
  main()
  { int i;
    static double x[6];
    static double t[6]={6.0,5.0,4.0,3.0,2.0,1.0};
    static double b[6]={11.0,9.0,9.0,9.0,13.0,17.0};
    if (atlvs(t,6,b,x)>0)
      for (i=0; i<=5; i++)
        printf("x(%d)=%13.7e\n",i,x[i]);
  }

