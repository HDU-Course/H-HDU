
  #include "math.h"
  #include "stdio.h"
  void irhis(x,n,x0,h,m,l,dt,g,q)
  int n,m,l,g[],q[];
  double x[],x0,h,dt[];
  { int i,j,k,z;
    double s;
    char a[50];
    dt[0]=0.0;
    for (i=0; i<=n-1; i++) dt[0]=dt[0]+x[i]/n;
    dt[1]=0.0;
    for (i=0; i<=n-1; i++)
      dt[1]=dt[1]+(x[i]-dt[0])*(x[i]-dt[0]);
    dt[1]=dt[1]/n;
    dt[2]=sqrt(dt[1]);
    for (i=0; i<=m-1; i++)
      { q[i]=0;
        s=x0+(i+0.5)*h-dt[0];
        s=exp(-s*s/(2.0*dt[1]));
        g[i]=n*s*h/(dt[2]*2.5066);
      }
    s=x0+m*h;
    for (i=0; i<=n-1; i++)
      if ((x[i]-x0)>=0.0)
        if ((s-x[i])>=0.0)
          { j=(x[i]-x0)/h;
            q[j]=q[j]+1;
          }
    if (l==0) return;
    printf("\n");
    printf("n=%d\n",n);
    printf("\n");
    printf("x0=%e  h=%e  m=%d\n",x0,h,m);
    printf("\n");
    printf("xa=%e  s=%e  t=%e\n",dt[0],dt[1],dt[2]);
    printf("\n");
    k=1; z=0;
    for (i=0; i<=m-1; i++)
      if (q[i]>z) z=q[i];
    while (z>50)
      { z=z/2; k=2*k;}
    for (i=0; i<=m-1; i++)
      { s=x0+(i+0.5)*h;
        for (j=0; j<=49; j++) a[j]=' ';
        j=q[i]/k;
        for (z=0; z<=j-1; z++) a[z]='X';
        j=g[i]/k;
        if ((j>0)&&(j<=50)) a[j]='*';
        printf("%e  %7d  ",s,q[i]);
        for (j=0; j<=49; j++)
          printf("%c",a[j]);
        printf("\n");
      }
    printf("\n");
    printf("k=%d\n",k);
    printf("\n");
    return;
  }

