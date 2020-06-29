
  #include "math.h"
  #include "stdio.h"
  int dsrrt(a,n,xr,xi)
  int n;
  double a[],xr[],xi[];
  { int m,i,jt,k,is,it;
    double t,x,y,x1,y1,dx,dy,p,q,w,dd,dc,c;
    double g,u,v,pq,g1,u1,v1;
    void g60();
    void g65();
    void g90();
    m=n;
    while ((m>0)&&(fabs(a[m])+1.0==1.0)) m=m-1;
    if (m<=0)
      { printf("fail\n"); return(-1);}
    for (i=0; i<=m; i++)
      a[i]=a[i]/a[m];
    for (i=0; i<=m/2; i++)
      { w=a[i]; a[i]=a[m-i]; a[m-i]=w;}
    k=m; is=0; w=1.0;
    jt=1;
    while (jt==1)
      { pq=fabs(a[k]);
	while (pq<1.0e-12)
          { xr[k-1]=0.0; xi[k-1]=0.0; k=k-1;
            if (k==1)
              { xr[0]=-a[1]*w/a[0]; xi[0]=0.0;
                return(1);
              }
            pq=fabs(a[k]);
          }
	q=log(pq); q=q/(1.0*k); q=exp(q);
        p=q; w=w*p;
        for (i=1; i<=k; i++)
          { a[i]=a[i]/q; q=q*p;}
        x=0.0001; x1=x; y=0.2; y1=y; dx=1.0;
        g=1.0e+37; 
        l40:
        u=a[0]; v=0.0;
        for (i=1; i<=k; i++)
          { p=u*x1; q=v*y1;
            pq=(u+v)*(x1+y1);
            u=p-q+a[i]; v=pq-p-q;
          }
        g1=u*u+v*v;
        if (g1>=g)
          { if (is!=0)
              { it=1;
                g65(&x,&y,&x1,&y1,&dx,&dy,&dd,&dc,&c,
                    &k,&is,&it);
                if (it==0) goto l40;
              }
            else
              { g60(&t,&x,&y,&x1,&y1,&dx,&dy,&p,&q,
                    &k,&it);
                if (t>=1.0e-03) goto l40;
                if (g>1.0e-18)
                  { it=0;
                    g65(&x,&y,&x1,&y1,&dx,&dy,&dd,&dc,&c,
                        &k,&is,&it);
                    if (it==0) goto l40;
                  }
              }
            g90(xr,xi,a,&x,&y,&p,&q,&w,&k);
          }
        else
          { g=g1; x=x1; y=y1; is=0;
            if (g<=1.0e-22)
	      g90(xr,xi,a,&x,&y,&p,&q,&w,&k);
            else
              { u1=k*a[0]; v1=0.0;
                for (i=2; i<=k; i++)
                  { p=u1*x; q=v1*y; pq=(u1+v1)*(x+y);
                    u1=p-q+(k-i+1)*a[i-1];
                    v1=pq-p-q;
                  }
                p=u1*u1+v1*v1;
                if (p<=1.0e-20)
                  { it=0;
                    g65(&x,&y,&x1,&y1,&dx,&dy,&dd,&dc,&c,
                        &k,&is,&it);
                    if (it==0) goto l40;
                    g90(xr,xi,a,&x,&y,&p,&q,&w,&k);
                  }
                else
                  { dx=(u*u1+v*v1)/p;
                    dy=(u1*v-v1*u)/p;
                    t=1.0+4.0/k;
                    g60(&t,&x,&y,&x1,&y1,&dx,&dy,&p,&q,
                        &k,&it);
                    if (t>=1.0e-03) goto l40;
                    if (g>1.0e-18)
                      { it=0;
                        g65(&x,&y,&x1,&y1,&dx,&dy,&dd,&dc,
                            &c,&k,&is,&it);
                        if (it==0) goto l40;
                      }
                    g90(xr,xi,a,&x,&y,&p,&q,&w,&k);
                  }
              }
          }
        if (k==1) jt=0;
        else jt=1;
      }
    return(1);
  }

  #include "math.h"
  static void g60(t,x,y,x1,y1,dx,dy,p,q,k,it)
  int *k,*it;
  double *t,*x,*y,*x1,*y1,*dx,*dy,*p,*q;
  { *it=1;
    while (*it==1)
      { *t=*t/1.67; *it=0;
        *x1=*x-(*t)*(*dx);
        *y1=*y-(*t)*(*dy);
        if (*k>=50)
	  { *p=sqrt((*x1)*(*x1)+(*y1)*(*y1));
            *q=exp(85.0/(*k));
            if (*p>=*q) *it=1;
          }
      }
    return;
  }

  #include "math.h"
  static void g90(xr,xi,a,x,y,p,q,w,k)
  int *k;
  double *x,*y,*p,*q,*w;
  double xr[],xi[],a[];
  { int i;
    if (fabs(*y)<=1.0e-06)
      { *p=-(*x); *y=0.0; *q=0.0;}
    else
      { *p=-2.0*(*x); *q=(*x)*(*x)+(*y)*(*y);
        xr[*k-1]=(*x)*(*w);
        xi[*k-1]=-(*y)*(*w);
        *k=*k-1;
      }
    for (i=1; i<=*k; i++)
      { a[i]=a[i]-a[i-1]*(*p);
        a[i+1]=a[i+1]-a[i-1]*(*q);
      }
    xr[*k-1]=(*x)*(*w); xi[*k-1]=(*y)*(*w);
    *k=*k-1;
    if (*k==1)
      { xr[0]=-a[1]*(*w)/a[0]; xi[0]=0.0;}
    return;
  }

  #include "math.h"
  static void g65(x,y,x1,y1,dx,dy,dd,dc,c,k,is,it)
  int *k,*is,*it;
  double *x,*y,*x1,*y1,*dx,*dy,*dd,*dc,*c;
  { if (*it==0)
      { *is=1;
        *dd=sqrt((*dx)*(*dx)+(*dy)*(*dy));
        if (*dd>1.0) *dd=1.0;
        *dc=6.28/(4.5*(*k)); *c=0.0;
      }
    while(1==1)
      { *c=*c+(*dc);
        *dx=(*dd)*cos(*c); *dy=(*dd)*sin(*c);
        *x1=*x+*dx; *y1=*y+*dy;
        if (*c<=6.29)
          { *it=0; return;}
        *dd=*dd/1.67;
        if (*dd<=1.0e-07)
          { *it=1; return;}
        *c=0.0;
      }
  }

