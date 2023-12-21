#include<unistd.h>
#include<fcntl.h>

int main(void){
	int fd;

	fd = creat("holefile",0644);
	write(fd, "hello",5);
	lseek(fd,10,SEEK_CUR);
	write(fd, "world",5);
	lseek(fd,8192,SEEK_SET);
	write(fd,"bye",3);
	close(fd);
	return 0;
}
