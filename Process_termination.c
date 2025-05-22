#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork Failed\n");
        exit(1);
    }
    else if (pid == 0) {
        printf("Child process running 'ls' command...\n");
        execlp("/bin/ls", "ls", NULL);
        perror("execlp failed");
        exit(2);
    }
    else {
        int status;
        wait(&status);

        if (WIFEXITED(status)) {
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Child terminated abnormally\n");
        }

        printf("Parent process complete.\n");
        exit(0);
    }
}
