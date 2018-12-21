#include<stdio.h>
#include<stdlib.h>

int counter = 0;

void hanoi(int n,char a[],char b[],char c[]){
    counter++;
    if(n==1){
        printf("move disk-%d  from %s to %s\n",n,a,c);
    }else{
        hanoi(n-1,a,b,c);
        printf("move disk-%d  from %s to %s\n",n,a,b);
        hanoi(n-1,b,a,c);
    }
}

main(void) {
    int n;
    char a[]="colA";
    char b[]="colB";
    char c[]="colC";
    printf("tower of hanoi\n");
    printf("input disk amount N:");
    scanf("%d",&n);
    hanoi(n,a,b,c);
    printf("call times is: %d\n",counter);
    system("pause");
}