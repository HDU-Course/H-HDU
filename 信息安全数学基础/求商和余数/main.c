#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,i=0,m,n;
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
    }
    m=a%b;
    n=(a-m)/b;
    printf("%d=%d*%d+%d\n",a,b,n,m);
    return 0;
}
