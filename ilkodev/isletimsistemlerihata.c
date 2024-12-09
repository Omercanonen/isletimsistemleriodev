#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char **argv)
{
	int durum;
	//child process oluşturma
	int pid;
	pid = fork();
	
	if(pid<0){
		perror("Fork işlemi başarısız oldu");
		exit(1);
		}
		
	if(pid == 0){
		//child process
		FILE*file = fopen("ornek.txt","r");
		
		if(file==NULL){
			printf("Dosya bulunamadı abort kullanılıyor.");
			abort();
		}
		else{
			printf("Dosya açıldı çıkış işlemi gerçekleşiyor.");
			exit(0);
			}
		if(pid>0){
			//parent process
			wait(&durum);
			if(WIFSIGNALED(durum)){
				int signal_number=WTERMSIG(durum);
				printf("Alt işlem sinyal ile sonlandı. sinyal numarası:%d\n",signal_number);
				}
				else if (WIFEXITED(durum)) {
            int exit_status = WEXITSTATUS(durum);
            printf("Child process exit ile sonlandı. Çıkış durumu:%d\n", exit_status);
				} else {
            printf("Child process beklenmedik bir şekilde sonlandı.\n");
        }
			}	
	
	
	
}
return 0;
}

