
  #include "stdio.h"
  #include "enlg3.c"
  main()
  { double t,z;
    static double x[5]={1.615,1.634,1.702,1.828,1.921};
    static double y[5]={2.41450,2.46459,2.65271,3.03035,3.34066};
    printf("\n");
    t=1.682; z=enlg3(x,y,5,t);
    printf("x=%6.3f,   f(x)=%e\n",t,z);
    t=1.813; z=enlg3(x,y,5,t);
    printf("x=%6.3f,   f(x)=%e\n",t,z);
    printf("\n");
  }

