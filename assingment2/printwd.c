#include <stdio.h>
#include<string.h>

#define pathlen 200
int main(int argc,char **argv)
{
    char path[pathlen];
    char buf[100];
    getcwd(path,pathlen);

    sprintf(buf,"%s",path);
    write(1,buf,strlen(buf));    

    return 0;
}

