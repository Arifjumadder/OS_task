#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int shared = 1;
int read_count = 0;

pthread_mutex_t mutex;
pthread_mutex_t write_lock;

void *reader(void *arg) {
    int id = *((int *)arg);

    printf("Reader %d trying to acquire lock\n", id);
    
    pthread_mutex_lock(&mutex);
    read_count++;
    if (read_count == 1) {
        pthread_mutex_lock(&write_lock);
    }
    pthread_mutex_unlock(&mutex);

    printf("Reader %d is reading shared = %d\n", id, shared);
    sleep(1);
    printf("Reader %d done reading\n", id);

    pthread_mutex_lock(&mutex);
    read_count--;
    if (read_count == 0) {
        pthread_mutex_unlock(&write_lock);
    }
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void *writer(void *arg) {
    int id = *((int *)arg);

    printf("Writer %d trying to acquire lock\n", id);
    pthread_mutex_lock(&write_lock);

    printf("Writer %d is writing...\n", id);
    shared += 10;
    sleep(1);
    printf("Writer %d updated shared to %d\n", id, shared);

    pthread_mutex_unlock(&write_lock);
    printf("Writer %d released lock\n", id);

    return NULL;
}

int main() {
    pthread_t r1, r2, w1;
    int r_id1 = 1, r_id2 = 2, w_id = 1;

    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&write_lock, NULL);

    pthread_create(&r1, NULL, reader, &r_id1);
    pthread_create(&w1, NULL, writer, &w_id);
    pthread_create(&r2, NULL, reader, &r_id2);

    pthread_join(r1, NULL);
    pthread_join(w1, NULL);
    pthread_join(r2, NULL);

    printf("Final value of shared is %d\n", shared);

    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&write_lock);

    return 0;
}
