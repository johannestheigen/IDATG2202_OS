/**
Simple program that demonstrates the use of the system call fork() and waitpid(),
The program runs six processes according to
the following time schedule (S means start, T means
terminate/exit):

Process-number
  ^
5 |           S--------T
4 |  S--------T
3 |        S-----T
2 S--------T
1 |  S-----T
0 S--T
  +-----------------------> time (seconds)
  0  1  2  3  4  5  6  7

@author Johannes Nupen Theigen
@version 10.09.2025
@since 10.09.2025
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
States which process is running and how long it ran for
*/
void process(int number, int time) {
    printf("Process %d is running\n", number);
    sleep(time);
    printf("Process %d ran for %d seconds\n", number, time);
}

/*
The main program
*/
int main(void) {
    pid_t pid0, pid1, pid2, pid3, pid4, pid5;

    pid0 = fork(); /* Process number 0 */
    if (pid0 == 0) {
        process(0, 1);
        exit(0);
    }

    pid2 = fork(); /* Process number 2 */
    if (pid2 == 0) {
        process(2, 3);
        exit(0);
    }

    waitpid(pid0, NULL, 0); /* Waits for process 0 to finish */

    pid1 = fork(); /* Process number 1 */
    if (pid1 == 0) {
        process(1, 2);
        exit(0);
    }

    pid4 = fork(); /* Process number 4 */
    if (pid4 == 0) {
        process(4, 3);
        exit(0);
    }

    waitpid(pid1, NULL, 0); /* Waits for process 1 to finish */


    pid3 = fork(); /* Process number 3 */
    if (pid3 == 0) {
        process(3, 2);
        exit(0);
    }
    pid3 = fork(); /* Process number 3 */
    if (pid3 == 0) {
        process(3, 2);
        exit(0);
    }

    waitpid(pid4, NULL, 0); /* Waits for process 4 to finish */

    pid5 = fork(); /* Process number 5 */
    if (pid5 == 0) {
        process(5, 3);
        exit(0);
    }

    /**
    Clean up any remaining processes
    */
    pid_t child;
    while ((child = wait(NULL)) > 0) {
    }
    return 0;
}
