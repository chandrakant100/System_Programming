#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    int num;
    write(1,"Enter the data:(press ctrl+d to exit):",38);
    char *buf=(char *)malloc(100*sizeof(char));

    while(num=read(1,buf,100))
    {
                write(1,buf,num);
    }    
    return 0;
}