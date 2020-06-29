
  #include "enlgr.c"
  #include "stdio.h"
  main()
  { double t,z;
    static double x[10]={0.10,0.15,0.25,0.40,0.50,
                         0.57,0.70,0.85,0.93,1.00};
    static double y[10]={0.904837,0.860708,0.778801,0.670320,0.606531,
                       0.565525,0.496585,0.427415,0.394554,0.367879};
    t=0.63; z=enlgr(x,y,10,t);
    printf("\n");
    printf("t=%6.3f,   z=%e\n",t,z);
    printf("\n");
  }

