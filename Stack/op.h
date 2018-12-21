int isoperater(char op);
int priority(char op);

int isoperater(char op){
	switch(op){
		case '(':
		case ')':
		case '-':
		case '*':
		case '/':
		case '+':
			return 1;
		default:
			return 0;
	}
}

//return value bigger, the priority bigger
int priority(char op){
	switch(op){
		case '*':	
		case '/':	
			return 2;
		case '+':
		case '-':	
			return 1;
		case '(':	
			return 3;
		default: 
			return 0;
	}
}

