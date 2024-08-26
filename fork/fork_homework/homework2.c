#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd = open("../dummy.txt", O_RDWR);
    if (fd < 0)
    {
        perror("error while opening file");
        exit(42);
    }

    pid_t pid;
    pid = fork();

    if (pid < 0)
    {
        printf("error cannot create child process \n");
        exit(42);
    }
    else if (pid == 0)
    {
        printf("this is child process %d \n", getpid());
        char buf[100] = "this is from child process\n";
         for (int i = 0; i < 300; i++)
        {
            int sz = write(fd, buf, strlen(buf));
            if (sz < 0)
            {
                perror("error while writing to file");
            }
        }
        // printf("this is the fd : %d\n", fd);
    }
    else
    {
        printf("this is parent process %d \n", getpid());
        char buf[100] = "this is from parent process\n";
        for (int i = 0; i < 300; i++)
        {
            int sz = write(fd, buf, strlen(buf));
            if (sz < 0)
            {
                perror("error while writing to file");
            }
        }

        // printf("this is the fd : %d\n", fd);
    }

    close(fd);
    return 0;
}