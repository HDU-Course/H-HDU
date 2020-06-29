
  #include "stdio.h"
  #include "qfkmp.c"
  main()
  { FILE *fp;
    int i,j,jt;
    char pp[8],*p=pp;
    printf("\n");
    p="abcd";
    if ((fp=fopen("abc","r"))==NULL)
      { printf("cannot open this file\n");
        exit(0);
      }
    jt=1; j=0;
    while (jt==1)
      { i=qfkmp(fp,p);
        if (i!=0) j=j+1;
        else jt=0;
      }
    printf("sum=%d\n",j);
    printf("\n");
    fclose(fp);
  }

