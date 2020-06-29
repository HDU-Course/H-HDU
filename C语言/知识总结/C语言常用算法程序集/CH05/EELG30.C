
  #include "stdio.h"
  #include "eelg3.c"
  main()
  { double t,z,x0,h;
    static double y[10]={0.904837,0.818731,0.740818,0.670320,0.606531,
                       0.548812,0.496585,0.449329,0.406570,0.367879};
    x0=0.1; h=0.1;
    printf("\n");
    t=0.23; z=eelg3(x0,h,10,y,t);
    printf("t=%6.3f,   z=%e\n",t,z);
    t=0.63; z=eelg3(x0,h,10,y,t);
    printf("t=%6.3f,   z=%e\n",t,z);
    t=0.95; z=eelg3(x0,h,10,y,t);
    printf("t=%6.3f,   z=%e\n",t,z);
    printf("\n");
  }
 
