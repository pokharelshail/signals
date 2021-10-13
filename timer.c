/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int isHandled;
int alarmNum = 0;
time_t startTime;
time_t endTime;

void handler(int signum)
{ //signal handler
  isHandled = 1;
  alarmNum +=1;
  printf("Hello World!\n");
  alarm(1);
//   exit(1); //exit after printing
}

void handler2(int signum){
  time_t runtime;
  endTime = time(NULL);
  runtime = endTime-startTime;
  printf("Number of alarms was %d\n", alarmNum);
  printf("\nRuntime: %d \n", (int)runtime);
  exit(0);
}

int main(int argc, char * argv[])
{
  startTime = time(NULL);
  signal(SIGALRM,handler);//register handler to handle SIGALRM
  signal(SIGINT,handler2);
  while(1){
    isHandled = 0;
    alarm(1);
    while(isHandled == 0);
    printf("turing was right!\n");
  }
  return 0; //never reached
}