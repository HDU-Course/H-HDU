
  #include "math.h"
  #include "stdlib.h"
  #include "string.h"
  int qfkmp(fp,p)
  FILE *fp;
  char p[];
  { int i,j,k,jt,*flink;
    char s;
    void qflink();
    k=strlen(p);
    flink=malloc(k*sizeof(int));
    qflink(p,k,flink);
    i=0; j=0;
    jt=1;
    if ((s=fgetc(fp))==EOF) jt=0;
    while (jt==1)
      { while ((j!=-1)&&(p[j]!=s)) j=flink[j];
        if (j!=k-1) 
          { j=j+1; i=i+1;
            if ((s=fgetc(fp))==EOF) { jt=0; i=0;}
          }
        else { i=1; jt=0;}
      }
    free(flink); return(i);
  }
         
  static void qflink(p,k,flink)
  int flink[],k;
  char p[];
  { int i,j;
    flink[0]=-1; i=1;
    while (i<=k-1)
      { j=flink[i-1];
        while ((j!=-1)&&(p[j]!=p[i-1])) j=flink[j];
        flink[i]=j+1;
        i=i+1;
      }
    return;
  }
 
