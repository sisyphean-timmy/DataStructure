#include<stdio.h>
#include<stdlib.h>

int counter =0;

power(int x,int n){
    counter++;
    if(n==0){
        return 0;
    }else if(n==1){
        return x;
    }else{
        return x*power(x,n-1);
    }
}

main(void) {
    int x,n;
    printf("X to the power of N,X>=1,N>=0\n");
    printf("input X:");
    scanf("%d",&x);
    printf("input N:");
    scanf("%d",&n);
    printf("result is: %d\n",power(x,n));
    printf("call times is: %d\n",counter);
    system("pause");
}