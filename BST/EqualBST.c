#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

void Equal(char a,char b);

int Equalsub(Node* a,Node* b);

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
    char paramenters[2];

    while(1){
        printf("*****************\n");
        printf("There are 'a' 'b' 'c' trees above, selet two to check equal or not\n");
        scanf("%s",paramenters);
        Equal(paramenters[0],paramenters[1]);
        printf("*****************\n");
    }

    system("pause");

}

int Equalsub(Node* a,Node* b){
    if(a!=NULL&&b!=NULL){
        if(a->data!=b->data){
            return 0;
        }else{
            if(Equalsub(a->leftchild,b->leftchild)&&Equalsub(a->rightchild,b->rightchild)){
                return 1;
            }else{
                return 0;
            }
        }
    }else{
        if(a==NULL&&b==NULL){
            return 1;
        }else{
            return 0;
        }
    }
}

void Equal(char a,char b){
    Node* tempa = SelectTree(a)->root;
    Node* tempb = SelectTree(b)->root;
    if(Equalsub(tempa,tempb)){
        printf("'%c' and '%c' is eqlual !!\n\n",a,b);
    }else{
        printf("'%c' and '%c' is not eqlual !!\n\n",a,b);
    }
}
