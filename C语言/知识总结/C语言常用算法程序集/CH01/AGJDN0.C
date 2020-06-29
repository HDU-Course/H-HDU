
  #include "stdio.h"
  #include "agjdn.c"
  main()
  { int i;
    static double a[4][4]={ {1.0,3.0,2.0,13.0},
                            {7.0,2.0,1.0,-2.0},
                            {9.0,15.0,3.0,-2.0},
                            {-2.0,-2.0,11.0,5.0}};
    static double b[4][2]={ {9.0,0.0},{6.0,4.0},
                            {11.0,7.0},{-2.0,-1.0}};
    if (agjdn(a,b,4,2)!=0)
      for (i=0;i<=3;i++)
        printf("x(%d)=%13.7e,  %13.7e\n",i,b[i][0],b[i][1]);
  }

