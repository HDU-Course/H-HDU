
  #include "string.h"
  void pdisk(fp,n,k,m)
  FILE *fp;
  long int n,k,m;
  { long int i,j,kk;
    char t[sizeof(STU.KEY)],*w,*getkey();
    void sp();
    if (k<0L) k=0;
    if (m>n-1L) m=n-1;
    i=k; j=m; kk=(long)(i+j)/2;
    w=getkey(fp,kk);
    strcpy(t,w);
    do
      { w=getkey(fp,i);
        while ((strcmp(w,t)<0)&&(i<=j))
          { i=i+1; w=getkey(fp,i);}
        w=getkey(fp,j);
        while ((strcmp(w,t)>0)&&(i<=j))
          { j=j-1; w=getkey(fp,j);}
        if (i<=j) {sp(fp,i,j); i=i+1; j=j-1;}
      }
    while (i<=j);
    if (k<j) pdisk(fp,n,k,j);
    if (i<m) pdisk(fp,n,i,m);
    return;
  }

  #include "stdio.h"
  static char *getkey(fp,rec)
  FILE *fp;
  long int rec;
  { long int i,k;
    k=sizeof(STU);
    fseek(fp,rec*k,0);
    fread(&STU,k,1,fp);
    return(STU.KEY);
  }

  #include "stdio.h"
  static void sp(fp,i,j)
  FILE *fp;
  long int i,j;
  { long int k,l;
    char p[sizeof(STU)],q[sizeof(STU)];
    l=sizeof(STU);
    fseek(fp,l*i,0);
    for (k=0; k<l; k++) p[k]=getc(fp);
    fseek(fp,l*j,0);
    for (k=0; k<l; k++) q[k]=getc(fp);
    fseek(fp,l*j,0);
    for (k=0; k<l; k++) putc(p[k],fp);
    fseek(fp,l*i,0);
    for (k=0; k<l; k++) putc(q[k],fp);
    return;
  }

