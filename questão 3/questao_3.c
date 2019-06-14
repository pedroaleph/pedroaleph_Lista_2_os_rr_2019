/*3) Faça um programa que imprima os números primos 
 * existentes entre 0 e 99999. UTILIZE THREADS. 
 * Dica: para cada faixa de mil valores 
 * crie uma thread e dispare o processo para cada uma delas. 
*/
//compilador gcc
//criado no terminal: vim questa_3.c
//para compilar: gcc questao_3.c -pthread -o questao_3
// para executar: ./questao_3
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
// como temos que colocar uma thread para cada 1000 de 99999
// então temos 100 threads
#define NUM_THREADS 100

pthread_t threads[NUM_THREADS];//definindo o número de threads

void *primos(void *valor){
    long v = (long)valor;
    long n;
    for(n = v; n < v + 1000; n++){
        int d = 0; //divisores do numero
        long N = n;//dividendo do numero
        while(N > 0){//divide n por N até que N seja 1
            if(n%N == 0) d++;// conta os divisores
            N--;
        }
        if(d <= 2) printf("%ld eh primo\n", n);// se ele so tiver 2 divisores (1 e n), entao eh primo
    }
pthread_exit(NULL);
}
int main(){
   long i;//valor que ira criar cada thread no loop até 100
   printf("numeros primos usando threads\n\n");
    for(i = 0; i < NUM_THREADS; i++){
        printf("Thead do intervalo %ld - %ld\n",i*1000, i*1000+999);
        pthread_create(&threads[i], NULL, primos, (void*)(i*1000));//criando as threads...
    }
    pthread_exit(NULL);
    return 0;
}
