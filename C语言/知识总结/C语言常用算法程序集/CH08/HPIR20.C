
  #include "math.h"
  #include "stdio.h"
  #include "hpir2.c"
  main()
  { int i,j;
    double x[11],y[21],z[11][21],a[6][5],dt[3];
    for (i=0; i<=10; i++) x[i]=0.2*i;
    for (i=0; i<=20; i++) y[i]=0.1*i;
    for (i=0; i<=10; i++)
      for (j=0; j<=20; j++)
        z[i][j]=exp(x[i]*x[i]-y[j]*y[j]);
    hpir2(x,y,z,11,21,a,6,5,dt);
    printf("\n");
    printf("MAT A(i,j) IS:\n");
    for (i=0; i<=5; i++)
      { for (j=0; j<=4; j++)
          printf("%e  ",a[i][j]);
        printf("\n");
      }
    printf("\n");
    for (i=0; i<=2; i++)
      printf("dt(%2d)=%e  ",i,dt[i]);
    printf("\n");
  }

