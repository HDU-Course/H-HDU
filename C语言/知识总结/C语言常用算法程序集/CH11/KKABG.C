
  void kkabg(n,x,t,a,b,c,y)
  int n;
  double x[],t,a,b,c,y[];
  { int i;
    double s1,ss,v1,vv,a1,aa;
    aa=0.0; vv=0.0;ss=0.0;
    for (i=0; i<=n-1; i++)
      { s1=ss+t*vv+t*t*aa/2.0;
        v1=vv+t*aa; a1=aa;
        ss=s1+a*(x[i]-s1); y[i]=ss;
        vv=v1+b*(x[i]-s1);
        aa=a1+2.0*c*(x[i]-s1)/(t*t);
      }
    return;
  }

