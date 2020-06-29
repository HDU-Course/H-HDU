
  #define STRU struct student
  #define KEY name
  STRU
    { int num;
      char name[8];
      char sex;
      int age;
      double score;
    }
  #include "stdio.h"
  #include "qhsch.c"
  main()
  { int i,q;
    char aa[8],bb[8],*a=aa,*b=bb;
    static STRU p[10]={{101,"Zhang",'M',19,95.6},
    {102,"Wang",'F',18,92.4},{103,"Zhao",'M',19,85.7},
    {104,"Li",'M',20,96.3},{105,"Gou",'M',19,90.2},
    {106,"Lin",'M',18,91.5},{107,"Ma",'F',17,98.7},
    {108,"Zhen",'M',21,90.1},{109,"Xu",'M',19,89.8},
    {110,"Mao",'F',18,94.9}};
    a="Zhen"; b=a;
    i=0;
    printf("\n");
    do
      { q=qhsch(p,i,9,a,b);
	if (q!=-1)
          printf("%-5d%-10s%-4c%-6d%-7.2f\n",p[q].num,
             p[q].name,p[q].sex,p[q].age,p[q].score);
        i=q+1;
      }
    while (q!=-1);
    printf("\n");
  }

