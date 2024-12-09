#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// Dosya oluşturma 
void create_file() {
    FILE *file = fopen("ornek.txt", "w");
    if (file == NULL) {
        perror("Dosya oluşturulamadı");
        exit(1);
    }
    printf("Dosya oluşturuldu.\n");
    fclose(file);
}

// Dosyaya veri yazma
void write_file() {
    FILE *file = fopen("ornek.txt", "a");  
    if (file == NULL) {
        perror("Dosyaya yazılamadı");
        exit(1);
    }
    fprintf(file, "Örnek yazı.\n");
    printf("Dosyaya veri yazıldı.\n");
    fclose(file);
}

// Dosyayı okuma ve içeriğini ekrana yazdırma f
void read_file() {
    FILE *file = fopen("ornek.txt", "r");
    if (file == NULL) {
        perror("Dosya açılamadı");
        exit(1);
    }
    char ch;
    printf("Dosyanın içeriği:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    printf("\nDosya okundu.\n");
    fclose(file);
}

int main() {
    int pid1, pid2, pid3;
    int durum;

    // ilk child process dosya oluşturma
    pid1 = fork();
    if (pid1 < 0) {
        perror("Fork 1 başarısız oldu");
        exit(1);
    }
    if (pid1 == 0) {
        create_file();
        exit(0);  
    }

    // 2.child process dosyaya yazı ekleme
    pid2 = fork();
    if (pid2 < 0) {
        perror("Fork 2 başarısız oldu");
        exit(1);
    }
    if (pid2 == 0) {
        sleep(1);  
        write_file();
        exit(0);
    }

    // 3.child process dosyayı okuma 
    pid3 = fork();
    if (pid3 < 0) {
        perror("Fork 3 başarısız oldu");
        exit(1);
    }
    if (pid3 == 0) {
        sleep(2);  
        read_file();
        exit(0);  
    }

    // Parent process
    waitpid(pid1, &durum, 0);
    waitpid(pid2, &durum, 0);
    waitpid(pid3, &durum, 0);

    printf("Tüm child process'ler tamamlandı.\n");
    
    return 0;
    
}

    
