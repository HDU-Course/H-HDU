
  #include "stdio.h"
  #include "pcshl.c"
  main()
  { char *s;
    static char p[]={'a','s','t','b','x','e','f','h','i',
    'g','p', 'q','a','i','f','j','c','b','a','z','y','x'};
    s=p+2;
    printf("\n");
    printf("%s\n",p);
    printf("\n");
    pcshl(s,17);
    printf("%s\n",p);
    printf("\n");
  }

