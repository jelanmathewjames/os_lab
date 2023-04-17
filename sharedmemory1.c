#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h>
#include <stdlib.h>
#define SHMSZ 27 
int main(){
	char C;
	int shmid,i;
	key_t key;
	char *shm, *s; 
	key = 5678;
	if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666))<0){
		perror("shmget"); 
		exit(1);
	}
	if ((shm = shmat(shmid, NULL, 0)) == (char *) -1){
		perror("shmat");
		exit(1);
	}
	for (s = shm,i=0;i<26; s++,i++) 
		*s='A'+i;
	*s='\0';
	shmdt(shm); 
	return 0;
}
