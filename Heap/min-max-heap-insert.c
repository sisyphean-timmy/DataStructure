#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Algorithm pesudo
if i is on a min-level then
    if i has a parent cand A[i] > A[parent(i)] then
        swap A[i] and A[parent(i)]
        BubbleUpMax(parent(i))
    else
        BubbleUpMin(i)
else
    if i has a parent cand A[i] < A[parent(i)] then
        swap A[i] and A[parent(i)]
        BubbleUpMin(parent(i))
    else
        BubbleUpMax(i)

BubbleUpMin(i)
    if A[i] has grandparent then
        if A[i] < A[grandparent(i)] then
        swap A[i] and A[grandparent(i)]
        BubbleUpMin(grandparent(i))
*/

int isminlevel(int x){
    int lg = log2(x);
    if(lg%2==0){//is min-heap
        return 1;
    }else{
        return 0;//is max-heap
    }
}

void minadjust(int* tree,int i){
    if(i/4!=0){//has grandparent
        if(tree[i/4]>tree[i]){
            int temp = tree[i/4];
            tree[i/4]=tree[i];
            tree[i]=temp;
        }
        minadjust(tree,i/4);
    }
}

void maxadjust(int* tree,int i){
    if(i/4!=0){//has grandparent
        if(tree[i/4]<tree[i]){
            int temp = tree[i/4];
            tree[i/4]=tree[i];
            tree[i]=temp;
        }
        maxadjust(tree,i/4);
    }
}

void print(int* tree,int length){
    printf("\nMin-Max-Heap tree content:");
    for(int i=1;i<=length;i++){
        printf("%d=>%d  ",i,tree[i]);
    }
}

int insert(int value,int* tree,int i){
    tree[i] = value;
    int temp = tree[i];
    if(isminlevel(i)){
        if(tree[i/2]<tree[i]){
            tree[i]=tree[i/2];
            tree[i/2]=temp;
            maxadjust(tree,i/2);
        }else{
            minadjust(tree,i);
        }
    }else{
        if(tree[i/2]>tree[i]){
            tree[i]=tree[i/2];
            tree[i/2]=temp;
            minadjust(tree,i/2);
        }else{
            maxadjust(tree,i);
        }
    }
    return i;
}

main(void){
    
    int length;
    int tree[16];

    printf("\n\nInput data amount(max is 15) to build main-max-heap?\n");
    scanf("%d",&length);
    fflush(stdin);

    if(length<=15){

        for(int i=1;i<=length;i++){
            printf("%dth data:\n",i);
            scanf("%d",&tree[i]);
            fflush(stdin);
        }

        for(int i=1;i<=length;i++){
            insert(tree[i],tree,i);
        }
        
        print(tree,length);
        
    }
    system("pause");
}
