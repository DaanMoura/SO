/*
 * Estudos de Sistemas Operacionais
 * Daniel Moura
 *
 * Objetivo: explorar o uso do fork()
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int _x = 10;

int main() {
  pid_t result;

  printf("Parent PID: %d\n\n", getpid());
  printf("x: %d\n", _x);
  
  _x++;
  printf("incrementando x: %d\n\n", _x);

  printf("Realizando fork\n");
  result = fork();

  if(result==-1) {
    perror("Erro na execução do fork!");
    exit(0);
  }

  printf("Result: %d\n", result);

  /* separando processos */
  if(result==0) { /* filho */
    _x+=10;
    printf("\nFilho PID: %d\n", getpid()); fflush(stdout);
    printf("esperando..."); fflush(stdout); 
    sleep(15);
    printf("x do filho: %d\n----\n", _x); fflush(stdout);
  } else { /* pai */
    _x+=20;
    printf("\nPai PID: %d\n", getpid()); fflush(stdout);
    printf("esperando..."); fflush(stdout);
    sleep(30);
    printf("x do pai: %d\n----\n", _x); fflush(stdout);
  }
  
  /* final agora juntando tudo */
  _x++;
  printf("\nProcesso %d terminou. x incremento: %d\n", getpid(), _x);

  return 0;
}
