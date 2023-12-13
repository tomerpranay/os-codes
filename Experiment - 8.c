#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

sem_t x;
pthread_t writerthreads[100], readerthreads[100];
int readercount = 0, writercount = 0, criticalValue = 10;

void * reader() {
    printf("Reader is trying to enter\n");
    sem_wait( & x);
    readercount++;
    printf("Reader %d is inside\n", readercount);
    printf("Critical Value: %d\n", criticalValue);
    printf("Reader %d is leaving\n", readercount);
    sem_post( & x);
    return NULL;
}

void * writer() {
    printf("Writer is trying to enter\n");
    sem_wait( & x);
    writercount++;
    printf("Writer %d has entered\n", writercount);
    criticalValue += writercount;
    printf("Writer %d is leaving\n", writercount);
    sem_post( & x);
    return NULL;
}

int main() {
    int nReader, nWriter;
    printf("Enter the number of readers: ");
    scanf("%d", & nReader);
    printf("Enter the number of writers: ");
    scanf("%d", & nWriter);
    sem_init( & x, 0, 1);
    for (int i = 0; i < nReader; i++)
        pthread_create( & readerthreads[i], NULL, reader, NULL);
    for (int i = 0; i < nWriter; i++)
        pthread_create( & writerthreads[i], NULL, writer, NULL);
    for (int i = 0; i < nReader; i++)
        pthread_join(readerthreads[i], NULL);
    for (int i = 0; i < nWriter; i++)
        pthread_join(writerthreads[i], NULL);
    return 0;
}