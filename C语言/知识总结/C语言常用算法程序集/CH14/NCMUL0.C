
  #include "stdio.h"
  #include "ncmul.c"
  #include "ocmul.c"
  main()
  { int i;
    static double pr[6]={4.0,-6.0,5.0,2.0,-1.0,3.0};
    static double pi[6]={2.0,3.0,-4.0,1.0,-1.0,2.0};
    static double qr[4]={2.0,3.0,-6.0,2.0};
    static double qi[4]={1.0,2.0,-4.0,1.0};
    double sr[9],si[9];
    ncmul(pr,pi,6,qr,qi,4,sr,si,9);
    printf("\n");
    for (i=0; i<=8; i++)
      printf(" s(%d)=%13.7e +j %13.7e\n",i,sr[i],si[i]);
    printf("\n");
  }

