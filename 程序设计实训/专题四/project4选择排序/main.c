#include <stdio.h>
#define con 13

int removeZeroElement(int* array, int n);

int main(){
    int array[con];
    int i,nscore;
    for(i=0; i<con; i++)
        scanf("%d",&array[i]);
    nscore = removeZeroElement(array, con);
    printf("%d\n",nscore);
    for(i=0; i<nscore; i++)
        printf("%d ",array[i]);
}

int removeZeroElement(int* array,int n){
    int i,j,ncount=0;
    for(i=0; i<n; i++)
        if(*(array+i)==0)
            ncount++;
    for(i=0; i<n-ncount; i++){
        if(*(array+i)==0)
            for(j=1; j<n-i; j++){
                if(*(array+i+j)!=0){
                    *(array+i) = *(array+i+j);
                    *(array+i+j) = 0;
                    break;
                }
            }
    }
    return (n-ncount);
}

