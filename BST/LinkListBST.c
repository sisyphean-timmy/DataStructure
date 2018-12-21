#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* leftchild;
    struct node* rightchild;
};

typedef struct node Node;

Node* root = NULL;

void cbst(int data);

main(void) {


    int data[9]={5,6,4,8,2,3,7,1,9};

    for(int i =0;i<9;i++){
        cbst(data[i]);
    }

    system("pause");

}

void cbst(int data){
    Node* newnode = (Node*) malloc(sizeof(Node));
    if(newnode==NULL){
        printf("\nerr malloc\n");
        system("pause");
    }else{
        newnode->data = data;
        newnode->leftchild = NULL;
        newnode->rightchild = NULL;
        if(root==NULL){
            root = newnode;
        }else{
            Node* temp=root;
            while(1){
                if(newnode->data>temp->data){//right child
                    if(temp->rightchild==NULL){
                        temp->rightchild=newnode;
                        break;
                    }else{
                        temp=temp->rightchild;
                    }
                }else{//left child
                    if(temp->leftchild==NULL){
                        temp->leftchild=newnode;
                        break;
                    }else{
                        temp=temp->leftchild;
                    }
                }
            }
        }
    }
}