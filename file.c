#include<fcntl.h> 
#include<sys/types.h> 
#include<sys/stat.h> 
#include<stdlib.h> 
#include <stdio.h>

int close();
int lseek();
int read();
int write();
static char message[]="hai Hello world";
int main(){
	int fd;
	char buffer[80];
	fd=open("new2file.txt",O_RDWR|O_CREAT|O_EXCL,S_IREAD|S_IWRITE); 	  
	if(fd!=-1){
		printf("new2file.txt opened for read/write access\n");
		write(fd,message,sizeof(message)); 
		lseek(fd,0,0);
		if(read(fd,buffer,sizeof(message))==sizeof(message))
			printf("\"%s\" was written to new2file.txt\n",buffer); 			
		else
			printf("***Error reading new2file.txt***\n");
	}else{
		close(fd);
		printf("***new2file.txt already exists***\n"); 
		exit(0);
	}
}
