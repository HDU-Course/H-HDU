
  #include "math.h"
  double flags()
  { int i;
    double x,g;
    extern double flagsf();
    static double t[5]={0.26355990,1.41340290,
            3.59642600,7.08580990,12.64080000};
    static double c[5]={0.6790941054,1.638487956,
             2.769426772,4.315944000,7.104896230};
    g=0.0;
    for (i=0; i<=4; i++)
      { x=t[i]; g=g+c[i]*flagsf(x); }
    return(g);
  }

