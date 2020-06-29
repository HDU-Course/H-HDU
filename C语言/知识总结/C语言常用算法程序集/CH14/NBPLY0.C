
  #include "stdio.h"
  #include "nbply.c"
  main()
  { double z;
    static double a[4][5]={{1.0,2.0,3.0,4.0,5.0},
                         {6.0,7.0,8.0,9.0,10.0},
                     {11.0,12.0,13.0,14.0,15.0},
                    {16.0,17.0,18.0,19.0,20.0}};
    printf("\n");
    z=nbply(a,4,5,0.6,-1.3);
    printf(" p(0.60,-1.30)=%13.7e\n",z);
    printf("\n");
  }

