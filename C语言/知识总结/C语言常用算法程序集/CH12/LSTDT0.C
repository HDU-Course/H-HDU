
  #include "stdio.h"
  #include "lstdt.c"
  #include "lbeta.c"
  #include "lgam1.c"
  main()
  { int n;
    double t,y;
    printf("\n");
    for (n=1; n<=5; n++)
      { t=0.5; y=lstdt(t,n);
        printf("P(%4.2f, %d)=%e\n",t,n,y);
        t=5.0; y=lstdt(t,n);
        printf("P(%4.2f, %d)=%e\n",t,n,y);
      }
    printf("\n");
  }

