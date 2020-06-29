#include <stdio.h>
int d[];//全局变量，用来存放分解结果 
void decompose(int m,int n,int k, int j);
//全局函数，起分解作用，将m分解为不大于n的组成数，k>=0 
int main()
{
	int j,n;
	printf("请输入整数n\n");
	scanf("%d",&n);
	j=n;//将n赋值给j，使j等于初值 
    decompose(n,n,0,j);
	return 0;
}
void decompose(int m,int n,int k,int j)
{
	int i;
	if(m==0)
	{
		printf("%d=",j);
		printf("%d",d[0]);//输出"n=" 
		for(i=1;i<k;i++)//设置输出格式 
		printf("+%d",d[i]);
		printf("\n");
	}
	for(i=m<n?m:n;i>0;i--)//一次分解的几种可能分法 
	{
		if(i<n)
		d[k]=i;
		else
		d[k]=n;
		decompose(m-d[k],d[k],k+1,j);//继续分解，直到得到一个划分 
	}		
}   
