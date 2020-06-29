

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
  #include "pdisk.c"
  #include "qdbsh.c"
  main()
  { FILE *fp;
    long int n,k,m;
    static struct student a[10]=
           {{"101" ,"Zhang","M" ,"19" ,"095.6"},
            {"102" ,"Wang" ,"F" ,"18" ,"092.4"},
            {"103" ,"Zhao" ,"M" ,"19" ,"085.7"},
            {"104" ,"Li"   ,"M" ,"20" ,"096.3"},
	    {"105" ,"Gou"  ,"M" ,"19" ,"090.2"},
            {"106" ,"Lin"  ,"M" ,"18" ,"091.5"},
            {"107" ,"Ma"   ,"F" ,"17" ,"098.7"},
            {"108" ,"Zhen" ,"M" ,"21" ,"090.1"},
            {"109" ,"Xu"   ,"M" ,"19" ,"089.8"},
            {"110" ,"Mao"  ,"F" ,"18" ,"094.9"}};
    int i,j,mm0,*mm=&mm0;
    char cc[7],dd[7],*c=cc,*d=dd;
    fp=fopen("student.dat","w+");
    for (i=0; i<=9; i++)
      if (fwrite(&a[i],sizeof(stu),1,fp)!=1)
        printf("file write error\n");
    fclose(fp);
    if ((fp=fopen("student.dat","r+"))==NULL)
      { printf("cannot open this file\n"); exit(0);}
    for (i=0; i<=9; i++)
      { fread(&a[i],sizeof(stu),1,fp);
        printf("%-10s%-10s%-5s%-5s%-8s\n",a[i].num,
               a[i].name,a[i].sex,a[i].age,a[i].score);
      }
    printf("\n");
    n=10; k=0; m=9;
    pdisk(fp,n,k,m);
    fseek(fp,0L,0);
    for(i=0; i<=9; i++)
      { fread(&a[i],sizeof(stu),1,fp);
        printf("%-10s%-10s%-5s%-5s%-8s\n",a[i].num,
               a[i].name,a[i].sex,a[i].age,a[i].score);
      }
    printf("\n");
    c="095"; d="100";
    i=qdbsh(fp,10,c,d,mm);
    for (j=i; j<=i+mm0-1; j++)
      { fseek(fp,j*sizeof(stu),0);
        fread(&a[j],sizeof(stu),1,fp);
        printf("p(%d)=  %-10s%-10s%-5s%-5s%-8s\n",
                j,a[j].num,a[j].name,a[j].sex,a[j].age,
                  a[j].score);
      }
    printf("\n");
    fclose(fp);
  }

