#include<fcntl.h>
int main()
{
	int fd1,n;
	char buf[1024];

	fd1=open("testwrite.txt",O_RDONLY|O_WRONLY| O_APPEND);
	if(fd1 == -1)
		{
			perror("ERROR1");
			return 1;
		}
	write(1,"Enter (press ctrl+d to end):",28);	
	while((n=read(1,buf,1024)))
	{
		write(fd1,buf,n); 
	}
	close(fd1);
return 0;}
