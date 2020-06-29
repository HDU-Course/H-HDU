
  double eslgq(x,y,z,n,m,u,v)
  int n,m;
  double x[],y[],z[],u,v;
  { int ip,ipp,i,j,l,iq,iqq,k;
    double h,w,b[10];
    if (u<=x[0]) { ip=1; ipp=4;}
    else if (u>=x[n-1]) { ip=n-3; ipp=n;}
    else
      { i=1; j=n;
        while (((i-j)!=1)&&((i-j)!=-1))
          { l=(i+j)/2;
            if (u<x[l-1]) j=l;
            else i=l;
          }
        ip=i-3; ipp=i+4;
      }
    if (ip<1) ip=1;
    if (ipp>n) ipp=n;
    if (v<=y[0]) { iq=1; iqq=4;}
    else if (v>=y[m-1]) { iq=m-3; iqq=m;}
    else
      { i=1; j=m;
        while (((i-j)!=1)&&((i-j)!=-1))
          { l=(i+j)/2;
            if (v<y[l-1]) j=l;
            else i=l;
          }
        iq=i-3; iqq=i+4;
      }
    if (iq<1) iq=1;
    if (iqq>m) iqq=m;
    for (i=ip-1;i<=ipp-1;i++)
      { b[i-ip+1]=0.0;
        for (j=iq-1;j<=iqq-1;j++)
          { h=z[m*i+j];
            for (k=iq-1;k<=iqq-1;k++)
              if (k!=j) h=h*(v-y[k])/(y[j]-y[k]);
            b[i-ip+1]=b[i-ip+1]+h;
          }
      }
    w=0.0;
    for (i=ip-1;i<=ipp-1;i++)
      { h=b[i-ip+1];
        for (j=ip-1;j<=ipp-1;j++)
          if (j!=i) h=h*(u-x[j])/(x[i]-x[j]);
        w=w+h;
      }
    return(w);
  }

