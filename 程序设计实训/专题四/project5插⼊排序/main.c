#include <stdio.h>
#include <stdlib.h>
void Subsequence(int*, int);

int main() {
    int arraylength,count,tally;
    int *p;
    printf("输入的array的长度:");
    scanf("%d", &arraylength);
    p = (int*)malloc(sizeof(int)*arraylength);
    printf("输入array的元素:");
    for(count=0; count<arraylength; count++)
        scanf("%d",p+count);
    for (count=0; count<arraylength; count++){
        Subsequence(p,count);
        printf("第%d次处理后:",count+1);
        for(tally=0; tally<arraylength; tally++)
            printf("%d ",*(p+tally));
        printf("\n");
    }
    free(p);
}

void Subsequence(int *p,int count){
    int tem;
    while(*(p+count)<*(p+count-1)&&count>0){
        tem = *(p+count);
        *(p+count) = *(p+count-1);
        *(count+p-1) = tem;
        count--;
    }
}
