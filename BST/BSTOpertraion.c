#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* leftchild;
    struct node* rightchild;
};

typedef struct node Node;

Node* root = NULL;

void Insert(int value);
void Search(int value);
void Delete(int value);


main(void) {


    int data[9]={5,6,4,8,2,3,7,1,9};

    for(int i =0;i<9;i++){
        Insert(data[i]);
    }

    int select;
    int value;
    while(1){
        printf("\n\nselect traverse type\n(0)Search Node\n(1)Delete Node\n(2)Add Node\n");
        scanf("%d",&select);
        switch(select){
            case 0:
                printf("Search :");
                scanf("%d",&value);
                Search(value);
                break;
            case 1:
                printf("Delete :");
                scanf("%d",&value);
                Delete(value);
                break;
            case 2:
                printf("Add :");
                scanf("%d",&value);
                Insert(value);
                break;
            default:
                printf("\nerr unexpect format");
        }
    }

    system("pause");

}

void Insert(int value){
    Node* newnode = (Node*) malloc(sizeof(Node));
    if(newnode==NULL){
        printf("\nerr malloc\n");
        system("pause");
    }else{
        newnode->data = value;
        newnode->leftchild = NULL;
        newnode->rightchild = NULL;
    }
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
    printf("Inset %d\n",value);
}


void Search(int value){
    Node* target = root;
    int isfound = 0;
    while(target!=NULL&&!isfound){
        if(target->data==value){
            isfound=1;
        }else{
            if(value>target->data){//target in rightchild
                target=target->rightchild;
            }else{//target in leftchild
                target=target->leftchild;
            }
        }
    }
    if(isfound){
        printf("%d is in the tree",value);
    }else{
        printf("Can't find %d in the tree",value);
    }
}

void Delete(int value){

    /*search tree and save pointer to delete*/
    Node* target = root;
    Node* parent = root;
    int isfound = 0;
    while(target!=NULL&&!isfound){
        if(target->data==value){
            isfound=1;
        }else{
            parent=target;//save parent's pointer
            if(value>target->data){//right child
                target=target->rightchild;
            }else{//left child
                target=target->leftchild;
            }
        }
    }

    if(target==NULL){
        printf("Can't find %d in the tree",value);
    }else{
        /*use the pointer*/
        //case target is leaf
        if(target->rightchild==NULL&&target->leftchild==NULL){
            //check the parent pointer that the search save , is blong rightchild or leftchild
            if(parent->leftchild==target){//target is parent's leftchild
                parent->leftchild=NULL;
            }else{//target is parent's rightchild
                parent->rightchild=NULL;
            }
            free(target);
            printf("Delete %d in the tree and the node is leaf",value);
        }
        //case target no leftchild
        else if(target->rightchild!=NULL&&target->leftchild==NULL){
            if(parent->leftchild==target){//target is parent's leftchild
                parent->leftchild=target->rightchild;
            }else{//target is parent's rightchild
                parent->rightchild=target->rightchild;
            }
            free(target);
            printf("Delete %d in the tree and the node has no leftchild",value);
        }
        //case target no rightchild
        else if(target->rightchild==NULL&&target->leftchild!=NULL){
            if(parent->leftchild==target){//target is parent's leftchild
                parent->leftchild=target->leftchild;
            }else{//target is parent's rightchild
                parent->rightchild=target->leftchild;
            }
            free(target);
            printf("Delete %d in the tree and the node has no rightchild",value);
        }
        //case target has rightchild and leftchild (Swap target and (1)target->leftchild->rigchild->{max node} or (2)target->rightchild->leftchild->{min node} )
        else if(target->rightchild!=NULL&&target->leftchild!=NULL){
            //use (1)target->leftchild->rigchild->{max node}
            Node* temp =target->leftchild;
            while(temp->rightchild!=NULL){
                temp=temp->rightchild;
            }
            target->data=temp->data;
            target->leftchild=temp->leftchild;
            free(temp);
            printf("Delete %d in the tree and the node has rightchild and leftchild",value);
        }
    }
}
