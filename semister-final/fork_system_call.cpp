#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {

    pid_t child_pid;

    // Create a child process

    child_pid = fork();

    if(child_pid == 0) {
        // printf("Child Process\n");
        printf("Child Process PID = %d , Child PID value = %d\n",getpid(), child_pid);
    }else if(child_pid > 0) {

        // wait(NULL); // Wait for the child process to finish

        printf("Parent Process\n");
        
    }else {
        perror("Forkk failed!!\n");
    }



    return 0;
}