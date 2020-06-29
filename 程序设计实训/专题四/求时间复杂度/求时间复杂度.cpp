#include <iostream>
using namespace std;
#define n 2
int main()
{
	int i,j,k;
	int al=0,bl=0,cl=0,sum=0;
	int a[n][n];
	int b[n][n];
	int c[n][n];
	cout<<" n= "<<n<<endl;
	cout<<" cin a[n][n] "<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];bl++;
		}
		al++;
	}
	sum=al+bl;
	al=0,bl=0;
	cout<<" cin b[n][n] "<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>b[i][j];bl++;
		}
		al++;
	}
	sum=sum+al+bl;
	al=0;bl=0;
	cout<<" cout c[n][n] "<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			c[i][j]=0;
			for(k=0;k<n;k++)
			{
				c[i][j]=c[j][j]+a[i][k]*b[k][j];cl++;
			}
			bl++;
		}
		al++;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<c[i][j]<<endl;bl++;
		}
		al++;
	}
    sum=sum+al+bl+cl;
    al=0,bl=0,cl=0;
    sum=sum+17;
    cout<<" 共执行了: "<<sum<<"次 "<<endl;
	return 0;
}
