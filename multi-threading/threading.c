#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *myturn(void *arg)
{
    int *ptr=(int *)arg;
    for(int i=1;i<=8;i++)
    {
        sleep(1);
        printf("My turn! %d\n",i);
        (*ptr)++;

    }
    return NULL;
}

void yourturn()
{
    for(int i=1;i<=3;i++)
    {
        sleep(2);
        printf("your turn! %d\n",i);
    }
}

int main()
{
    pthread_t newthread;
    int a=10;
    
    pthread_create(&newthread, NULL, myturn, &a);
    yourturn();
    
    pthread_join(newthread,NULL);
    printf("threads done a:%d\n",a);
    return 0;
}
