
  #include "stdio.h"
  #include "prbub.c"
  #include "mrnds.c"
  main()
  { int i,j;
    double p[100],r0,*r,*s;
    r0=5; r=&r0; s=p+30;
    mrnds(r,p,100);
    for (i=0; i<=99; i++)
      p[i]=100.0+200.0*p[i];
    printf("\n");
    for (i=0; i<=9; i++)
      { for (j=0; j<=9; j++)
          printf("%7.3f ",p[10*i+j]);
        printf("\n");
      }
    printf("\n");
    prbub(s,50);
    for (i=0; i<=9; i++)
      { for (j=0; j<=9; j++)
          printf("%7.3f ",p[10*i+j]);
        printf("\n");
      }
    printf("\n");
  }

