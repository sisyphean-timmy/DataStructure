/* Circular link-list Queue (Only use Rear)*/

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

Node* rear = NULL;

void enqueue(int value){
	Node* newnode = (Node*)malloc(sizeof(Node));
	if(newnode==NULL){
		printf("\nerr malloc :¡@Queue is full");
		system("pause");
	}else{
		if(rear==NULL){ // Null to 1 node ( the order is important )
			rear = newnode;
			newnode->data = value;
			newnode->next = newnode;
		}else{ // gather than 1 node ( the order is important )
			newnode->data = value;
			newnode->next = rear->next;
			rear->next = newnode;
			rear = newnode;
		}
	}
}

void dequeue(void){
	if(rear==NULL){
		printf("\nqueue is empty");
	}else{
		Node* temp = rear->next;
		if(rear==rear->next){ // the rest node is one and the node's next points to himself
			printf("\ndequeue %d",temp->data);
			rear = NULL;
		}else{ 
			printf("\ndequeue %d",temp->data);
			rear->next = temp->next;
		}
		free(temp);
	}
}

void listall(void){
	if(rear!=NULL){
		Node* temp = rear->next;
		int lc=1;
		while(lc){
			if(temp == rear->next){
				printf(" (R->Next) ");
			}
			if(temp == rear){
				printf(" (R) ");
				lc=0;
			}
			printf(" %d ->",temp->data);
			temp= temp->next;
		}
	}else{
		printf("empty\n");
	}
}

main(void){
    while(1){
		int select;
        printf("\n\n*******************\nCircular LinkList Queue opration\n(0)enqueue\n(1)dequeue\n(2)List All\n");
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
                listall();
                break;
            default:
                printf("\nerr format\n");
        }
    }
}