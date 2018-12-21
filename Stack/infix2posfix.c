#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include"op.h"

#define CHAR 10

int check(char t){
    if(priority(t)>priority(gettop())||gettop()=='('){
        return 1;
    }else{
        return 0;
    }
}

//REVIEW : *(infix+cnt) = infix[cnt]
void postfix(char* infix){
    int cnt = 0;
    int doit = 1;
    while( infix[cnt] !='\0' && infix[cnt] != '\n'){ // haven't scaned the string
        if(!isoperater(infix[cnt])){
            printf("%c",infix[cnt]);
        }else{
            if(infix[cnt]==')'){
                while(gettop()!='('){
                    printf("%c",gettop());
                    pop();
                }
                pop();
            }else{
                if(check(infix[cnt])){
                    push(infix[cnt]);
                }else{
                    while(!check(infix[cnt])){
                        printf("%c",gettop());
                        pop();
                    }
                    push(infix[cnt]);
                }
            }
        }
        cnt++;
    }
    while(!isEmpty()){
        printf("%c",gettop());
        pop();
    }
}

int main(void){
    char infix[CHAR];
    while(1){
        printf("inter the infix:\n");
        gets(infix);
        printf("Postfix:");
        postfix(infix);
        printf("\n\n");
    }
    //a/(b*c-(d+e))*(f-g)
    system("pause");
}
