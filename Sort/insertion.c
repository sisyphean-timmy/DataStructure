#include <stdio.h>
#include <stdlib.h>

main(void){

    int i,j,n,temp,a[30];

    printf("Insertion sort\n");
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    printf("\nEnter the elements\n");

    for(i=0;i<n;i++){
        printf("%d th data: ",i+1);
        scanf("%d",&a[i]);
    }

    for(i=1;i<n;i++){
        j= i-1;
        while(j>=0&&a[j]>a[i]){
            a[j+1]=a[j]; // a[i]=>a[i-1]
            j=j-1;
        }
        a[i]=temp;
    }

    printf("\nSorted list: \n\n");

    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    system("pause");
}