#include<iostream>
#include<stdio.h>
using namespace std;
#define StartX 1
#define StartY 1
#define EndX   8
#define EndY   8
int TraceRoute (int a[][10],int i,int j){
     //1.用2标记当前的点已经走过
     a[i][j]=2;
     //2.标记是否结束,end=0表示还未到终点
     int end=0;
     if(i==EndX&&j==EndY){end=1;}//到达终点，用end=1标记 
     //3.路线选择，共有4种走法
     if(end!=1&&j+1<= EndY &&a[i][j+1]==1) //往东走 
            {if(TraceRoute(a,i,j+1)==1) return 1;}
     if(end!=1&&i+1<= EndX &&a[i+1][j]==1)  //往南走 
            {if(TraceRoute(a,i+1,j)==1) return 1;}
     if(end!=1&&j-1>= StartY &&a[i][j-1]==1)  //往西走 
            {if(TraceRoute(a,i,j-1)==1) return 1;}
     if(end!=1&&i-1>= StartX &&a[i-1][j]==1)  //往北走 
            {if(TraceRoute(a,i-1,j)==1) return 1;} 
     if(end!=1){a[i][j]=1;}
	  //4.如果走到了死胡同并且没有到达终点，走不通,将当前点还原为1
     return end;
}
int main(){
        int a[10][10] = {
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
            { 0, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
            { 0, 1, 1, 1, 1, 0, 0, 1, 1, 0 },
            { 0, 1, 0, 0, 0, 1, 1, 1, 1, 0 },
            { 0, 1, 1, 1, 0, 1, 1, 1, 1, 0 },
            { 0, 1, 0, 1, 1, 1, 0, 1, 1, 0 },
            { 0, 1, 0, 0, 0, 1, 0, 0, 1, 0 },
            { 0, 0, 1, 1, 1, 1, 1, 1, 1, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    };
    for (int i = 0; i <= 9; i++)
	{
        for (int j = 0; j <= 9; j++)
		{
            cout << a[i][j] << " ";
        }
        cout << endl;
    }//输出原始路径 
    cout << endl;
    TraceRoute(a,StartX,StartY);
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }//输出行走过的路径 
    system("pause");
    return 0;
}
