#include<stdio.h>
#include<stdlib.h>
int counter =0;

fib(int n){
    counter++;
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }else{
        return fib(n-1)+fib(n-2);
    }
}

main(void) {
    int n;
    printf("input number:");
    scanf("%d",&n);
    printf("result is: %d\n",fib(n));
    printf("call times is: %d\n",counter);
    system("pause");
}