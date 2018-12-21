#include <stdio.h>
#include <stdlib.h>

//BST
struct node{
    int data;
    struct node* leftchild;
    struct node* rightchild;
};

typedef struct node Node;

//BST Name manage
struct BSTS{
    char name;
    Node* root;
    struct BSTS* next;
};
typedef struct BSTS tree;

tree* rear = NULL;

void CreatTree(char name){
    tree* newtree = (tree*)malloc(sizeof(tree));
    if(newtree!=NULL){
        if(rear==NULL){
            rear = newtree;
            newtree->name = name;
            newtree->root = NULL;
            newtree->next = newtree;
        }else{
            newtree->next = rear->next;
            rear->next = newtree;
            newtree->name = name;
            newtree->root = NULL;
            rear = newtree;
        }
        printf("Creat tree %c ...\n",name);
    }else{
        printf("\nerr malloc\n");
    }
}

tree* SelectTree(char select){
    tree* ptr = rear->next;
    while(1){
        if(ptr->name==select){
            return ptr;
        }else{
            if(ptr==rear){break;}
            ptr=ptr->next;
        }
    }
    return NULL;
}

void Insert(int value,char Select){
    tree* ptr = SelectTree(Select);
    if(ptr!=NULL){
        Node* newnode = (Node*) malloc(sizeof(Node));
        if(newnode!=NULL){
            newnode->data = value;
            newnode->leftchild = NULL;
            newnode->rightchild = NULL;
            if(ptr->root==NULL){
                ptr->root = newnode; // !!
            }else{
                Node* temp=ptr->root;
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
            printf("Inset %d to tree'%c'\n",value,Select);
        }else{
            printf("\nerr malloc\n");
        }
    }else{ // select() return NULL
        printf("%c is not exist you need to creat the tree\n",Select);    
    }
}
