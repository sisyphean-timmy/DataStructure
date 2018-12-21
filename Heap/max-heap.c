#include <stdio.h>
#include <stdlib.h>
    
void adjust(int* tree,int ptr,int length);
void creatHeap(int *tree,int length);
int insert(int value,int* tree,int length);
int deletemax(int* tree,int length);


main(void){
    
    int length;
    int tree[6];

    printf("\n\nInput data amount(max is 5) to build max-heap?\n");
    scanf("%d",&length);
    fflush(stdin);

    if(length<=5){

        for(int i=1;i<=length;i++){
            printf("%dth data:\n",i);
            scanf("%d",&tree[i]);
            fflush(stdin);
        }

        creatHeap(tree,length);
        print(tree,length);

        while(1){
            int select;
            printf("\n\n Do something ? \n (0) insert data to heap\n (1) delete max form heap\n");
            scanf("%d",&select);
            switch(select){
                case 0:
                    if(length<5){
                        int value;
                        printf("Insert value?\n");
                        scanf("%d",&value);
                        length = insert(value,tree,length);
                    }else{
                        printf("heap array is full!\n");
                    }
                    break;
                case 1:
                    length = deletemax(tree,length);
                    break;
                default:
                    printf("err format\n");
            }
        }
    }

}

void adjust(int* tree,int ptr,int length){
    int temp= tree[ptr];//preserve the parent
    int leftchild = ptr*2;
    while(leftchild<=length){//has child
        if(leftchild+1<=length){//has right child
            if(tree[leftchild+1]>tree[leftchild]){// select the max(right child) to replace leftchild
                leftchild=leftchild+1;
            }
        }
        if(tree[leftchild]<temp){//tree[ptr] is the tree's max 
            break; 
        }else{//leftchild is bigger than tree[ptr]
            tree[leftchild/2]=tree[leftchild];//leftchild replace parent
            leftchild*=2;//deepper tree
        }
    }
    tree[leftchild/2]=temp;//when whileloop end leftchild has been power 2
}

void creatHeap(int *tree,int length){
    int i = length/2;
    while(i>0){
        adjust(tree,i,length);
        i--;
    }
    printf("\nMax-Heap Builded !\n");
}

void print(int* tree,int length){
    printf("\nHeap tree content:");
    for(int i=1;i<=length;i++){
        printf("%d=>%d  ",i,tree[i]);
    }
}

int insert(int value,int* tree,int length){
    length++;
    tree[length]=value;
    creatHeap(tree,length);
    print(tree,length);
    return length;
}

int deletemax(int* tree,int length){
    int max=tree[1];
    int lastNode = tree[length];
    length--;
    tree[1]=lastNode;
    creatHeap(tree,length);
    printf(" delete max : %d\n",max);
    print(tree,length);
    return length;
}
