
  #include "math.h"
  #include "stdio.h"
  #include "dsnse.c"
  main()
  { int i,js;
    double eps;
    static double x[3]={1.5,6.5,-5.0};
    js=500; eps=0.000001;
    i=dsnse(3,eps,x,js);
    printf("\n");
    if ((i>0)&&(i<js))
      { for (i=0; i<=2; i++)
          printf("x(%d)=%13.7e\n",i,x[i]);
        printf("\n");
      }
  }

  double dsnsef(x,y,n)
  int n;
  double x[],y[];
  { double z,f1,f2,f3,df1,df2,df3;
    n=n;
    f1=x[0]-5.0*x[1]*x[1]+7.0*x[2]*x[2]+12.0;
    f2=3.0*x[0]*x[1]+x[0]*x[2]-11.0*x[0];
    f3=2.0*x[1]*x[2]+40.0*x[0];
    z=f1*f1+f2*f2+f3*f3;
    df1=1.0; df2=3.0*x[1]+x[2]-11.0; df3=40.0;
    y[0]=2.0*(f1*df1+f2*df2+f3*df3);
    df1=10.0*x[1]; df2=3.0*x[0]; df3=2.0*x[2];
    y[1]=2.0*(f1*df1+f2*df2+f3*df3);
    df1=14.0*x[2]; df2=x[0]; df3=2.0*x[1];
    y[2]=2.0*(f1*df1+f2*df2+f3*df3);
    return(z);
  }


