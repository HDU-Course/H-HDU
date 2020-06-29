#include <stdio.h>
#include <stdlib.h>
int RemoveDuplicates(int *, int);

int main() {
    int nScores,count;
    int *score;
    printf("输入array的长度:");
    scanf("%d", &nScores);
    printf("输入array的元素:\n");
    score = (int *)malloc(sizeof(int)*nScores);
    for(count=0; count<nScores; count++)
        scanf("%d", score+count);
    nScores = RemoveDuplicates(score, nScores);
    printf("处理后的数组长度:%d\n", nScores);
    printf("经过处理后的数组:\n");
    for(count=0; count<nScores; count++)
        printf("%d ", *(score+count));
    free(score);
}

int RemoveDuplicates(int *scores, int nScores){
    int *p;
    int count,tally,length,flag;
    length=0;
    p = (int *)malloc(sizeof(int)*nScores);
    for(count=0; count<nScores; count++){
        flag = 0;
        for(tally=0; tally<length; tally++){
            if(*(scores+count)==*(p+tally)){
                flag = 1;
                break;
            }
        }
        if(flag==0){
            *(p+length) = *(scores+count);
            length++;
        }
    }
    nScores = length;
    for(count=0; count<nScores; count++)
        *(scores+count) = *(p+count);
    free(p);
    return nScores;
}
