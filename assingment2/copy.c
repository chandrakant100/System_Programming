#include<unistd.h>
#include<fcntl.h>

int main(int argc,char **argv)
{
	int fd=open(argv[1],O_RDONLY);
	int n;
	char buf[100];

	if(argc!=3)
	{
		perror("Invalid arguments!!!");
		return 1;
	}	
	if(fd== -1)
        {
                perror("1st File does not exist!!");
                return 1;
        }


	int fd2=open(argv[2],O_WRONLY);

	if(fd2 == -1)
        {
                perror("2nd File does not exist!!");
                return 1;
        }


	while((n=read(fd,buf,100)) > 0)
		write(fd2,buf,n);

	close(fd);
	close(fd2);
	
return 0;
}


