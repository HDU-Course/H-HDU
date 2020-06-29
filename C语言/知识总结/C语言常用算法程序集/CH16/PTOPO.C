
  #include "stdlib.h"
  void ptopo(n,r,m,p)
  int n,m,p[],r[];
  { int top,i,j,k,t,*s,*g,*f;
    struct node
      { int suc;
        int next;
      } *q;
    q=(struct node *)malloc(m*sizeof(struct node));
    f=malloc(n*sizeof(int));
    s=malloc(n*sizeof(int));
    g=malloc(n*sizeof(int));
    top=-1; t=0;
    for (k=0; k<=n-1; k++) { f[k]=0; g[k]=-1;}
    for (k=0; k<=m-1; k++)
      { i=r[k+k]; j=r[k+k+1];
        f[j-1]=f[j-1]+1;
        q[k].next=g[i-1]; q[k].suc=j; g[i-1]=k;
      }
    for (k=0; k<=n-1; k++)
      if (f[k]==0) { top=top+1; s[top]=k+1;}
    while (top!=-1)
      { i=s[top]; top=top-1; p[t]=i; t=t+1;
        k=g[i-1];
        while (k!=-1)
        { j=q[k].suc; f[j-1]=f[j-1]-1;
          if (f[j-1]==0) { top=top+1; s[top]=j;}
          k=q[k].next;
        }
      }
    for (k=0; k<=n-1; k++)
      if (f[k]!=0) { p[t]=-(k+1); t=t+1;}
    free(f); free(g); free(s); free(q);
    return;
  }

