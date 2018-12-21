#include <stdio.h>
#include <stdlib.h>


//struct Node of BSTtree
struct BSTNode{
    int data;
    struct BSTNode* leftchild;
    struct BSTNode* rightchild;
};
typedef struct BSTNode BST;

BST* root = NULL;

void cbst(int data);
void inorder(BST* temp);
void preorder(BST* temp);
void postorder(BST* temp);
void levelorder(BST* temp);

//struct Node of Queue
struct QueueNode{
    BST* data;
    struct QueueNode* next;
};
typedef struct QueueNode Queue;

Queue* rear = NULL;
Queue* front = NULL;
void enqueue(BST* ptr);
BST* dequeue(void);
int Qempty(void);

main(void) {


    int data[9]={5,6,4,8,2,3,7,1,9};

    for(int i =0;i<9;i++){
        cbst(data[i]);
    }

    int select;

    while(1){
        printf("\n\nselect traverse type\n(0)Inorder\n(1)Preorder\n(2)Postorder\n(3)Levelorder\n");
        scanf("%d",&select);
        switch(select){
            case 0:
                inorder(root);
                break;
            case 1:
                preorder(root);
                break;
            case 2:
                postorder(root);
                break;
            case 3:
                levelorder(root);
                break;
            default:
                printf("\nerr unexpect format");
        }
    }

    system("pause");

}

void enqueue(BST* ptr){
    Queue* newnode = (Queue*)malloc(sizeof(Queue));
    if(newnode==NULL){
        printf("\nerr malloc : queue");
        system("pause");
    }else{
        newnode->data = ptr;
        newnode->next = NULL;
        if(rear==NULL&&front==NULL){
            rear = newnode;
            front = newnode;
        }else{
            rear->next = newnode;
            rear = newnode;
        }
    }
}
BST* dequeue(void){
    if(front!=NULL){
        Queue* temp1 = front;
        BST* data = front->data;
        front=front->next;
        if(front==NULL){rear=NULL;};
        free(temp1);
        return data;
    }
}
int Qempty(void){
    if(front==NULL&&rear==NULL){
        return 1;
    }else{
        return 0;
    }
}

void cbst(int data){
    BST* newnode = (BST*) malloc(sizeof(BST));
    if(newnode==NULL){
        printf("\nerr malloc\n");
        system("pause");
    }else{
        newnode->data = data;
        newnode->leftchild = NULL;
        newnode->rightchild = NULL;
    }
    if(root==NULL){
        root = newnode;
    }else{
        BST* temp=root;
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
    printf("Inset %d\n",data);
}
void inorder(BST* temp){
    if(temp!=NULL){
        /*L*/inorder(temp->leftchild);
        /*D*/printf("%d,",temp->data);
        /*R*/inorder(temp->rightchild);
    }
}
void preorder(BST* temp){
    if(temp!=NULL){
        /*D*/printf("%d,",temp->data);
        /*L*/inorder(temp->leftchild);
        /*R*/inorder(temp->rightchild);
    }
}
void postorder(BST* temp){
    if(temp!=NULL){
        /*L*/inorder(temp->leftchild);
        /*R*/inorder(temp->rightchild);
        /*D*/printf("%d,",temp->data);
    }
}
void levelorder(BST* temp){
    enqueue(temp);
    while(!Qempty()){
        BST* ptr = dequeue();
        printf("%d,",ptr->data);
        
        if(ptr->leftchild!=NULL){
            enqueue(ptr->leftchild);
        }
        
        if(ptr->rightchild!=NULL){
            enqueue(ptr->rightchild);
        }
    }
}