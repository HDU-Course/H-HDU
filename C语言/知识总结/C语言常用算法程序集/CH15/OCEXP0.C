
  #include "stdio.h"
  #include "ocexp.c"
  main()
  { double x,y,u,v;
    x=1.0; y=4.0;
    ocexp(x,y,&u,&v);
    printf("\n");
    printf("  %13.7e +j %13.7e\n",u,v);
    printf("\n");
  }

