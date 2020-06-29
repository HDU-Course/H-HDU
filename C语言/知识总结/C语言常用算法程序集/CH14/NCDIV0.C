
  #include "stdio.h"
  #include "ncdiv.c"
  #include "ocmul.c"
  #include "ocdiv.c"
  main()
  { int i;
    static double pr[5]={8.0,-5.0,-3.0,6.0,3.0};
    static double pi[5]={3.0,4.0,4.0,-5.0,-1.0};
    static double qr[3]={1.0,-1.0,2.0};
    static double qi[3]={2.0,-3.0,2.0};
    double sr[3],si[3],rr[2],ri[2];
    ncdiv(pr,pi,5,qr,qi,3,sr,si,3,rr,ri,2);
    printf("\n");
    for (i=0; i<=2; i++)
      printf(" s(%d)=%13.7e +j %13.7e\n",i,sr[i],si[i]);
    printf("\n");
    for (i=0; i<=1; i++)
      printf(" r(%d)=%13.7e +j %13.7e\n",i,rr[i],ri[i]);
    printf("\n");
  }

