#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *x, char *y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 

void permute(char *a, int l, int r) 
{ 
    int i; 
    if (l == r) 
        printf("%s\n", a); 
    else
    { 
        for (i = l; i <= r; i++) 
        { 
            swap((a+l), (a+i)); 
            permute(a, l+1, r); 
            swap((a+l), (a+i)); 
        } 
    } 
}

int main(void) 
{ 
    int n;

    char *str = (char *)malloc(sizeof(char)); // *str => 存放已配置記憶體的起始位置

    printf("Inter The String : \n");
    scanf("%s",str);

    n = strlen(str);

    permute(str, 0, n-1);
    
    free(&str); // *str => address

    system("pause");
} 