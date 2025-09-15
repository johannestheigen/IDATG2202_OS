#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/**
 * This program forks a child process for each command line argument.
 * Each child executes the 'cowsay' program with its corresponding argument
 * as input. The parent process waits for each child, ensuring the cowsay
 * messages are printed in the same order as the arguments.
 *
 * @author Johannes Nupen Theigen
 * @version 15.09.2025
 * @since 15.09.2025
 */
int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) {
        int rc = fork();
        if (rc < 0) {
            // fork failed; exit
            fprintf(stderr, "fork failed\n");
            exit(1);
        } else if (rc == 0) {
            // child (new process)
            char *myargs[3];
            myargs[0] = strdup("cowsay");   // program: cowsay
            myargs[1] = argv[i];
            myargs[2] = NULL;               // marks end of array
            execvp(myargs[0], myargs);      // runs cowsay
            printf("this shouldn't print out");
        } else {
            // parent goes down this path (original process)
            waitpid(rc, NULL, 0);
        }
    }
    return 0;
}
