#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include <wait.h>


void collectCpuData(){
    printf("Executing collectCpu function from [child] process pid %d\n",getpid());
}

void collectMemData(){
    printf("Executing collectMem function from [child] process pid %d\n",getpid());
}

void collectNetData(){
    printf("Executing collectNet function from [child] process pid %d\n",getpid());
}
void collectDiskData(){
    printf("Executing collectDisk function from [child] process pid %d\n",getpid());
}

int main()
{
    int processes = 4;
    int pids[processes-1];
    for(int i=1;i<=processes;i++)
    {
        if((pids[i] = fork()) == 0)
        {
            switch(i){
                case -1:
                    perror("Failed to fork\n");
                    break;
                case 1:
                    collectCpuData();
                    exit(0);
                case 2:
                    collectMemData();
                    exit(0);
                case 3:
                    collectNetData();
                    exit(0);
                case 4:
                    collectDiskData();
                    exit(0);
            }
        }
    }
    sleep(3);
    for(int i=1;i<=processes;i++){
        printf("Printing the id of child %d with process pid %d\n",i,pids[i]);
        wait(NULL);
    }
}
