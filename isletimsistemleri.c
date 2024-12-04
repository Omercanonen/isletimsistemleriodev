
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int durum;
	//parent process bir child process oluşturdu
	int pid;
	pid=fork();
	
	
	if(pid<0){
		//error
		perror("işlem başarısız oldu");
		exit(1);
		}
	
	if(pid==0){
		//child process
		if (execlp("cat","cat","ornek.txt", NULL) == -1){
			perror("işlem başarısız oldu");
			exit(1);
			}
	}
	else if(pid>0){
			//parent process
			wait(&durum);
			if(WIFEXITED(durum))
				printf("Alt işlem başarıyla tamamlandı");
				else
				printf("Alt işlem başarısız oldu");
	}
	
	
	
	return 0;
}

