
  #include "math.h"
  double eslq3(x,y,z,n,m,u,v)
  int m,n;
  double u,v,x[],y[],z[];
  { int nn,mm,ip,iq,i,j,k,l;
    double b[3],h,w;
    nn=3;
    if (n<=3) { ip=0;  nn=n;}
    else if (u<=x[1]) ip=0;
    else if (u>=x[n-2]) ip=n-3;
    else
      { i=1; j=n;
        while (((i-j)!=1)&&((i-j)!=-1))
          { l=(i+j)/2;
            if (u<x[l-1]) j=l;
            else i=l;
          }
        if (fabs(u-x[i-1])<fabs(u-x[j-1])) ip=i-2;
        else ip=i-1;
      }
    mm=3;
    if (m<=3) { iq=0; mm=m;}
    else if (v<=y[1]) iq=0;
    else if (v>=y[m-2]) iq=m-3;
    else
      { i=1; j=m;
        while (((i-j)!=1)&&((i-j)!=-1))
          { l=(i+j)/2;
            if (v<y[l-1]) j=l;
            else i=l;
          }
        if (fabs(v-y[i-1])<fabs(v-y[j-1])) iq=i-2;
        else iq=i-1;
      }
    for (i=0;i<=nn-1;i++)
      { b[i]=0.0;
        for (j=0;j<=mm-1;j++)
          { k=m*(ip+i)+(iq+j);
            h=z[k];
            for (k=0;k<=mm-1;k++)
              if (k!=j)
                h=h*(v-y[iq+k])/(y[iq+j]-y[iq+k]);
            b[i]=b[i]+h;
          }
      }
    w=0.0;
    for (i=0;i<=nn-1;i++)
      { h=b[i];
        for (j=0;j<=nn-1;j++)
          if (j!=i)
            h=h*(u-x[ip+j])/(x[ip+i]-x[ip+j]);
        w=w+h;
      }
    return(w);
  }

 