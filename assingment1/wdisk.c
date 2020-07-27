#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    int num;
    write(1,"Enter the data:(press ctrl+d to exit):",38);
    char *buf=(char *)malloc(sizeof(char));

    int fd=open("file.txt",O_RDONLY | O_WRONLY| O_CREAT);
    while(num=read(1,buf,1))
    {
                write(fd,buf,num);
    } 
    close(fd);   
    return 0;
}