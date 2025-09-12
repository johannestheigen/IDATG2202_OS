#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

/**
Program that opens a file and forks a child and
writes two separate strings to the same file.

@author Johannes Nupen Theigen
@version 11.09.2025
@since 11.09.2025
*/
int main(int argc, char *argv[]) {

    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644); // Open the file and return a file descriptor (fd).
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child: writes directly to the file
        char *file_content = "This was written by the child process \n";
        write(fd, file_content, strlen(file_content));
        close(fd);

    } else {
        // parent writes directly to the file
        char *file_content = "This was written by the parent process \n";
        write(fd, file_content, strlen(file_content));
        close(fd);
    }
    return 0;
}