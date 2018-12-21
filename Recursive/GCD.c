#include<stdio.h>
#include<stdlib.h>
int counter =0;

gcd(int a,int b){
    counter++;
    if(a%b==0){
        return b;
    }else{
        gcd(b,a%b);
    }
}

main(void) {
    int a,b;
    printf("find gratest common divisor paramenter A:");
    scanf("%d",&a);
    printf("find gratest common divisor paramenter B:");
    scanf("%d",&b);
    printf("result is: %d\n",gcd(a,b));
    printf("call times is: %d\n",counter);
    system("pause");
}