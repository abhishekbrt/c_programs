#include <stdio.h>
int main(){
    int a=5;
    int b=4;
    int *r=&b;
    int *p=&a;
     printf("%p\n",p);

    printf("%p\n",p);
    printf("%p\n",&p);
    // printf("%p\n",r);
    // printf("%d\n", *r);

    // int a=5;
    // int *p=&a;
    // p+=5;
    // printf("%p\n",p);

    int arr[3]={2,3,4};
    printf("%p\n",arr);
    
   
}