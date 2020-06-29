
  #include "stdio.h"
  #include "enpqs.c"
  main()
  { double t,z;
    static double x[10]={-1.0,-0.8,-0.65,-0.4,-0.3,
                         0.0,0.2,0.45,0.8,1.0};
    static double y[10]={0.0384615,0.0588236,0.0864865,0.2,0.307692,
                         1.0,0.5,0.164948,0.0588236,0.0384615};
    printf("\n");
    t=-0.85; z=enpqs(x,y,10,t);
    printf("t=%6.3f,   z=%e\n",t,z);
    t=0.25; z=enpqs(x,y,10,t);
    printf("t=%6.3f,   z=%e\n",t,z);
    printf("\n");
  }

