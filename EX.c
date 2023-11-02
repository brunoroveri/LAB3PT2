#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4     // Número de threads
#define NUM_TERMS 1000000 // Número de termos na série

double partial_sums[NUM_THREADS]; 
double sum = 0.0; 
pthread_mutex_t print_mutex;
long current_thread = 0;
pthread_mutex_t thread_order_mutex;

  void* Thread_sum(void* rank) {
    long my_rank = (long) rank;
    double factor, my_sum = 0.0;
    long long i;
    long long my_n = NUM_TERMS/NUM_THREADS;
    long long my_first_i = my_n*my_rank;
    long long my_last_i = my_first_i + my_n - 1;

    pthread_mutex_lock(&thread_order_mutex);
    while (my_rank != current_thread) {
        pthread_mutex_unlock(&thread_order_mutex);
        pthread_mutex_lock(&thread_order_mutex);
    }

    pthread_mutex_lock(&print_mutex);
    printf("\nThread %ld iniciando cálculo para termos %lld até %lld.\n", my_rank, my_first_i, my_last_i);
    pthread_mutex_unlock(&print_mutex);

    if (my_first_i % 2 == 0) factor = 1.0;
    else factor = -1.0;

    for (i = my_first_i; i <= my_last_i; i++, factor = -factor) {
        my_sum += factor/(2*i+1);
    }

    pthread_mutex_lock(&print_mutex);
    printf("Thread %ld terminou.\n", my_rank);
    pthread_mutex_unlock(&print_mutex);

    partial_sums[my_rank] = my_sum;

    current_thread++;  
    pthread_mutex_unlock(&thread_order_mutex);

    return NULL;
  }

  int main() {
    pthread_mutex_init(&print_mutex, NULL);       
    pthread_mutex_init(&thread_order_mutex, NULL);
    pthread_t threads[NUM_THREADS];
    long thread;
    double pi_estimate = 0.0;

    printf("Calculando pi usando %d threads e %d termos.\n", NUM_THREADS, NUM_TERMS);

    for(thread = 0; thread < NUM_THREADS; thread++) {
        pthread_create(&threads[thread], NULL, Thread_sum, (void*)thread);
    }

    for(thread = 0; thread < NUM_THREADS; thread++) {
        pthread_join(threads[thread], NULL);
        pi_estimate += partial_sums[thread];  
    }

    pi_estimate *= 4.0;  

    printf("\nEstimativa de pi = %.6f\n", pi_estimate);  

    pthread_mutex_destroy(&print_mutex);          
    pthread_mutex_destroy(&thread_order_mutex);
    return 0;
}# LAB3PT2
# LAB3PT2
