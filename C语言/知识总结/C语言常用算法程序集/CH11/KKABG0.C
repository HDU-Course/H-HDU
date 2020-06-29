
  #include "stdio.h"
  #include "kkabg.c"
  main()
  { int i;
    void kfabg5();
    double x[250],y[250],z[250];
    double a,b,c,dt,t;
    a=0.271; b=0.0285; c=0.0005; dt=0.04;
    printf("\n");
    kfabg5(250,y);
    for (i=0; i<=249; i++)
      { t=(i+1)*dt;
        z[i]=3.0*t*t-2.0*t+5.0;
        x[i]=z[i]+y[i];
      }
    kkabg(250,x,dt,a,b,c,y);
    for (i=0; i<=249; i=i+5)
      { t=(i+1)*dt;
        printf("t=%5.2f  x(t)=%e  y(t)=%e  z(t)=%e\n",
                t,x[i],y[i],z[i]);
      }
    printf("\n");
  }

  static void kfabg5(n,y)
  int n;
  double y[];
  { int i,j,m;
    double s,w,v,r,t;
    s=65536.0; w=2053.0; v=13849.0; r=0.0;
    for (i=0; i<=n-1; i++)
      { t=0.0;
        for (j=0; j<=11; j++)
          { r=w*r+v; m=r/s; r=r-m*s; t=t+r/s;}
        y[i]=0.5*(t-6.0);
      }
    return;
  }

