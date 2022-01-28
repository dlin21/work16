#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

int main(){
  printf("parent forking...");
  srand(time(NULL));
  
  int f1 = fork();
  int f2;

  if(f1) {
    rand();
    f2 = fork();
  }
  
  if(f1 && f2){
    int stat;
    int pid = wait(&stat);

    printf("parent: child pid: %d\t asleep for %d second\n", pid, WEXITSTATUS(stat));
    printf("parent process complete\n");
    return 0;
  }

  else{
    printf("child pid: %d\n ", getpid());
    int i = rand() % 4 + 2; // gets a number from 2 to 5
    sleep(i);
    printf("child slept for %d seconds\n", i);
    return i;
  }

  return 0;
}
