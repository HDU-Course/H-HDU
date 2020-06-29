
  #include "stdio.h"
  #include "dnetn.c"
  #include "agaus.c"
  main()
  { int i,k;
    double eps,t,h;
    static double x[3]={1.0,1.0,1.0};
    t=0.1; h=0.1; eps=0.0000001; k=100;
    i=dnetn(3,eps,t,h,x,k);
    printf("\n");
    printf("i=%d\n",i);
    printf("\n");
    for (i=0; i<=2; i++)
      printf("x(%d)=%13.7e\n",i,x[i]);
    printf("\n");
  }

  void dnetnf(x,y,n)
  int n;
  double x[],y[];
  { y[0]=x[0]*x[0]+x[1]*x[1]+x[2]*x[2]-1.0;
    y[1]=2.0*x[0]*x[0]+x[1]*x[1]-4.0*x[2];
    y[2]=3.0*x[0]*x[0]-4.0*x[1]+x[2]*x[2];
    n=n;
    return;
  }

