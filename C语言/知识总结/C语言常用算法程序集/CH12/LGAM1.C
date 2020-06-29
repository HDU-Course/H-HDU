
  #include "stdio.h"
  double lgam1(x)
  double x;
  { int i;
    double y,t,s,u;
    static double a[11]={ 0.0000677106,-0.0003442342,
           0.0015397681,-0.0024467480,0.0109736958,
           -0.0002109075,0.0742379071,0.0815782188,
           0.4118402518,0.4227843370,1.0};
    if (x<=0.0)
      { printf("err**x<=0!\n"); return(-1.0);}
    y=x;
    if (y<=1.0)
      { t=1.0/(y*(y+1.0)); y=y+2.0;}
    else if (y<=2.0)
      { t=1.0/y; y=y+1.0;}
    else if (y<=3.0) t=1.0;
    else
      { t=1.0;
        while (y>3.0)
          { y=y-1.0; t=t*y;}
      }
    s=a[0]; u=y-2.0;
    for (i=1; i<=10; i++)
      s=s*u+a[i];
    s=s*t;
    return(s);
  }

