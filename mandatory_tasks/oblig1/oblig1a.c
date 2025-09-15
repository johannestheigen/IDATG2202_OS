#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
This program creates exactly four processes in total using fork()
The original process (the root parent) should create a child;
both the parent and that child should each create one additional child,
resulting in this two-level tree. The end result should print out something
like this:

depth=0 pid=120023 ppid=119864
        depth=1 pid=120025 ppid=120023
        depth=1 pid=120024 ppid=120023
                depth=2 pid=120026 ppid=120024

*/
int main(void) {
    pid_t pid1, pid2; // Child processes to be forked
    int depth = 0; // Initial depth

    setvbuf(stdout, NULL, _IONBF, 0);

    pid1 = fork();
    if (pid1 < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid1 == 0) {
        depth = 1; // Sets the depth to 1
    }
    pid2 = fork();
    if (pid2 < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid2 == 0) {
        depth++; // Child is one level deeper than its parent
    }
    if (depth == 0) {
        printf("depth=%d pid=%d ppid=%d\n", depth, getpid(), getppid());
    } else if (depth == 1) {
        printf("\tdepth=%d pid=%d ppid=%d\n", depth, getpid(), getppid());
    } else if (depth == 2) {
        printf("\t\tdepth=%d pid=%d ppid=%d\n", depth, getpid(), getppid());
    }

    // Reap any children (if we have any) to avoid zombies, leave as is
    int status;
    while (wait(&status) > 0) {
        // loop until no more children
    }
    return 0;
}
