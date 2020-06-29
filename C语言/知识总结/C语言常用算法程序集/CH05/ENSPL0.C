
  #include "enspl.c"
  #include "stdio.h"
  main()
  { int k,n;
    double t;
    static double x[11]={-1.0,-0.95,-0.75,-0.55,-0.3,0.0,
                         0.2,0.45,0.6,0.8,1.0};
    static double y[11]={0.0384615,0.0424403,0.06639,0.116788,
           0.307692,1.0,0.5,0.164948,0.1,0.0588236,0.0384615};
    static double s[5];
    k=-1; n=11;
    printf("\n");
    t=-0.85; enspl(x,y,n,k,t,s);
    printf("x=%6.3f,   f(x)=%e\n",t,s[4]);
    printf("s0=%e, s1=%e, s2=%e, s3=%e\n",s[0],s[1],s[2],s[3]);
    printf("\n");
    t=0.15; enspl(x,y,n,k,t,s);
    printf("x=%6.3f,   f(x)=%e\n",t,s[4]);
    printf("s0=%e, s1=%e, s2=%e, s3=%e\n",s[0],s[1],s[2],s[3]);
    printf("\n");
  }

