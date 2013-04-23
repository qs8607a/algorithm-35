#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_foo_func(void *);
void *thread_bar_func(void *);

int global = 4;

int main(){
  int local = 8;
  int foo, bar;
  pthread_t fthread, bthread;
  foo = pthread_create(&fthread, NULL, thread_foo_func, (void *)&local);
  bar = pthread_create(&bthread, NULL, thread_bar_func, (void *)&local);
  if (foo != 0 || bar != 0){
    printf("thread creation failed.\n");
    return -1;
  }

  foo = pthread_join(fthread, NULL);
  bar = pthread_join(bthread, NULL);
  if (foo != 0 || bar != 0){
    printf("thread join failed.\n");
    return -2;
  }

  char i;
  scanf("%c", &i);

  return 0;
}

void *thread_foo_func(void *arg){
  int foo_local = 16;
  printf("address of global %d: %x\n", global, &global);
  printf("address of main local %d: %x\n", *(int *)arg, arg);
  printf("address of foo local: %x\n", &foo_local);
  char i;
  scanf("%c", &i);
}

void *thread_bar_func(void *arg){
  int bar_local = 32;
  printf("address of global %d: %x\n", global, &global);
  printf("address of main local %d: %x\n", *(int *)arg, arg);
  printf("address of bar local: %x\n", &bar_local);
  char i;
  scanf("%c", &i);
}
