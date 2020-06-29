
  #include "math.h"
  void ncdiv(pr,pi,m,qr,qi,n,sr,si,k,rr,ri,l)
  int m,n,k,l;
  double pr[],pi[],qr[],qi[],sr[],si[],rr[],ri[];
  { int i,j,mm,ll;
    double a,b,c,d,u,v;
    extern void ocmul();
    extern void ocdiv();
    for (i=0; i<=k-1; i++) 
      { sr[i]=0.0; si[i]=0.0; }
    d=qr[n-1]*qr[n-1]+qi[n-1]*qi[n-1];
    if (d+1.0==1.0) return;
    ll=m-1;
    for (i=k; i>=1; i--)
      { a=pr[ll]; b=pi[ll]; c=qr[n-1]; d=qi[n-1];
        ocdiv(a,b,c,d,&u,&v);
        sr[i-1]=u; si[i-1]=v;
        mm=ll;
        for (j=1; j<=n-1; j++)
          { a=sr[i-1]; b=si[i-1]; 
            c=qr[n-j-1]; d=qi[n-j-1];
            ocmul(a,b,c,d,&u,&v);
            pr[mm-1]=pr[mm-1]-u;
            pi[mm-1]=pi[mm-1]-v;
            mm=mm-1;
          }
        ll=ll-1;
      }
    for (i=0; i<=l-1; i++) 
      { rr[i]=pr[i]; ri[i]=pi[i]; }
    return;
  }

