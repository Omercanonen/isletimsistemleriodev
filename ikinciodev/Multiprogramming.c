#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void program1(){
	int i;
	for(i=0;i<5;i++)
	{	printf("Program 1 Çalışıyor: %d \n",i);
		sleep(1);
		}
	}
	
void program2(){
	int i;
	for(i=0;i<5;i++){
		printf("Program 2 çalışıyor: %d \n",i);
		sleep(1);
		}
	
	}	
int main(int argc, char **argv)
{
	int pid1, pid2;
	
	pid1=fork();
	if(pid1==0){
		program1();
		return 0;
		}
		
	pid2=fork();
	if(pid2==0){
		program2();
		return 0;
	}
	
	wait(NULL);
	wait(NULL);

		printf("Ana süreç sonlandı");
	
	return 0;
	
}

