#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

int sayilar[] = {1,2,3,4,5};
int i;

void* karealma(void* arg) {
    int num = *((int*)arg); 
    pthread_t thread_id = pthread_self(); 
    printf("Thread/Process ID: %lu, Sayı: %d, Karesi: %d\n", thread_id, num, num*num);
    sleep(1);
    return NULL;
}

void coklu_programlama() {
    printf("Çoklu programlama başlatıldı\n");
    pthread_t threads[5];
    for (i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, karealma, (void*)&sayilar[i]);
    }
    for (i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Çoklu programlama sonlandı\n");
}

void coklu_islemci() {
    printf("Çoklu işlemci başlatıldı\n");
    for (i = 0; i < 5; i++) {
        int pid = fork();
        if (pid == 0) {
            karealma((void*)&sayilar[i]);
            exit(0); 
        }
    }
    for (i = 0; i < 5; i++) {
        wait(NULL); 
    }
    printf("Çoklu işlemci sonlandı\n");
}

int main(int argc, char **argv) {
    coklu_programlama();  
    coklu_islemci();     
    return 0;
}
