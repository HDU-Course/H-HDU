
  #include "math.h"
  void fpart(a,b,m,n,fa,fb,s)
  int m,n;
  double a,b,fa[],fb[],s[];
  { int mm,k,j;
    double sa[4],sb[4],ca[4],cb[4],sma,smb,cma,cmb;
    sma=sin(m*a); smb=sin(m*b);
    cma=cos(m*a); cmb=cos(m*b);
    sa[0]=sma; sa[1]=cma; sa[2]=-sma; sa[3]=-cma;
    sb[0]=smb; sb[1]=cmb; sb[2]=-smb; sb[3]=-cmb;
    ca[0]=cma; ca[1]=-sma; ca[2]=-cma; ca[3]=sma;
    cb[0]=cmb; cb[1]=-smb; cb[2]=-cmb; cb[3]=smb;
    s[0]=0.0; s[1]=0.0;
    mm=1;
    for (k=0;k<=n-1;k++)
      { j=k;
        while (j>=4) j=j-4;
        mm=mm*m;
        s[0]=s[0]+(fb[k]*sb[j]-fa[k]*sa[j])/(1.0*mm);
        s[1]=s[1]+(fb[k]*cb[j]-fa[k]*ca[j])/(1.0*mm);
      }
    s[1]=-s[1];
    return;
  }

