
  #include "stdlib.h"
  #include "stdio.h"
  #include "math.h"
  void thzlb(num,flag,n,fn1,fn2,fn3)
  char *fn1,*fn2,*fn3;
  int num,flag,n;
  { FILE *fp1,*fp2,*fp3;
    int code,i,j,m,x,y,kk;
    long int k;
    unsigned char *p,*q,*qq;
    void pch();
    void p_q();
    kk=(num+1)*(num+1)*8;
    p=malloc(kk*sizeof(unsigned char));
    q=malloc(kk*sizeof(unsigned char));
    qq=malloc(kk*4*sizeof(unsigned char));
    if ((fp1=fopen(fn1,"r+b"))==NULL)
      { printf("cannot open fn1 !\n");
        exit(0);
      }
    if ((fp2=fopen(fn2,"w+b"))==NULL)
      { printf("cannot open fn2 !\n");
        exit(0);
      }
    if ((fp3=fopen(fn3,"r+t"))==NULL)
      { printf("cannot open fn3 !\n");
        exit(0);
      }
    if ((flag<1)||(flag>4)) flag=1;
    i=0;
    while (fscanf(fp3,"%d",&code)!=EOF)
      { j=code;
        y=j/100;
        x=j-y*100;
        if ((flag%2!=0)&&(y>=7)) 
            m=(y-7)*94+(x-1);
        else  m=(y-1)*94+(x-1);
        k=(long)m*(long)kk;
        fseek(fp1,k*sizeof(char),SEEK_SET);
        if (flag<=2)
           fread(q,sizeof(char),kk,fp1);
        else
          { fread(p,sizeof(char),kk,fp1);
            pch(num,p,q);
          }
        k=(long)i*(long)kk;
        if (n!=0)
          { p_q(num+1,q,qq);
            fseek(fp2,k*4*sizeof(char),SEEK_SET);
            fwrite(qq,sizeof(char),kk*4,fp2);
          }
        else
          { fseek(fp2,k*sizeof(char),SEEK_SET);
	    fwrite(q,sizeof(char),kk,fp2);
          }
	i=i+1;
      }
    fclose(fp1); fclose(fp2); fclose(fp3);
    free(p); free(q); free(qq);
    return;
  }

  static void pch(num,p,q)
  unsigned char p[],q[];
  int num;
  { int  i,j,k,m,n,l,ii,jj;
    unsigned char tt,d[8]={128,64,32,16,8,4,2,1};
    jj=(num+1)*8;
    ii=jj*(num+1);
    for (i=0;  i<=ii-1;  i++)  q[i]=(char)0;
    for (l=0;  l<=num; l++)
      { n=0; k=0;
        for  (i=0; i<=jj-1; i++)
          { for (j=0; j<=7;  j++)
              { m=n+(num+1)*j+l; tt=d[j];
                if ((p[i+jj*l]&tt)!=(unsigned char)0)
                  { tt=d[k]; q[m]=q[m]|tt;}
              }
            n=n+jj;
            if  (n==ii) n=0;
            if  (((i+1)%(num+1))==0) k=k+1;
            if  (k==8) k=0;
          }
      }
    return;
  }

  static void p_q(n,p,q)
  int n;
  unsigned char p[],q[];
  { int i,j;
    unsigned char s,t;
    for (i=0; i<=n*8-1; i++)
      for (j=0; j<=n-1; j++)
        { t=p[n*i+j];
          q[n*4*i+2*j]=t;
          q[n*4*i+2*j+n*2]=t;
        }
    for (i=0; i<=n*16-1; i++)
      for (j=0; j<=n*2-1; j=j+2)
        { t=q[n*2*i+j]; s=0;
          if ((t&128)!=0) s=s|192;
          if ((t&64)!=0)  s=s|48;
          if ((t&32)!=0)  s=s|12;
          if ((t&16)!=0)  s=s|3;
          q[n*2*i+j]=s; s=0;
          if ((t&8)!=0) s=s|192;
          if ((t&4)!=0) s=s|48;
          if ((t&2)!=0) s=s|12;
          if ((t&1)!=0) s=s|3;
          q[n*2*i+j+1]=s;
        }
    return;
  }

