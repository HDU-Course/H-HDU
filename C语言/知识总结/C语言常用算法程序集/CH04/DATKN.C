
  #include "math.h"
  int datkn(x,eps,js)
  int js;
  double eps,*x;
  { int flag,l;
    double u,v,x0;
    extern double datknf();
    l=0; x0=*x; flag=0;
    while ((flag==0)&&(l!=js))
      { l=l+1; 
        u=datknf(x0); v=datknf(u);
        if (fabs(u-v)<eps) { x0=v; flag=1; }
        else x0=v-(v-u)*(v-u)/(v-2.0*u+x0);
      }
    *x=x0; l=js-l;
    return(l);
  }

 