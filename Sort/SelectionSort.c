#include <stdio.h>
#include <stdlib.h>

main(void){

    int n,a[30];

    printf("Selection sort\n");
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    printf("\nEnter the elements\n");

    for(int i=0;i<n;i++){
        printf("%d th data: ",i+1);
        scanf("%d",&a[i]);
    }

    for(int i=0;i<n-1;i++){ // (n-1) : the last is max
        int min = a[i];
        int minindex;
        for(int j=i+1;j<n;j++){
            if(a[j]<min){
                min = a[j];
                minindex = j;
            }
        }
        int temp = a[i];
        a[i]=min;
        a[minindex]=temp;
    }

    printf("\nSorted list: \n\n");

    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    system("pause");
}
