
  #include "stdio.h"
  #include "eelgr.c"
  main()
  { double x0,h,t,z;
    static double y[10]={0.904837,0.818731,0.740818,0.670320,0.606531,
                       0.548812,0.496585,0.449329,0.406570,0.367879};
    x0=0.1; h=0.1;
    printf("\n");
    t=0.25; z=eelgr(x0,h,10,y,t);
    printf("t=%6.3f,   z=%e\n",t,z);
    t=0.63; z=eelgr(x0,h,10,y,t);
    printf("t=%6.3f,   z=%e\n",t,z);
    t=0.95; z=eelgr(x0,h,10,y,t);
    printf("t=%6.3f,   z=%e\n",t,z);
    printf("\n");
  }

