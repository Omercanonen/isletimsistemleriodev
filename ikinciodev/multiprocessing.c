#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* karealma(void* arg) {
    int num = *((int*)arg);
    printf("Sayı: %d, Sayının Karesi: %d \n", num, num * num);
    free(arg);
    return NULL;
}

int main(int argc, char **argv) {
    pthread_t threads[5]; //5 adet iş parçacığı oluşturur
    int sayilar[] = {1, 2, 3, 4, 5};
    int i;

    for (i = 0; i < 5; i++) {
        int* num = malloc(sizeof(int));  
        *num = sayilar[i];  

        pthread_create(&threads[i], NULL, karealma, (void*)num);
    }

    for (i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL); 
    }

    printf("Tüm işlemler tamamlandı\n");

    return 0;
}


