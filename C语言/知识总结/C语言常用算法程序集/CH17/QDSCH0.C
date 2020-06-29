
  #define STU stu
  #define KEY score
  struct student
    { char num[5];
      char name[8];
      char sex[3];
      char age[4];
      char score[7];
    } STU;
  #include "stdio.h"
  #include "qdsch.c"
  main()
  { int i;
    char aa[7],*a=aa,bb[7],*b=bb;
    FILE *fp;
    static struct student p[10]=
          {{"101","Zhang","M","19","095.6"},
           {"102","Wang" ,"F","18","092.4"},
           {"103","Zhao" ,"M","19","085.7"},
           {"104","Li"   ,"M","20","096.3"},
           {"105","Gou"  ,"M","19","090.2"},
           {"106","Lin"  ,"M","18","091.5"},
           {"107","Ma"   ,"F","17","098.7"},
           {"108","Zhen" ,"M","21","090.1"},
           {"109","Xu"   ,"M","19","089.8"},
           {"110","Mao"  ,"F","18","094.9"}};
    a="090.0"; b="100.0";
    fp=fopen("stu.dat","w+");
    for (i=0; i<=9; i++)
      if (fwrite(&p[i],sizeof(stu),1,fp)!=1)
        printf("file write error\n");
    fclose(fp);
    fp=fopen("stu.dat","r+");
    printf("\n");
    i=1;
    do
      { i=qdsch(fp,a,b);
	if (i!=0)
          printf("%-10s%-10s%-5s%-5s%-8s\n",stu.num,
             stu.name,stu.sex,stu.age,stu.score);
      }
    while (i!=0);
    printf("\n");
    fclose(fp);
  }

