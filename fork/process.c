#include<stdio.h>
#include<sys/types.h>

int main(){
    pid_t pid;
    pid=fork();

    if(pid<0){
        perror("error while creating child");

    }
    else if(pid==0){
        
    }
}