#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

#include "randomfuncs.h"

#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define BHRED "\e[1;91m"
#define BHBLUE "\e[1;94m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"
#define GREY "\e[38;5;248m"
#define reset "\e[0m"

int main() {
  printf(HCYN"%d"reset" about to create 2 child processes\n", getpid());
  pid_t p1, p2;
  p1 = fork();
  if (p1 != 0) {
    p2 = fork();
  }
  if (p1 < 0 || p2 < 0)
    perror("fork fail\n");
  else if (p1 == 0) {
    int random_num = abs(random_random() % 5) + 1;

    printf(HCYN "%d" reset " " HGRN "%d" reset "sec\n", getpid(), random_num);
    sleep(random_num);
    printf(HCYN "%d" reset " finished after " HGRN "%d" reset "sec\n", getpid(),
           random_num);
    return (random_num);
  } else if (p2 == 0) {
    int random_num = abs(random_random() % 5) + 1;
    printf(HCYN "%d" reset " " HGRN "%d" reset "sec\n", getpid(), random_num);
    sleep(random_num);
    printf(HCYN "%d" reset " finished after " HGRN "%d" reset "sec\n", getpid(),
           random_num);
    return (random_num);
  } else {
    int status;
    int exit_pid = wait(&status);
    printf("Main Process " HCYN "%d" reset " is done. Child process " HCYN
           "%d" reset " finished after " HGRN "%d" reset " seconds\n",
           getpid(), exit_pid, WEXITSTATUS(status));
  }
}