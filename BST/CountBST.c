#include <stdio.h>
#include <stdlib.h>
#include "BST.h"


void CountNode(char a);
int CountNodeSub(Node* ptr);

void CountLevel(char a);
int CountLevelSub(Node* ptr);

void CountLeaf(char a);
int CountLeafSub(Node* ptr);

main(void) {

    CreatTree('a');
    int data_a[9]={5,6,4,8,2,3,7,1,9};
    for(int i =0;i<9;i++){
        Insert(data_a[i],'a');
    }

    CreatTree('b');
    int data_b[9]={5,6,4,8,2,3,7,1,9};
    for(int i =0;i<9;i++){
        Insert(data_b[i],'b');
    }

    CreatTree('c');
    int data_c[7]={5,6,4,3,7,1,9};
    for(int i =0;i<7;i++){
        Insert(data_c[i],'c');
    }
    
    while(1){
        int select;
        char paramenter;
        printf("\n*********start********\n\n");
        printf("There are 'a' 'b' 'c' trees above, \n(0)Get the Node amount\n(1)Get the tree level\n(2)Get the tree leaf\n");
        scanf("%d",&select);
        fflush(stdin);
        switch(select){
            case 0:
                printf("which one?\n");
                scanf("%c",&paramenter);
                fflush(stdin);
                CountNode(paramenter);
                break;
            case 1:
                printf("which one?\n");
                scanf("%c",&paramenter);
                fflush(stdin);
                CountLevel(paramenter);
                break;
            case 2:
                printf("which one?\n");
                scanf("%c",&paramenter);
                fflush(stdin);
                CountLeaf(paramenter);
                break;
            default:
                printf("err format \n");
        }
        printf("\n\n*********end********\n");
    }

    system("pause");

}

void CountNode(char a){
    tree* target = SelectTree(a);
    if(target==NULL){
        printf("Three is not exist");
    }else{
        int res = CountNodeSub(target->root);
        printf("\nthe tree's node amount is %d\n",res);
    }
}

int CountNodeSub(Node* ptr){
    if(ptr==NULL){
        return 0;
    }else{
        return CountNodeSub(ptr->leftchild)+CountNodeSub(ptr->rightchild)+1;
    }
}

void CountLevel(char a){
    tree* target = SelectTree(a);
    if(target==NULL){
        printf("Three is not exist");
    }else{
        int res = CountLevelSub(target->root);
        printf("\nthe tree's Level is %d\n",res);
    }
}

int CountLevelSub(Node* ptr){
    if(ptr==NULL){
        return 0;
    }else{
        int l = CountLevelSub(ptr->leftchild);
        int r = CountLevelSub(ptr->rightchild);
        if(l>r){
            return l+1;
        }else{//l<=r
            return r+1;
        }
    }
}

void CountLeaf(char a){
    tree* target = SelectTree(a);
    if(target==NULL){
        printf("Three is not exist");
    }else{
        int res = CountLeafSub(target->root);
        printf("\nthe tree's Leaf is %d\n",res);
    }
}
int CountLeafSub(Node* ptr){
    if(ptr==NULL){
        return 0;
    }else if(ptr->rightchild==NULL&&ptr->leftchild==NULL){
        return 1;
    }else{
        int l = CountLeafSub(ptr->leftchild);
        int r = CountLeafSub(ptr->rightchild);
        return l+r;
    }
}