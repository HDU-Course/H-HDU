
  #include "math.h"
  #include "stdlib.h"
  void spsp3(row,col,x0,y0,r,xp,yp,zp,
                             dx,dy,color,xor)
  int row,col,x0,y0,r,xp,yp,zp,dx,dy,color,xor;
  { int vv,du,dv,kk,*mx,*mn,i,j,k,l,u0,v0,u1,v1;
    double x,y,z,b1,b2,b3,ca,cc,ss,sc,cca,yyy,
           ssa,u,v,xx,yy,zz,xx0,yy0,rr,dyy;
    extern double persp3f();
    extern void sline();
    extern int POINT();
    if (dx<0) dx=-dx;
    if (dy<0) dy=-dy;
    dyy=(double)dy;
    mx=malloc(2000*sizeof(int));
    mn=malloc(2000*sizeof(int));
    for (i=0; i<=1999; i++)
      { mx[i]=-2000; mn[i]=2000;}
    xx=(double)xp; yy=(double)yp; zz=(double)zp;
    b1=-xx;
    b2=-yy;
    b3=-zz;
    ca=sqrt(b1*b1+b2*b2+b3*b3); ca=b1/ca;
    if (ca<0.0) ca=-ca;
    ss=b2*b2; sc=b3*b3; cc=sc/(sc+ss);
    ss=ss/(sc+ss);
    cca=cc*ca; ssa=ss*ca;
    sc=-(b2*b3)/(b3*b3+b2*b2); sc=sc*(1.0-ca);
    u0=0; v0=0; xx0=(double)x0; yy0=(double)y0;
    rr=(double)r;
    for (i=x0+r; i>=x0-r; i=i-dx)
      { x=(double)i; k=0; l=0;
        b1=sqrt(rr*rr-(x-xx0)*(x-xx0));
        b2=-b1; b1=yy0+b1; b2=yy0+b2;
        for (yyy=b2; yyy<=b1+dyy; yyy=yyy+dyy)
          { y=yyy;
            if (yyy>b1) y=b1;
            z=persp3f(x,y);
            u=(y*xx-x*yy)/xx;
            v=(z*xx-x*zz)/xx;
            ca=u*(cc+ssa)+v*sc;
            v=u*sc+v*(ss+cca); 
            v1=row-(int)v; u1=col+(int)ca;
            if ((u1>=0)&&(u1<=1999))
              { if (k!=0)
                  { if ((v1<mx[u1])&&(v1>mn[u1])) k=0;
                    else 
                      { sline(v0,u0,v1,u1,color,xor);
                        POINT(v1,u1,color,xor);
                      }
                  }
                else if ((v1>mx[u1])||(v1<mn[u1])) k=1;
                if (l==0) u0=u1;
                du=u1-u0; dv=v1-v0; kk=0;
                if (du==0)
                  { if (v1>mx[u1]) mx[u1]=v1;
                    if (v1<mn[u1]) mn[u1]=v1;
                  }
                else
                  for (l=u0; l<=u1; l++) 
                    { vv=v0+kk*dv/du;
                      if (vv>mx[l]) mx[l]=vv;
                      if (vv<mn[l]) mn[l]=vv;
                      kk=kk+1;
                    }
                v0=v1; u0=u1; l=1;
              }
          }
      }
    POINT(v0,u0,color,xor);
    free(mx); free(mn); return;
  }

