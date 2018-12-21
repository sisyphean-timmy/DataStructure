#include <stdio.h>
#include <stdlib.h>

main(void){

    int i,n,a[30];

    printf("Bubble sort\n");
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    printf("\nEnter the elements\n");

    for(i=0;i<n;i++){
        printf("%d th data: ",i+1);
        scanf("%d",&a[i]);
    }

    int temp;
    int flag = 1;
    int rounds = n-1;
    while(flag==1){
        flag=0; // initial flag if any round without swap will make the while loop stop(sort finishing)
        for(i=0;i<rounds;i++){
            if(a[i]>a[i+1]){
                temp = a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                flag=1;
            }
        }
        rounds--;//the last of array will be max after a round
    }

    printf("\nSorted list: \n\n");

    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    system("pause");
}