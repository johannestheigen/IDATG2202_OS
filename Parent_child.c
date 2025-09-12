#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
* Simple program that demonstrates the use of the fork() system call.
*
* Edit made in SkyHigh
* @author Johannes Nupen Theigen
* @version 11.09.2025
* @since 10.09.2025
*/
int main(int argc, char *argv[])
{

    printf("hello world (pid:%d)\n", (int) getpid());

    int x = 100;
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        x = 101;
        printf("hello, I am child (pid:%d): x = %d\n", (int) getpid(), x);
    } else {
        // parent goes down this path (original process)
        x = 99;
        printf("hello, I am parent of %d (pid:%d): x = %d\n",
               rc, (int) getpid(), x);
    }
    return 0;
}
