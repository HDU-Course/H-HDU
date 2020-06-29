
  #include "math.h"
  int dpqrt(x,eps)
  double *x,eps;
  { extern double dpqrtf();
    int i,j,m,it,l;
    double a[10],y[10],z,h,x0,q;
    l=10; q=1.0e+35; x0=*x; h=0.0;
    while (l!=0)
      { l=l-1; j=0; it=l;
        while (j<=7)
           { if (j<=2) z=x0+0.1*j;
             else z=h;
             y[j]=dpqrtf(z);
             h=z;
             if (j==0) a[0]=z;
             else
               { m=0; i=0;
                 while ((m==0)&&(i<=j-1))
                   { if (fabs(h-a[i])+1.0==1.0) m=1;
                     else h=(y[j]-y[i])/(h-a[i]);
                     i=i+1;
                   }
                 a[j]=h;
                 if (m!=0) a[j]=q;
                 h=0.0;
                 for (i=j-1; i>=0; i--)
                   { if (fabs(a[i+1]+h)+1.0==1.0) h=q;
                     else h=-y[i]/(a[i+1]+h);
                   }
                 h=h+a[0];
               }
             if (fabs(y[j])>=eps) j=j+1;
             else { j=10; l=0;}
           }
         x0=h;
       }
     *x=h;
     return(10-it);
   }

