
  #include "stdio.h"
  #include "mrnds.c"
  #include "prshl.c"
  #include "qrbsh.c"
  main()
  { int i,j,m0,*m;
    double p[100],r0,*r,a,b;
    r0=5.0; r=&r0; m=&m0;
    mrnds(r,p,100);
    prshl(p,100);
    printf("\n");
    for (i=0; i<=19; i++)
      { for (j=0; j<=4; j++)
          printf("%10.7f",p[5*i+j]);
        printf("\n");
      }
    printf("\n");
    a=0.4; b=0.5;
    i=qrbsh(p,100,a,b,m);
    printf("m=%d\n",m0);
    printf("i=%d\n",i);
    for (j=i; j<=i+m0-1; j++)
      printf("p(%d)=%10.7f\n",j,p[j]);
    printf("\n");
  }

