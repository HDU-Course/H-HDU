
  #include "math.h"
  #include "stdio.h"
  #include "fgaus.c"
  main()
  { static int js[3]={4,4,4};
    double s;
    s=fgaus(3,js);
    printf("\n");
    printf("s=%e\n",s);
    printf("\n");
  }

  void fgauss(j,n,x,y)
  int j,n;
  double x[],y[];
  { double q;
    n=n;
    switch (j)
      { case 0: { y[0]=0.0; y[1]=1.0; break;}
        case 1: { y[0]=0.0; y[1]=sqrt(1.0-x[0]*x[0]); break;}
        case 2: { q=x[0]*x[0]+x[1]*x[1]; y[0]=sqrt(q);
                  y[1]=sqrt(2.0-q); break;
                }
        default: { }
      }
    return;
  }

  double fgausf(n,x)
  int n;
  double x[];
  { double z;
    n=n;
    z=x[2]*x[2];
    return(z);
  }

