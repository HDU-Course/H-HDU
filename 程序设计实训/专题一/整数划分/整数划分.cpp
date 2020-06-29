#include <iostream>

using namespace std;

int mark[100];//记录分解情况
int n;
void divide(int nowNumber, int k, int preNumber);//划分函数声明 

int main()
{
	cin>>n;
	divide(0, 0, n-1);

	return 0;
}

//now用来记录当前值判断当前大小与n的关系，k记录递归次数， pre记录前一个值
void divide(int nowNumber, int k, int preNumber)
{
    int i;
//当前值大于n就返回，递归结束 
    if(nowNumber > n)
    {
         return;
    }
//当前值与n相等，递归结束；按照递归次数i，输出划分结果 
    if (nowNumber == n)
    {
        cout<<n<<"=";
        for(i = 0; i < k - 1; i++)
		{
        	cout<<mark[i]<<"+";
        }
        	cout<<mark[i]<<endl;
    }
    
     else//(nowNumber < n)
    {
        for(i = preNumber; i > 0;)//以n为6为例，i=5
        { 
                mark[k] = i; 
				// mark[0]=5 //mark[1]=4 break; //mark[1]=3 break.....
				
                nowNumber += i;
				// now=5 //now=4 //now=3
				
                divide(nowNumber, k + 1, i); 
				// (5,1,5)>>> k=1 >>>now=10>n break // (4,2,4)>>> k=2 >>> now=8>n break //
				
                nowNumber -= i;// now=0 // now=0
                
            	i--;//i=4 //i=3 //
        }
    }
}
