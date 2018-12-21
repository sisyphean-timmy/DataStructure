#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main(void){

    int i,n,a[30];

    printf("Shell sort\n");
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    printf("\nEnter the elements\n");

    for(i=0;i<n;i++){
        printf("%d th data: ",i+1);
        scanf("%d",&a[i]);
    }
    
    int span = (int)ceil(n/2.);
    int temp;
    while(1){
        for(i=0;i<n-span;i++){
            if(a[i]>a[i+span]){
                temp = a[i];
                a[i]= a[i+span];
                a[i+span] = temp;
            }
        }
        if(span==1){break;}
        span = (int)ceil(span/2.);
    }

    printf("\nSorted list: \n\n");

    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    system("pause");
}