
  #include "math.h"
  double fhmgs()
  { int i;
    double x,g;
    extern double fhmgsf();
    static double t[5]={-2.02018200,-0.95857190,
                     0.0,0.95857190,2.02018200};
    static double c[5]={1.181469599,0.9865791417,
           0.9453089237,0.9865791417,1.181469599};
    g=0.0;
    for (i=0; i<=4; i++)
      { x=t[i]; g=g+c[i]*fhmgsf(x); }
    return(g);
  }

