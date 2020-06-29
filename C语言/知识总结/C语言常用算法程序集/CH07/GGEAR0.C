
  #include "stdio.h"
  #include "ggear.c"
  #include "brinv.c"
  main()
  { int i,j,k,jjs;
    double a,b,hmax,h,y[3],t[30],z[3][30];
    static double hmin[4]={0.0001,0.0001,0.00001,0.00001};
    static double eps[4]={0.001,0.0001,0.0001,0.00001};
    a=0.0; b=1.0; h=0.01; hmax=0.1;
    for (k=0; k<=3; k++)
      { y[0]=1.0; y[1]=0.0; y[2]=-1.0;
        jjs=ggear(a,b,hmin[k],hmax,h,eps[k],3,y,30,t,z);
        printf("\n");
        printf("h=%5.2f\n",h);
        printf("hmin=%8.5f\n",hmin[k]);
        printf("hmax=%5.2f\n",hmax);
        printf("eps=%8.5f\n",eps[k]);
        printf("\n");
        printf("jjs=%d\n",jjs);
        printf("\n");
        for (i=0; i<=29; i++)
          { printf("t=%10.6f  ",t[i]);
            for (j=0; j<=2; j++)
              printf("y(%d)=%e  ",j,z[j][i]);
            printf("\n");
          }
        printf("\n");
      }
  }

  void ggearf(t,y,n,d)
  int n;
  double t,y[],d[];
  { t=t; n=n;
    d[0]=-21.0*y[0]+19.0*y[1]-20.0*y[2];
    d[1]=19.0*y[0]-21.0*y[1]+20.0*y[2];
    d[2]=40.0*y[0]-40.0*y[1]-40.0*y[2];
    return;
  }

  void ggears(t,y,n,p)
  int n;
  double t,y[],p[3][3];
  { t=t; n=n; y[0]=y[0];
    p[0][0]=-21.0; p[0][1]=19.0; p[0][2]=-20.0;
    p[1][0]=19.0; p[1][1]=-21.0; p[1][2]=20.0;
    p[2][0]=40.0; p[2][1]=-40.0; p[2][2]=-40.0;
    return;
  }

