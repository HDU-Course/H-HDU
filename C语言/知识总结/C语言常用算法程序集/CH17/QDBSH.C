
  #include "string.h"
  int qdbsh(fp,n,a,b,m)
  int *m,n;
  FILE *fp;
  char a[],b[];
  { long int i,j,k;
    int jj;
    char *w,*get();
    i=1; j=n;
    while (i<=j)
      { k=(i+j)/2; w=get(fp,k-1L);
        if ((strcmp(w,a)>=0)&&(strcmp(w,b)<=0))
	  { i=k-1; j=0; w=get(fp,i);
            while ((i>=0)&&(strcmp(w,a)>=0))
		{ i=i-1; j=j+1; w=get(fp,i);}
	    i=i+1; w=get(fp,k);
            while ((k<=n-1)&&(strcmp(w,b)<=0))
		{ k=k+1; j=j+1; w=get(fp,k);}
            *m=j; jj=i; return(jj);
          }
        if (strcmp(w,b)>0) j=k-1;
        else i=k+1;
      }
    w=get(fp,i);
    while ((i>=0)&&(strcmp(b,w)<0))
      { i=i-1; w=get(fp,i);}
    i=i+1; *m=0; jj=i;
    return(jj);
  }

  #include "stdio.h"
  static char *get(fp,rec)
  FILE *fp;
  long int rec;
  { long int i,k;
    k=sizeof(STU);
    fseek(fp,rec*k,0);
    fread(&STU,k,1,fp);
    return(STU.KEY);
  }

