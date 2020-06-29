
  #include "math.h"
  #include "stdio.h"
  #include "espl3.c"
  main()
  { int n,m,i,j;
    double u,s;
    static double x[37],y[37],dy[37],ddy[37];
    static double t[36],z[36],dz[36],ddz[36];
    for (i=0;i<=36;i++)
      { x[i]=i*6.2831852/36.0;
        y[i]=sin(x[i]);
      }
    for (i=0;i<=35;i++)
        t[i]=(0.5+i)*6.2831852/36.0;
    n=37; m=36;
    printf("\n");
    s=espl3(x,y,n,dy,ddy,t,m,z,dz,ddz);
    printf(" x(i) y(i)=sin(x) dy(i)=cos(x) ddy(i)=-sin(x)\n");
    printf("%6.1f%10.6f%11.6f%12.6f\n",x[0],y[0],dy[0],ddy[0]);
    for (i=0;i<=35;i++)
      { u=t[i]*36.0/0.62831852;
        printf("%6.1f%10.6f%11.6f%12.6f\n",u,z[i],dz[i],ddz[i]);
        u=x[i+1]*36.0/0.62831852;
        j=i+1;
        printf("%6.1f%10.6f%11.6f%12.6f\n",u,y[j],dy[j],ddy[j]);
      }
    printf("\n");
    printf("s=%e\n",s);
    printf("\n");
  }

