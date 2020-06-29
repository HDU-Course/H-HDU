#include<iostream>
#include<cstdio>
int s[1000];
int t[1000];
int q[1000];
int r[1000];
using namespace std;
int main()
{
    int a,b;
    printf("input a and b:\n");
    while(cin >> a)
    {
        cin >> b;
        printf("j   q[j]   r[j]  r[j+1]  s[j-1]  s[j]  t[j-1]  t[j]\n");
        s[0] = 1, s[1] = 0;
        t[0] = 0, t[1] = 1;
        r[0] = a,r[1] = b;
        q[1] = r[0] / r[1];
        r[2] = r[0] % r[1];
        printf("%d  %5d  %5d  %5d  %5d  %5d  %5d  %5d\n",1,q[1],r[1],r[1+1],s[1-1],s[1],t[1-1],t[1]);
        if(r[2] == 0) continue;
        r[3] = r[1] % r[2];
        int j = 2;
        while(1)
        {
            q[j] = r[j - 1] / r[j];
            r[j + 1] = r[j - 1] % r[j];
            s[j] = s[j - 2] - (q[j - 1] * s[j - 1]);
            t[j] = t[j - 2] - (q[j - 1] * t[j - 1]);
            printf("%d  %5d  %5d  %5d  %5d  %5d  %5d  %5d\n",j,q[j],r[j],r[j+1],s[j-1],s[j],t[j-1],t[j]);
            if(r[j + 1] == 0)  break;
            j++;
        }
    }
    return 0;
}
