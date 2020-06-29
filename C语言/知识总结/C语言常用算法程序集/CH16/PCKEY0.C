
  #define HEAPSORT struct student
  #define KEY sex
  HEAPSORT
    { int num;
      char name[8];
      char sex;
      int age;
      double score;
    }
  #include "stdio.h"
  #include "pckey.c"
  main()
  { int i;
    static HEAPSORT stu[10]={{101,"Zhang",'M',19,95.6},
    {102,"Wang",'F',18,92.4},{103,"Zhao",'M',19,85.7},
    {104,"Li",'M',20,96.3},{105,"Gou",'M',19,90.2},
    {106,"Lin",'M',18,91.5},{107,"Ma",'F',17,98.7},
    {108,"Zhen",'M',21,90.1},{109,"Xu",'M',19,89.8},
    {110,"Mao",'F',18,94.9}};
    HEAPSORT *p[10];
    for (i=0; i<=9; i++) p[i]=&stu[i];
    printf("\n");
    printf("No.     Name     Sex     Age     Score\n");
    for (i=0; i<=9; i++)
      printf("%-8d%-9s%-8c%-8d%-5.2f\n",
             (*p[i]).num,(*p[i]).name,(*p[i]).sex,
             (*p[i]).age,(*p[i]).score);
    printf("\n");
    pckey(p,10,1,8);
    printf("No.     Name     Sex     Age     Score\n");
    for (i=0; i<=9; i++)
      printf("%-8d%-9s%-8c%-8d%-5.2f\n",
             (*p[i]).num,(*p[i]).name,(*p[i]).sex,
             (*p[i]).age,(*p[i]).score);
    printf("\n");
  }

