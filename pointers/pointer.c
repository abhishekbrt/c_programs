#include <stdio.h>

int main(){
    printf("an int uses %zu bytes of memory\n", sizeof(int));
    int i=10;
    int i2=20;
    int *p=&i;
    printf("p points to the value %d\n", *p);
    printf("%p\n", (void *)p);
    printf("its address is %p\n", (void *)&i);
    printf("And its address is %p\n", (void *)&i2);
}