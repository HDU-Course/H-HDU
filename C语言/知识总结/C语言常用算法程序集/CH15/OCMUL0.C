
  #include "stdio.h"
  #include "ocmul.c"
  main()
  { double e,f;
    ocmul(-1.3,4.5,7.6,3.6,&e,&f);
    printf("\n");
    printf("  e+jf=%10.7lf +j %10.7f\n",e,f);
    printf("\n");
  }

