#include <stdio.h>
#include <stdlib.h>

void countingSort(int a[],int n,int max){
    int count[50]={0},i,j;
    
    for(i=0;i<n;i++){
        count[a[i]]++;//以值當索引，索引下為值累計出現次數
    }
    
    printf("\nSorted elements are:");
    
    for(i=0;i<=max;i++){
        for(j=1;j<=count[i];j++){
            printf("%d ",i);
        }
    }
}

main(void){
    int a[50],n,i,max=0;
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("\nEnter elements:");

    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]>max){
            max=a[i];
        }
    }

    countingSort(a,n,max);

    system("pause");

}