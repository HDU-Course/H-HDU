
  #include "string.h"
  int qdsch(fp,a,b)
  FILE *fp;
  char a[],b[];
  { long int k;
    int q,jt;
    k=sizeof(STU); jt=1;
    while (jt==1)
      { if (fread(&STU,k,1,fp)==NULL)
          { q=0; jt=0;}
        else
          { if ((strcmp(STU.KEY,a)>=0)&&
               (strcmp(STU.KEY,b)<=0)) {jt=0; q=1;}
          }
      }
    return(q);
  }
    
