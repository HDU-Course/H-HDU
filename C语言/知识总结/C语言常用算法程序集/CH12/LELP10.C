
  #include "stdio.h"
  #include "lelp1.c"
  main()
  { int i;
    double f,k,y;
    printf("\n");
    for (i=0; i<=10; i++)
      { f=i*3.1415926/18.0;
        k=0.5; y=lelp1(k,f);
        printf("F(%4.2f, %8.6f)=%e    ",k,f,y);
        k=1.0; y=lelp1(k,f);
        printf("F(%4.2f, %8.6f)=%e\n",k,f,y);
      }
    printf("\n");
  }

