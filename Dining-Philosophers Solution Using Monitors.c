#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define NUM_PHILOSOPHERS 5
#define NUM_MEALS 3
pthread_mutex_t forks[NUM_PHILOSOPHERS];
pthread_t philosophers[NUM_PHILOSOPHERS];
pthread_cond_t forks_available[NUM_PHILOSOPHERS];
int meals_eaten[NUM_PHILOSOPHERS];
void *philosopher(void *arg) {
int id = *((int *) arg);
int left_fork = id;
int right_fork = (id + 1) % NUM_PHILOSOPHERS;
for (int i = 0; i < NUM_MEALS; i++) {
printf("Philosopher %d is thinking\n", id);
pthread_mutex_lock(&forks[left_fork]);
while (meals_eaten[id] == i) {
pthread_cond_wait(&forks_available[right_fork], &forks[left_fork]);
}
printf("Philosopher %d is eating\n", id);
meals_eaten[id]++;
pthread_cond_signal(&forks_available[(right_fork + 1) % NUM_PHILOSOPHERS]);
pthread_mutex_unlock(&forks[left_fork]);
printf("Philosopher %d is done eating\n", id);
usleep(1000000); // wait for a second to simulate eating time
}
return NULL;
}
int main() {
for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
pthread_mutex_init(&forks[i], NULL);
pthread_cond_init(&forks_available[i], NULL);
}
int ids[NUM_PHILOSOPHERS];
for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
ids[i] = i;
pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
}
for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
pthread_join(philosophers[i], NULL);
}
for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
pthread_mutex_destroy(&forks[i]);
pthread_cond_destroy(&forks_available[i]);
}
return 0;
}