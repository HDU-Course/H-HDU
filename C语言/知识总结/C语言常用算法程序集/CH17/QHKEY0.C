
  #define HEAPSORT struct student
  #define KEY name
  #define BISERCH struct student
  struct student
    { int num;
      char name[8];
      char sex;
      int age;
      double score;
    }
  #include "stdio.h"
  #include "qhkey.c"
  #include "phkey.c"
  main()
  { int i,m0,*m,j;
    BISERCH *p[10];
    static BISERCH stu[10]={{101,"Zhang",'M',19,95.6},
    {102,"Wang",'F',18,92.4},{103,"Zhao",'M',19,85.7},
    {104,"Li",'M',20,96.3},{105,"Gou",'M',19,90.2},
    {106,"Lin",'M',18,91.5},{107,"Ma",'F',17,98.7},
    {108,"Zhen",'M',21,90.1},{109,"Xu",'M',19,89.8},
    {110,"Mao",'F',18,94.9}};
    m=&m0;
    for (i=0; i<=9; i++) p[i]=&stu[i];
    phkey(p,10,0,9);
    printf("\n");
    for (i=0; i<=9; i++)
      printf("%-8d%-9s%-8c%-8d%-5.2f\n",
             (*p[i]).num,(*p[i]).name,(*p[i]).sex,
             (*p[i]).age,(*p[i]).score);
    printf("\n");
    i=qhkey(p,10,"Z","Zzzzzz",m);
    printf("m=%d\n",m0);
    printf("i=%d\n",i);
    for (j=i; j<=i+m0-1; j++)
      printf("p(%d)=  %-8d%-9s%-8c%-8d%-5.2f\n",j,
             (*p[j]).num,(*p[j]).name,(*p[j]).sex,
             (*p[j]).age,(*p[j]).score);
    printf("\n");
  }

