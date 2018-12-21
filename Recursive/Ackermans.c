#include<stdio.h>
#include<stdlib.h>

int counter =0;

ack(int m,int n){
    counter++;
    if(m == 0){
        return n+1;
    }else if(n == 0){
        return ack(m-1,1);
    }else{
        return ack(m-1,ack(m,n-1));
    }
}

main(void) {
    int n,m;
    printf("input ackermans paramenters 1 M=:");
    scanf("%d",&m);
    printf("input ackermans paramenters 2 n=");
    scanf("%d",&n);
    printf("result is: %d\n",ack(m,n));
    printf("call times is: %d\n",counter);
    system("pause");
}