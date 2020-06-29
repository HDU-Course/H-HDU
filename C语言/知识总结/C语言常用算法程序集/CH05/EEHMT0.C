
  #include "stdio.h"
  #include "eehmt.c"
  main()
  { int i;
    double x0,h,t,z;
    static double y[10]={0.904837,0.818731,0.740818,0.670320,
      0.606531,0.548812,0.496585,0.449329,0.406570,0.367879};
    static double dy[10];
    printf("\n");
    for (i=0;i<=9;i++) dy[i]=-y[i];
    x0=0.1; h=0.1;
    t=0.752; z=eehmt(x0,h,10,y,dy,t);
    printf("t=%6.3f,   z=%e\n",t,z);
    printf("\n");
  }

