/* Sistemas Operacionais
 * Autor: Daniel Moura
 * Objetivo: Criar e observar execução de threads */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TIME 10

int _stop = 0;
pthread_t _tid;

void *minha_thread() {
  int i;
  int ret;
  
  printf("%d\n", (unsigned int) _tid);

  for(i=0;i<10;i++) {
    printf("%d ... \n", i);
    sleep(1);
  }

  _stop = 1;
  printf("mudando stop para %d\n", _stop);
  pthread_exit(&ret);
}

int main() {

  pthread_create(&_tid, NULL, &minha_thread, NULL);
  
  while(!_stop) {
    printf("executando main (stop = %d) \n", _stop);
    sleep(1);
  }
  
  printf("thread _tid: %d acabou!\n", (unsigned int) _tid);

  return 0;
}
