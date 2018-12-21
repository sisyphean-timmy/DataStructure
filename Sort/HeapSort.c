#include<stdio.h>
#include<stdlib.h>

void bottomup_adjust(int* heap,int i){
    int len = heap[0];
    while(i*2<=len){//heas child
        int j = i*2;
        if(j+1<=len && heap[j]<heap[j+1]){//has right
            j=j+1; // swap right and left
        }
        if(heap[j]<heap[i]){
            break;
        }else{
            int temp = heap[i];
            heap[i]= heap[j];
            heap[j]= temp;
            i*=2; 
        }
    }
}
void createheap(int* heap){
    int i = heap[0]/2; // call bottom-up adjust by lastparent
    while(i>0){
        bottomup_adjust(heap,i);
        i--;
    }
}

main(void){

    int i,n;
    int heap[30];

    printf("Heap sort\n");
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    printf("\nEnter the elements\n");
    
    for(i=1;i<=n;i++){
        printf("%d th data: ",i);
        scanf("%d",&heap[i]);
    }

    heap[0]=n; //for store the length

    createheap(heap);

    /*Sorting : move max to last then length-- then adjust heap*/
    while(heap[0]>0){   
        int last = heap[0];
        int temp = heap[last];
        heap[last] = heap[1];
        heap[1] = temp;

        heap[0]--;
        createheap(heap); // or bottomup_adjust(heap,1)
    }

    printf("\nSorted list: \n\n");

    for(i=1;i<=n;i++){
        printf("%d ",heap[i]);
    }

    system("pause");
}