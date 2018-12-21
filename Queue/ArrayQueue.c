#include<stdio.h>
#include<stdlib.h>

#define Qsize 6 // One will be stored front and rear

// type=0 linear array
// type=1 circular array (use n-1)
// type=2 circular array (use n)
void enqueue(int* q,int type);
void dequeue(int* q,int type);

int flag = 0; //var for type=2

//commen
void listQueue(int* q);
int front= 0;
int rear= 0;

int main(void){
    int select;
    int type;
    int queue[Qsize]={0}; //array data initail => 0
    printf("\n*******************\nSelect Array Queue type ? \nDefine array size is %d, one will be stored front and rear,avaliable N is %d\n(0)type 1 (Lineaer array)\n(1)type 2 (Circular array use n-1)\n(2)type 3 (Circular array use n)\n",Qsize,Qsize-1);
    scanf("%d",&type);
    while(1){
        printf("\n*******************\nQueue opration\n(0)enqueue\n(1)dequeue\n(2)List Queue\n");
        scanf("%d",&select);
        switch(select){
            case 0:
                enqueue(queue,type);
                break;
            case 1:
                dequeue(queue,type);
                break;
            case 2:
                listQueue(queue);
                break;
            default:
                printf("\nerr format\n");
        }
    }
}

void enqueue(int* q,int type){
    switch(type){
        case 0://linear array
            if(rear==Qsize-1){
                printf("Queue is full\n");
            }else{
                int value;
                printf("value?\n");
                scanf("%d",&value);
                rear++;
                q[rear]=value;
            }
            break;
        case 1://circular array (use n-1)
            if((rear+1)%(Qsize-1)==front){
                printf("Queue is full\n");
            }else{
                int value;
                printf("value?\n");
                scanf("%d",&value);
                rear=(rear+1)%(Qsize-1);
                q[rear]=value;
            }
            break;
        case 2://circular array (use n)
            if(rear==front&&flag==1){
                printf("Queue is full\n");
            }else{
                int value;
                printf("value?\n");
                scanf("%d",&value);
                rear=(rear+1)%(Qsize-1);
                q[rear]=value;
                if(rear==front){
                    flag = 1;
                }
            }
            break;
    }  
}
void dequeue(int* q,int type){
    switch(type){
    case 0://linear array
        if(rear==front){
            printf("Queue is empty\n");
        }else{
            front++;
            printf("dequeue %d\n",q[front]);
        }
        break;
    case 1://circular array (use n-1)
        if(rear==front){
            printf("Queue is empty\n");
        }else{
            front=(front+1)%(Qsize-1);
            printf("dequeue %d\n",q[front]);
        }
        break;
    case 2://circular array (use n)
        if(rear==front&&flag==0){
            printf("Queue is empty\n");
        }else{
            front=(front+1)%(Qsize-1);
            printf("dequeue %d\n",q[front]);
            if(rear==front){
                flag = 0;
            }
        }
        break;
    }
    
}

void listQueue(int* q){
    int cnt=0;
    while(cnt<Qsize){
        if(q[cnt]==0){
            printf("(%d) empty",cnt);
        }else{
            printf("(%d) %d",cnt,q[cnt]);
        }
        if(rear==cnt){
            printf(" (rear) ");
        }
        if(front==cnt){
            printf(" (front) ");
        }
        printf(" ; ");
        cnt++;
    }
}