
  #include "stdio.h"
  #include "lffff.c"
  #include "lbeta.c"
  #include "lgam1.c"
  main()
  { int n1,n2,i;
    double y,f;
    static int n[2]={ 2,5};
    static int m[2]={ 3,10};
    printf("\n");
    for (i=0; i<=1; i++)
      { n1=n[i]; n2=m[i]; f=3.5;
        y=lffff(f,n1,n2);
        printf("P(%4.2f, %d, %d)=%e\n",f,n1,n2,y);
        f=9.0; y=lffff(f,n1,n2);
        printf("P(%4.2f, %d, %d)=%e\n",f,n1,n2,y);
      }
    printf("\n");
  }

