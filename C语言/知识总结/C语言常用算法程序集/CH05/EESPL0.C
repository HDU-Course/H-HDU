
  #include "eespl.c"
  #include "stdio.h"
  main()
  { int k,n;
    double t,x0,h;
    static double y[11]={0.0384615,0.0588236,0.1,0.2,0.5,
                     1.0,0.5,0.2,0.1,0.0588236,0.0384615};
    static double s[5];
    k=-1; n=11; x0=-1.0; h=0.2;
    printf("\n");
    t=-0.65; eespl(x0,h,n,y,k,t,s);
    printf("x=%6.3f,   f(x)=%e\n",t,s[4]);
    printf("s0=%e, s1=%e, s2=%e, s3=%e\n",s[0],s[1],s[2],s[3]);
    printf("\n");
    t=0.25; eespl(x0,h,n,y,k,t,s);
    printf("x=%6.3f,   f(x)=%e\n",t,s[4]);
    printf("s0=%e, s1=%e, s2=%e, s3=%e\n",s[0],s[1],s[2],s[3]);
    printf("\n");
  }

