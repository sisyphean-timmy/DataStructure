/* Single link-list Queue */

#include <stdio.h>
#include <stdlib.h>

struct node{
	char data; 
	struct node *next;
};

typedef struct node Node; //def name of struct node

void enqueue(int value);
void dequeue(void);
void listall(void);

Node* front = NULL;
Node* rear = NULL;


void enqueue(int value){
	Node* newnode = (Node*)malloc(sizeof(Node));
	if(newnode==NULL){
		printf("\nerr malloc :¡@Queue is full");
		system("pause");
	}else{
		newnode->data = value;
		newnode->next = NULL;
		if(front==NULL&&rear==NULL){
			front = newnode;
			rear = newnode;
		}else{
			rear->next = newnode;
			rear = newnode;
		}
	}
	
}

void dequeue(void){
	if(front==NULL){
		printf("\nqueue is empty");
	}else{
		Node* temp = front;
		printf("\ndequeue %d",temp->data);
		front = front->next; //front move forwrad
		if(front==NULL){rear=NULL;}; // !! Important
		free(temp);
	}
}

void listqueue(void){
	if(front!=NULL&&rear!=NULL){
		Node* temp = front;//prevent effect real rear
		while(temp!=NULL){
			if(temp == front){
				printf(" (F) ");
			}
			if(temp == rear){
				printf(" (R) ");
			}
			printf(" %d | ->",temp->data);
			temp= temp->next;
		}
	}else{
		printf("empty\n");
	}
}

main(void){
    while(1){
		int select;
        printf("\n\n*******************\nSingle LinkList Queue opration\n(0)enqueue\n(1)dequeue\n(2)List Queue\n");
        scanf("%d",&select);
        switch(select){
            case 0:
				int value;
				printf("\nValue:\n");
        		scanf("%d",&value);
                enqueue(value);
                break;
            case 1:
                dequeue();
                break;
            case 2:
                listqueue();
                break;
            default:
                printf("\nerr format\n");
        }
    }
}