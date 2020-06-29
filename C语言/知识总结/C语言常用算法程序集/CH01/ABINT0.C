
  #include "stdio.h"
  #include "abint.c"
  #include "brmul.c"
  #include "agaus.c"
  main()
  { int k;
    double eps=0.000001,x[4];
    static double a[4][4]=
                 {{3.4336,-0.5238,0.67105,-0.15272},
                  {-0.5238,3.28326,-0.73051,-0.2689},
                  {0.67105,-0.73051,4.02612,0.01835},
                  {-0.15272,-0.2689,0.01835,2.75702}};
    static double b[4]={-1.0,1.5,2.5,-2.0};
    if (abint(a,4,b,eps,x)!=0)
      { printf("\n");
        for (k=0; k<=3; k++)
        printf("x[%d]=%13.7e\n",k,x[k]);
        printf("\n");
      }
  }

