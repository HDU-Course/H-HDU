
  #include "math.h"
  void isqt3(n,k,x,f1,f2,eps,xx,b,v,s,dt,ye,yr,r)
  int n,k;
  double f1,f2,eps,x[],xx[],b[],v[],s[],dt[],ye[],yr[],r[];
  { int i,j,ii,m,imi,imx,l,it;
    double z,phi,sd,vmi,vmx,q,fmi,fmx;
    m=n+1; q=0.0;
    for (j=0; j<=n; j++)
      { z=0.0;
        for (i=0; i<=k-1; i++)
          z=z+x[i*m+j]/k;
        xx[j]=z;
      }
    for (i=0; i<=n; i++)
      for (j=0; j<=i; j++)
        { z=0.0;
          for (ii=0; ii<=k-1; ii++)
            z=z+(x[ii*m+i]-xx[i])*(x[ii*m+j]-xx[j]);
          r[i*m+j]=z;
        }
    for (i=0; i<=n; i++)
      ye[i]=sqrt(r[i*m+i]);
    for (i=0; i<=n; i++)
      for (j=0; j<=i; j++)
        { r[i*m+j]=r[i*m+j]/(ye[i]*ye[j]);
          r[j*m+i]=r[i*m+j];
        }
    phi=k-1.0;
    sd=ye[n]/sqrt(k-1.0);
    it=1;
    while (it==1)
      { it=0;
        vmi=1.0e+35; vmx=0.0;
        imi=-1; imx=-1;
        for (i=0; i<=n; i++)
          { v[i]=0.0; b[i]=0.0; s[i]=0.0;}
        for (i=0; i<=n-1; i++)
          if (r[i*m+i]>=eps)
            { v[i]=r[i*m+n]*r[n*m+i]/r[i*m+i];
              if (v[i]>=0.0)
                { if (v[i]>vmx)
                    { vmx=v[i]; imx=i;}
                }
              else
                { b[i]=r[i*m+n]*ye[n]/ye[i];
                  s[i]=sqrt(r[i*m+i])*sd/ye[i];
                  if (fabs(v[i])<vmi)
                    { vmi=fabs(v[i]); imi=i;}
                }
            }
        if (phi!=n-1.0)
          { z=0.0;
            for (i=0; i<=n-1; i++)
              z=z+b[i]*xx[i];
            b[n]=xx[n]-z; s[n]=sd; v[n]=q;
          }
        else
          { b[n]=xx[n]; s[n]=sd;}
        fmi=vmi*phi/r[n*m+n];
        fmx=(phi-1.0)*vmx/(r[n*m+n]-vmx);
        if ((fmi<f2)||(fmx>=f1))
          { if (fmi<f2)
              { phi=phi+1.0; l=imi;}
            else
              { phi=phi-1.0; l=imx;}
            for (i=0; i<=n; i++)
              if (i!=l)
                for (j=0; j<=n; j++)
                  if (j!=l)
                    r[i*m+j]=r[i*m+j]-
                             (r[l*m+j]/r[l*m+l])*r[i*m+l];
            for (j=0; j<=n; j++)
              if (j!=l)
                r[l*m+j]=r[l*m+j]/r[l*m+l];
            for (i=0; i<=n; i++)
              if (i!=l)
                r[i*m+l]=-r[i*m+l]/r[l*m+l];
            r[l*m+l]=1.0/r[l*m+l];
            q=r[n*m+n]*ye[n]*ye[n];
            sd=sqrt(r[n*m+n]/phi)*ye[n];
            dt[0]=sqrt(1.0-r[n*m+n]);
            dt[1]=(phi*(1.0-r[n*m+n]))/
		  ((k-phi-1.0)*r[n*m+n]);
            it=1;
          }
      }
    for (i=0; i<=k-1; i++)
      { z=0.0;
        for (j=0; j<=n-1; j++)
          z=z+b[j]*x[i*m+j];
        ye[i]=b[n]+z; yr[i]=x[i*m+n]-ye[i];
      }
    return;
  }

