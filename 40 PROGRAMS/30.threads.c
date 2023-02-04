#include <stdio.h>
#include <string.h>
#include <pthread.h>

int i = 2;

void* foo(void* p){

  printf("Value recevied as argument in starting routine: ");
  printf("%i\n", * (int*)p);

  pthread_exit(&i);
}

int main(void){
  pthread_t id;

  int j = 1;
  pthread_create(&id, NULL, foo, &j);
    
  int* ptr;

  pthread_join(id, (void**)&ptr);
  printf("Value recevied by parent from child: ");
  printf("%i\n", *ptr);
}
