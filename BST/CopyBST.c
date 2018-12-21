#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

void Copytree(char a);
Node* CopySub(Node* sour);

main(void) {
    CreatTree('a');
    int data[9]={5,6,4,8,2,3,7,1,9};

    for(int i =0;i<9;i++){
        Insert(data[i],'a');
    }
    Copytree('a');
    
    system("pause");

}

Node* CopySub(Node* sour){
    if(sour==NULL){
        return NULL;
    }else{
        Node* newnode = (Node*)malloc(sizeof(Node));
        if(newnode!=NULL){
            newnode->data = sour->data;
            printf("Copy %d ...\n",newnode->data);
            newnode->leftchild= CopySub(sour->leftchild);
            newnode->rightchild= CopySub(sour->rightchild);
            return newnode;
        }
    }
    
}

void Copytree(char a){
    if(SelectTree(a)!=NULL){
        char b;
        printf("New tree's name of 'a' copy to?\n");
        scanf("%c",&b);
        CreatTree(b);
        SelectTree(b)->root = CopySub(SelectTree(a)->root);
    }
}