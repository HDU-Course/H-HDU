
  #define STU stu
  #define KEY score
  #define MUDISK struct student
  MUDISK
    { char num[5];
      char name[8];
      char sex[3];
      char age[4];
      char KEY[7];
    } STU;
  #include "stdio.h"
  #include "pdisk.c"
  main()
  { FILE *fp;
    long int n,k,m;
    MUDISK b[10];
    static MUDISK a[10]=
           {{"101","Zhang","M","19","95.6"},
            {"102","Wang" ,"F","18","92.4"},
            {"103","Zhao" ,"M","19","85.7"},
            {"104","Li"   ,"M","20","96.3"},
	    {"105","Gou"  ,"M","19","90.2"},
            {"106","Lin"  ,"M","18","91.5"},
            {"107","Ma"   ,"F","17","98.7"},
            {"108","Zhen" ,"M","21","90.1"},
            {"109","Xu"   ,"M","19","89.8"},
            {"110","Mao"  ,"F","18","94.9"}};
    int i;
    fp=fopen("student.dat","w+");
    for (i=0; i<=9; i++)
      if (fwrite(&a[i],sizeof(stu),1,fp)!=1)
        printf("file write error\n");
    fclose(fp);
    if ((fp=fopen("student.dat","r+"))==NULL)
      { printf("cannot open this file\n"); exit(0);}
    for (i=0; i<=9; i++)
      { fread(&b[i],sizeof(stu),1,fp);
        printf("%-10s%-10s%-5s%-5s%-8s\n",b[i].num,
               b[i].name,b[i].sex,b[i].age,b[i].score);
      }
    printf("\n");
    n=10; k=1; m=8;
    pdisk(fp,n,k,m);
    fseek(fp,0L,0);
    for(i=0; i<=9; i++)
      { fread(&b[i],sizeof(stu),1,fp);
        printf("%-10s%-10s%-5s%-5s%-8s\n",b[i].num,
               b[i].name,b[i].sex,b[i].age,b[i].score);
      }
    printf("\n");
    fclose(fp);
  }

