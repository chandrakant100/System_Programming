#include<fcntl.h>
int main()
{
	int fd1,fd2,n;
	char buf[1024];

	fd1=open("testwrite.txt",O_RDONLY|O_CREAT);
	if(fd1 == -1)
		{
			perror("ERROR1");
			return 1;
		}
	
	fd2=open("backup.txt",O_WRONLY | O_CREAT);
        if(fd2 == -1)
                {
                        perror("ERROR2");
                        return 1;
                }

	while((n=read(fd1,buf,1024)) > 0)
	{
		write(fd2,buf,n); //STDERR_FILENO,STDIN_FILENO,STDOUT_FILENO
	}
	close(fd1);
	close(fd2);
return 0;}
