#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node *next;
};

typedef struct node slot;
slot* start = NULL;//start of input linklist sequence

void radix_sorting(void);
int larger_dig(slot*);
int digit(int,int);

main(void){
    slot* el;
    slot* end;//rear of input linklist sequence
    int cnt,n,val;

    printf("Least Significant Digit First(LSD) Radix Sort\nEnter the Number of Elements : ");
    scanf("%d",&n);

    for(cnt=0;cnt<n;cnt++){
        printf("Enter element %d : ",cnt+1);
        scanf("%d",&val);

        //store every input value as link-list
        el=(slot*)malloc(sizeof(slot));
        el->data=val;
        el->next=NULL;

        if(start==NULL){
            start=el;
        }else{
            end=start;
            while(end->next!=NULL){
                end=end->next;
            }
            end->next=el;
        }
    }

    radix_sorting();

    printf("Sorted List is :\n");
    slot* temp = start;
    while( temp !=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    system("pause");
}

void radix_sorting(void){
    /*  Concept: 
        every bucket 0-9 is queue
        after every round(significant figure) link every queue in bucket 
    */
    int count,k,dig,least_sig,most_sig;
    slot *p,*rear[10],*front[10];

    least_sig=1;
    most_sig=larger_dig(start); // larger_dig() return the most significant figure

    for(k=least_sig; k<=most_sig; k++){// loop every significant figure

        // initial the content of 0-9 buckets to NULL
        for(count=0; count<=9 ; count++){
            rear[count] = NULL;
            front[count] = NULL ;
        }
        
        // distribute to correspond bucket 
        for( p=start; p!=NULL; p=p->next ){
            dig = digit(p->data, k);// return the bucket correct index
        
            if(front[dig] == NULL){
                front[dig] = p;
            }else{
                rear[dig]->next = p;
            }
            rear[dig] = p;
        }
        //find start of new link-list 
        count=0;
        while(front[count] == NULL){
            count++;
        }
        start = front[count];    

        //linking
        while(count<9){
            if(rear[count+1]!=NULL)
                rear[count]->next=front[count+1];
            else
                rear[count+1]=rear[count];
            count++;
        }
        
        //end of new link-list
        rear[9]->next=NULL;
    }
}

int larger_dig(slot* ptr){
    int large=0,ndigit=0;

    while(ptr!=NULL){
        if(ptr ->data > large){
            large = ptr->data;
        }
        ptr = ptr->next;
    }

    while(large != 0){
        ndigit++;
        large /= 10 ;
    }

    return ndigit;
}

int digit(int num, int k){

    for(int count=1; count<=k; count++){
        num = num /10 ;
    }

    return num%10;

}