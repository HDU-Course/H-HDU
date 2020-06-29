#include<stdio.h>
#include<stdlib.h>


long Maxinum(int c,int d)
    {
        int m=1;
        m=c%d;
        if(m!=0)
        return Maxinum(d,m);
        else
        return d;
    }
int main()
{
    int a=0,b=0,i=0;
    printf(" ‰»Îa\n");
    scanf("%d",&a);
    printf(" ‰»Îb\n");
    scanf("%d",&b);
    if(a<0)
        a=-a;
    if(b<0)
        b=-b;
    if(a<b)
    {
        i=a;
        a=b;
        b=i;
        printf("(%d,%d)=%d",b,a,Maxinum(a,b));
    }
    else
        printf("d=(%d,%d)=%d",a,b,Maxinum(a,b));
    return 0;
}
