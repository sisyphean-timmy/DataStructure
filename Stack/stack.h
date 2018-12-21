
struct node{
	char data; 
	struct node *next;
};

typedef struct node Node; //def name of struct node

int isEmpty(void);
void push(char value);
void pop();
char gettop(void);

Node* top = NULL;


int isEmpty(void){
	if(top==NULL){
		return 1;
	}else{
		return 0;
	}
}

void push(char value){
    Node* newnode = (Node*) malloc(sizeof(Node)); //distribute memory of struct node (Node), and return initail address
	if(newnode==NULL){
		printf("\n err malloc");
    	system("pause");
	}
	newnode->data = value;
	newnode->next = top;
	top = newnode;
}

void pop(){
	if(!isEmpty()){
		Node* temp = top;//free top memory by temp ptr point to current top
		top = top->next;
		free(temp);
	}
}

char gettop(void){
	if(!isEmpty()){
		return top->data;
	}
}
