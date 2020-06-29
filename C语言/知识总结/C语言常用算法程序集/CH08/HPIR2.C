
  #include "stdlib.h"
  #include "math.h"
  void hpir2(x,y,z,n,m,a,p,q,dt)
  int n,m,p,q;
  double x[],y[],z[],a[],dt[];
  { int i,j,k,l,kk;
    double apx[20],apy[20],bx[20],by[20],u[20][20];
    double t[20],t1[20],t2[20],xx,yy,d1,d2,g,g1,g2;
    double x2,dd,y1,x1,*v;
    v=malloc(20*m*sizeof(double));
    for (i=0; i<=p-1; i++)
      { l=i*q;
        for (j=0; j<=q-1; j++) a[l+j]=0.0;
      }
    if (p>n) p=n;
    if (p>20) p=20;
    if (q>m) q=m;
    if (q>20) q=20;
    xx=0.0;
    for (i=0; i<=n-1; i++)
      xx=xx+x[i]/(1.0*n);
    yy=0.0;
    for (i=0; i<=m-1; i++)
      yy=yy+y[i]/(1.0*m);
    d1=1.0*n; apx[0]=0.0;
    for (i=0; i<=n-1; i++)
      apx[0]=apx[0]+x[i]-xx;
    apx[0]=apx[0]/d1;
    for (j=0; j<=m-1; j++)
      { v[j]=0.0;
        for (i=0; i<=n-1; i++)
          v[j]=v[j]+z[i*m+j];
        v[j]=v[j]/d1;
      }
    if (p>1)
      { d2=0.0; apx[1]=0.0;
        for (i=0; i<=n-1; i++)
          { g=x[i]-xx-apx[0];
            d2=d2+g*g;
            apx[1]=apx[1]+(x[i]-xx)*g*g;
          }
        apx[1]=apx[1]/d2;
        bx[1]=d2/d1;
        for (j=0; j<=m-1; j++)
          { v[m+j]=0.0;
            for (i=0; i<=n-1; i++)
              { g=x[i]-xx-apx[0];
                v[m+j]=v[m+j]+z[i*m+j]*g;
              }
            v[m+j]=v[m+j]/d2;
          }
        d1=d2;
      }
    for (k=2; k<=p-1; k++)
      { d2=0.0; apx[k]=0.0;
        for (j=0; j<=m-1; j++) v[k*m+j]=0.0;
        for (i=0; i<=n-1; i++)
          { g1=1.0; g2=x[i]-xx-apx[0];
            for (j=2; j<=k; j++)
              { g=(x[i]-xx-apx[j-1])*g2-bx[j-1]*g1;
                g1=g2; g2=g;
              }
            d2=d2+g*g;
            apx[k]=apx[k]+(x[i]-xx)*g*g;
            for (j=0; j<=m-1; j++)
              v[k*m+j]=v[k*m+j]+z[i*m+j]*g;
          }
        for (j=0; j<=m-1; j++)
          v[k*m+j]=v[k*m+j]/d2;
        apx[k]=apx[k]/d2;
        bx[k]=d2/d1;
        d1=d2;
      }
    d1=m; apy[0]=0.0;
    for (i=0; i<=m-1; i++)
      apy[0]=apy[0]+y[i]-yy;
    apy[0]=apy[0]/d1;
    for (j=0; j<=p-1; j++)
      { u[j][0]=0.0;
        for (i=0; i<=m-1; i++)
	  u[j][0]=u[j][0]+v[j*m+i];
	u[j][0]=u[j][0]/d1;
      }
    if (q>1)
      { d2=0.0; apy[1]=0.0;
        for (i=0; i<=m-1; i++)
          { g=y[i]-yy-apy[0];
            d2=d2+g*g;
            apy[1]=apy[1]+(y[i]-yy)*g*g;
          }
        apy[1]=apy[1]/d2;
        by[1]=d2/d1;
        for (j=0; j<=p-1; j++)
	  { u[j][1]=0.0;
            for (i=0; i<=m-1; i++)
              { g=y[i]-yy-apy[0];
		u[j][1]=u[j][1]+v[j*m+i]*g;
              }
	    u[j][1]=u[j][1]/d2;
          }
        d1=d2;
      }
    for (k=2; k<=q-1; k++)
      { d2=0.0; apy[k]=0.0;
	for (j=0; j<=p-1; j++) u[j][k]=0.0;
        for (i=0; i<=m-1; i++)
          { g1=1.0;
            g2=y[i]-yy-apy[0];
            for (j=2; j<=k; j++)
              { g=(y[i]-yy-apy[j-1])*g2-by[j-1]*g1;
                g1=g2; g2=g;
              }
            d2=d2+g*g;
            apy[k]=apy[k]+(y[i]-yy)*g*g;
            for (j=0; j<=p-1; j++)
	      u[j][k]=u[j][k]+v[j*m+i]*g;
          }
        for (j=0; j<=p-1; j++)
	  u[j][k]=u[j][k]/d2;
        apy[k]=apy[k]/d2;
        by[k]=d2/d1;
        d1=d2;
      }
    v[0]=1.0; v[m]=-apy[0]; v[m+1]=1.0;
    for (i=0; i<=p-1; i++)
      for (j=0; j<=q-1; j++)
        a[i*q+j]=0.0;
    for (i=2; i<=q-1; i++)
      { v[i*m+i]=v[(i-1)*m+(i-1)];
        v[i*m+i-1]=-apy[i-1]*v[(i-1)*m+i-1]+v[(i-1)*m+i-2];
        if (i>=3)
          for (k=i-2; k>=1; k--)
            v[i*m+k]=-apy[i-1]*v[(i-1)*m+k]+
                     v[(i-1)*m+k-1]-by[i-1]*v[(i-2)*m+k];
        v[i*m]=-apy[i-1]*v[(i-1)*m]-by[i-1]*v[(i-2)*m];
      }
    for (i=0; i<=p-1; i++)
      { if (i==0) { t[0]=1.0; t1[0]=1.0;}
        else
          { if (i==1)
              { t[0]=-apx[0]; t[1]=1.0;
                t2[0]=t[0]; t2[1]=t[1];
              }
            else
              { t[i]=t2[i-1];
                t[i-1]=-apx[i-1]*t2[i-1]+t2[i-2];
                if (i>=3)
                  for (k=i-2; k>=1; k--)
                    t[k]=-apx[i-1]*t2[k]+t2[k-1]
                         -bx[i-1]*t1[k];
                t[0]=-apx[i-1]*t2[0]-bx[i-1]*t1[0];
                t2[i]=t[i];
                for (k=i-1; k>=0; k--)
                  { t1[k]=t2[k]; t2[k]=t[k];}
              }
          }
        for (j=0; j<=q-1; j++)
          for (k=i; k>=0; k--)
            for (l=j; l>=0; l--)
	      a[k*q+l]=a[k*q+l]+u[i][j]*t[k]*v[j*m+l];
      }
    dt[0]=0.0; dt[1]=0.0; dt[2]=0.0;
    for (i=0; i<=n-1; i++)
      { x1=x[i]-xx;
        for (j=0; j<=m-1; j++)
          { y1=y[j]-yy;
            x2=1.0; dd=0.0;
            for (k=0; k<=p-1; k++)
              { g=a[k*q+q-1];
                for (kk=q-2; kk>=0; kk--)
                  g=g*y1+a[k*q+kk];
                g=g*x2; dd=dd+g; x2=x2*x1;
              }
            dd=dd-z[i*m+j];
            if (fabs(dd)>dt[2]) dt[2]=fabs(dd);
            dt[0]=dt[0]+dd*dd;
            dt[1]=dt[1]+fabs(dd);
          }
      }
    free(v);
    return;
  }

