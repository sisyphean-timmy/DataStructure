#include <stdio.h>
#include <stdlib.h>

struct node{
	int data; 
	struct node *next;
};

typedef struct node Node; //def name of struct node

int isEmpty(Node* top);
Node* push(int value,Node* top);
Node* pop(Node* top);
void showAll(Node* top);

main(void){
	Node* top = NULL;
	int input,select;
	while(1){
		printf("(0)push data\n");
		printf("(1)pop data\n");
		scanf("%d",&select);
		switch(select){
			case 0:
				printf("\ninter the data:\n");
				scanf("%d",&input);
				top = push(input,top);
				showAll(top);
				break;
			case 1:
				top = pop(top);
				showAll(top);
				break;
			default:
				printf("\n err format!");	
		}
	}
	system("pause");
}


int isEmpty(Node* top){
	if(top==NULL){
		return 1;
	}else{
		return 0;
	}
}

Node* push(int value,Node* top){
    Node* newnode = (Node*) malloc(sizeof(Node)); //distribute memory of struct node (Node), and return initail address
	if(newnode==NULL){
		printf("\n err malloc");
		exit(0);
	}
	newnode->data = value;
	newnode->next = top;
	top = newnode;
	return top;
}

Node* pop(Node* top){
	if(isEmpty(top)){
		printf("\nstack has empty\n");
	}else{
		printf("\npop %d\n",top->data);
		Node* temp = top;//free top memory by temp ptr point to current top
		top = top->next;
		free(temp);
		return top;
	}
}

void showAll(Node* top){
	if(isEmpty(top)){
		printf("stack is empty\n");
	}else{
		printf("\n----start-----\n");
		printf("\n %d <--top",top->data);
		Node* ptr = top->next; // "ptr" (for list all data )instead of "top"
		while(ptr!=NULL){
			printf("\n %d",ptr->data);
			ptr = ptr->next;
		}
		printf("\n\n----end-----\n\n");
	}
}