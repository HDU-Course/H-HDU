
  #include "math.h"
  void jmaxn(x,n,eps,k,js)
  int n,k,js[];
  double eps,x[];
  { extern double jmaxnf();
    int i,j,m,l,jt,il;
    double y[10],b[10],p,z,t,h1,h2,f,dx;
    js[0]=0; jt=1; h2=0.0;
    while (jt==1)
      { t=0.0; js[0]=js[0]+1;
        for (i=1; i<=n; i++)
          { f=jmaxnf(x,n,i);
            t=t+fabs(f);
          }
        if (t<eps) jt=0;
        else
          { for (i=0; i<=n-1; i++)
              { il=5;
                while (il!=0)
                  { j=0; t=x[i]; il=il-1;
                    while (j<=7)
                      { if (j<=2) z=t+j*0.01;
                        else z=h2;
                        x[i]=z;
                        f=jmaxnf(x,n,i+1);
                        if (fabs(f)+1.0==1.0)
                          { j=10; il=0;}
                        else
                          { h1=f; h2=z;
                            if (j==0)
                              { y[0]=h1; b[0]=h2;}
                            else
                              { y[j]=h1; m=0; l=0;
                                while ((m==0)&&(l<=j-1))
                                    { p=h2-b[l];
                                      if (fabs(p)+1.0==1.0) m=1;
                                      else h2=(h1-y[l])/p;
                                      l=l+1;
                                    }
                                b[j]=h2;
                                if (m!=0) b[j]=1.0e+35;
                                h2=0.0;
                                for (l=j-1; l>=0; l--)
                                  h2=-y[l]/(b[l+1]+h2);
                                h2=h2+b[0];
                              }
                            j=j+1;
                          }
                      }
                    x[i]=h2; 
                  }
                x[i]=z;
              }
            if (js[0]==k) jt=0;
          }
      }
    js[1]=1;
    f=jmaxnf(x,n,0); x[n]=f;
    dx=0.00001; t=x[0];
    x[0]=t+dx; h1=jmaxnf(x,n,0);
    x[0]=t-dx; h2=jmaxnf(x,n,0);
    x[0]=t;
    t=h1+h2-2.0*f;
    if (t>0.0) js[1]=-1;
    j=1; jt=1;
    while (jt==1)
      { j=j+1; dx=0.00001; jt=0;
        t=x[j-1];
        x[j-1]=t+dx; h2=jmaxnf(x,n,0);
        x[j-1]=t-dx; h1=jmaxnf(x,n,0);
        x[j-1]=t; t=h1+h2-2.0*f;
        if ((t*js[1]<0.0)&&(j<n)) jt=1;
      }
    if (t*js[1]>0.0) js[1]=0;
    return;
  }

