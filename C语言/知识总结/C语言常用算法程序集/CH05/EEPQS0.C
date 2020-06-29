
  #include "stdio.h"
  #include "eepqs.c"
  main()
  { double x0,h,t,z;
    static double y[11]={0.0384615,0.0588236,0.1,0.2,0.5,1.0,
                         0.5,0.2,0.1,0.0588236,0.0384615};
    printf("\n");
    x0=-1.0; h=0.2;
    t=-0.75; z=eepqs(x0,h,11,y,t);
    printf("t=%6.3f,   z=%e\n",t,z);
    t=-0.05; z=eepqs(x0,h,11,y,t);
    printf("t=%6.3f,   z=%e\n",t,z);
    printf("\n");
  }

