#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main(void){
	int fd, n;
	char buf[10];
	fd = open("testfile",O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd <0){
		perror("open");
		exit(1);
	}
	system("ls testfile");
	unlink("testfile");
	system("ls testfile");

	write(fd,"hello\n",6);
	lseek(fd,0,SEEK_SET);
	n= read(fd, buf,10);
	write(STDOUT_FILENO, buf,n);
	close(fd);
}
