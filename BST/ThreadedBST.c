#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* leftchild;
    struct node* rightchild;
    int isLthread;
    int isRthread; 
};

typedef struct node Node;

Node* head=NULL;

void Insert(int data){
    Node* newnode = (Node*) malloc(sizeof(Node));
    if(newnode==NULL){
        printf("\nerr malloc\n");
        system("pause");
    }else{
        newnode->data = data;
        if(head==NULL){
            newnode->isLthread = 1;
            newnode->isRthread = 1;
            head=newnode;
            newnode->leftchild=head;
            newnode->rightchild=head;
        }else{
            Node* temp =head;
            while(1){
                if(newnode->data>temp->data){//right child
                    if(temp->isRthread){//leaf
                        temp->isRthread = 0;
                        newnode->isLthread = 1;
                        newnode->isRthread = 1;
                        newnode->leftchild=temp;
                        newnode->rightchild=temp->rightchild;
                        temp->rightchild=newnode;
                        break;
                    }else{
                        temp=temp->rightchild;
                    }
                }else{//left child
                    if(temp->isLthread){
                        temp->isLthread = 0;
                        newnode->isLthread = 1;
                        newnode->isRthread = 1;
                        newnode->rightchild=temp;
                        newnode->leftchild=temp->leftchild;
                        temp->leftchild=newnode;
                        break;
                    }else{
                        temp=temp->leftchild;
                    }
                }
            }
        }
    }
    printf("Threaded BST Insert %d\n",data);
}

Node* search(int x){
    Node* temp =head;
    if(temp==NULL){
        printf("tree is empty!\n");
    }else{
        while(1){
            if(x==temp->data){
                return temp;
            }else{
                if(x>temp->data){
                    if(temp->isRthread){
                        break;
                    }else{
                        temp=temp->rightchild;
                    }
                }else{
                    if(temp->isLthread){
                        break;
                    }else{
                        temp=temp->leftchild;
                    }
                }
            }
        }
            printf("the node is not exist in the tree\n");

    }
}

int Insuc(Node* x){
    Node* temp = x->rightchild;
    return temp->data;
}

int Inpre(Node* x){
    Node* temp = x->leftchild;
    return temp->data;
}

main(void)
{    

    int data[9]={5,6,4,8,2,3,7,1,9};

    for(int i =0;i<9;i++){
        Insert(data[i]);
    }
    
    while(1){
        int value;
        int select;
        int res;
        printf("\n(0)Find a node's successor of Inorder \n(1)Find a node's  predecessor of Inorder \n");
        scanf("%d",&select);
        fflush(stdin);
        switch(select){
            case 0:
                printf("Node?\n");
                scanf("%d",&value);
                fflush(stdin);
                if(search(value)!=NULL){
                    res=Insuc(search(value));
                    printf("Node %d 's Inorder successor is %d\n",value,res);
                }
                break;
            case 1:
                printf("Node?\n");
                scanf("%d",&value);
                fflush(stdin);
                if(search(value)!=NULL){
                    res=Inpre(search(value));
                    printf("Node %d 's Inorder predecessor is %d\n",value,res);
                }
                break;
            default:
                printf("/err format\n");
        }
    }

    system("pause");
}
