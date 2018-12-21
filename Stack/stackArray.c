#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTACK 5 /*define stack's size*/

int stack[MAXSTACK];
int top=0;

isEmpty(){
    if(top==0){
        return 1;//empty
    }else{
        return 0;//not empty
    }  
}

pop(){
    if(isEmpty()){
        printf("Stack is empty!!\n");
    }else{
        printf("pop data: %d\n",stack[top]);
        top--;
    }
}

push(int val){
    if(top>=MAXSTACK){
        printf("Stack is full!!\n");
    }else{
        top++;
        stack[top]=val;
        printf("push data: %d ,top: %d \n",stack[top],top);
    }
}

main(void){

    int val; // data of int
    int select; 
    
    printf("Stack (by array) \n\n");
    while(1){
        printf("(1) push data (2) pop data :");
        scanf("%d",&select);
        switch(select){
            case 1://push
                printf("Inter the data (Integer):");
                scanf("%d",&val);
                push(val);
                break;
            case 2://pop
                pop();
                break;
            default:
                printf("\n*err format\n");
        }
        printf("================================\n");
    }
}