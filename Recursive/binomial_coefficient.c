#include<stdio.h>
#include<stdlib.h>
int counter =0;

bin(int n,int m){
    counter++;
    if(n==m||m==0){
        return 1;
    }else{
        return bin(n-1,m)+bin(n-1,m-1);
    }
}

main(void) {
    int n,m;
    printf("input binomial paramenters 1 N=:");
    scanf("%d",&n);
    printf("input binomial paramenters 2 M=");
    scanf("%d",&m);
    printf("result is: %d\n",bin(n,m));
    printf("call times is: %d\n",counter);
    system("pause");
}