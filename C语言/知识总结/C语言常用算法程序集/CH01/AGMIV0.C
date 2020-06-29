
  #include "stdio.h"
  #include "agmiv.c"
  #include "bginv.c"
  #include "bmuav.c"
  main()
  { int i,m,n,ka;
    static double x[3],aa[3][4],u[4][4],v[3][3];
    static double a[4][3]={ {1.0,1.0,-1.0},{2.0,1.0,0.0},
                            {1.0,-1.0,0.0},{-1.0,2.0,1.0}};
    static double b[4]={2.0,-3.0,1.0,4.0};
    double eps;
    m=4; n=3; ka=5; eps=0.000001;
    i=agmiv(a,m,n,b,x,aa,eps,u,v,ka);
    if (i>0)
      { for (i=0; i<=2; i++)
          printf("x(%d)=%13.7e\n",i,x[i]);
        printf("\n");
        printf("MAT A+ :\n");
        for (i=0; i<=2; i++)
          printf("%13.7e %13.7e %13.7e %13.7e\n",
                  aa[i][0],aa[i][1],aa[i][2],aa[i][3]);
        printf("\n");
      }
  }

