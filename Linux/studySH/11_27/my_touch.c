#include<sys/types.h>
#include<utime.h>

int main(int argc, char* argv[]){
	if(argv<2) return 1;
	utime(argv[1], 0);
	return 0;
}
