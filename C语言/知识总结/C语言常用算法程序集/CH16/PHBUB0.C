
  #include "stdio.h"
  #include "phbub.c"
  main()
  { int i;
    static char *p[10]={"main","gou","zhao","lin","wang",
                        "zhang","li","zhen","ma","sub"};
    printf("\n");
    for (i=0; i<=9; i++)
      printf("%s , ",p[i]);
    printf("\n");
    phbub(p,10,0,9);
    printf("\n");
    for (i=0; i<=9; i++)
      printf("%s , ",p[i]);
    printf("\n");
    printf("\n");
  }

