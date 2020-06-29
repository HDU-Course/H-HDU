
  #include "stdio.h"
  #include "acgas.c"
  main()
  { int i;
    static double ar[4][4]={ {1.0,3.0,2.0,13.0},
                             {7.0,2.0,1.0,-2.0},
                             {9.0,15.0,3.0,-2.0},
                             {-2.0,-2.0,11.0,5.0}};
    static double ai[4][4]={ {3.0,-2.0,1.0,6.0},
                             {-2.0,7.0,5.0,8.0},
                             {9.0,-3.0,15.0,1.0},
                             {-2.0,-2.0,7.0,6.0}};
    static double br[4]={2.0,7.0,3.0,9.0};
    static double bi[4]={1.0,2.0,-2.0,3.0};
    if (acgas(ar,ai,4,br,bi)!=0)
      for (i=0;i<=3;i++)
        printf("b(%d)=%13.7e  +j %13.7e\n",i,br[i],bi[i]);
  }

