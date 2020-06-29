#include<graphics.h>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#define PI  M_PI
void Koch(int x1,int y1,int x2,int y2,int n)
{
    int x3=(x2-x1)/3+x1;
    int y3=(y2-y1)/3+y1;
    int x4=(x2-x1)*2/3+x1;
    int y4=(y2-y1)*2/3+y1;
    int x5 = x3 + ((x2 - x1) - (y2 - y1)*sqrt(3)) / 6;
 	int y5 = y3 + ((x2 - x1)*sqrt(3) + (y2 - y1)) / 6;
 	n=n+1;
 	if(n==3)
    {
        moveto(x1,y1);
        lineto(x3,y3);
        lineto(x5,y5);
        lineto(x4,y4);
        lineto(x2,y2);
        return;
    }
    Koch(x1,y1,x3,y3,n);
    Koch(x3, y3, x5, y5, n);
 	Koch(x5, y5, x4, y4, n);
 	Koch(x4, y4, x2, y2, n);
}
int main() {
 	int x1, x2, x3, y1, y2, y3;
 	int n = 0;
 	initgraph(1000,1000);
 	setcolor(GREEN);
 	x1 = 200;
 	y1 = 180;
 	x2 = 400;
 	y2 = 180;
 	x3 = 300;
 	y3 = 180 + 200 * sqrt(3) / 2;
 	moveto(x1, y1);
    Koch(x1, y1, x3, y3, n);
    Koch(x3, y3, x2, y2, n);
    Koch(x2, y2, x1, y1, n);
    getch();
}
