#include<fcntl.h>
int main()
{
	int fd1,fd2,fd3,num;
	char buf[1040];

	fd1=open("new.txt",O_CREAT|O_WRONLY|O_RDONLY);
	fd2=open("testwrite.txt",0660);
	
	if(fd1 ==- 1)
		{
			perror("ERROR1!");
			return 1;
		}
	
	if(fd2 ==- 1)
		{
			perror("ERROR2!");
			return 1;
		}	
	while((num=read(fd2,buf,1040)) > 0)
	{
		write(fd1,buf,num);
	}
	write(1,"Successully copied ist file",27);
	close(fd1);
	close(fd2);

	fd3=open("backup.txt",0660);
	fd1=open("new.txt",O_APPEND|O_WRONLY|O_RDONLY);

	while((num=read(fd3,buf,1040)) > 0)
		{
			write(fd1,buf,num);
		}
	write(1,"Successully copied 2nd file",27);
	
	close(fd1);
	close(fd3);
	return 0;
}
