#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define TOKEN_SIZE 20
#define DELIM      "/\0"
#define BUFF_SIZE  512
#define PATH_SIZE  200

int main(int argc, char *argv[]) {

    char src[PATH_SIZE];
    char srcDir[PATH_SIZE];
    char *token[TOKEN_SIZE];
    char buff[BUFF_SIZE];

    int fd1;
    int fd2;
    int count = 1;
    int check = 0;

    if (argc != 3) {
        write(STDERR_FILENO, "Usage: ./move source dest\n", 27);
        return 1;
    }

    if ((fd1 = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        return 1;
    }

    strcpy(src, argv[1]);

    token[0] = strtok(src, DELIM);
    while((token[count] = strtok(NULL, DELIM)) != NULL)
        count++;

    if (strcmp(token[0], argv[1]) == 0) {
        getcwd(srcDir, PATH_SIZE);
        check = 1;
    }

    if (chdir(argv[2]) == -1) {
        perror(argv[2]);
        close(fd1);
        return 1;
    }

    if ((fd2 = open(token[count - 1], O_WRONLY | O_CREAT | O_EXCL, 0644)) == -1) {
        perror(token[count - 1]);
        close(fd1);
        return 1;
    }

    while(count = read(fd1, buff, BUFF_SIZE))
        write(fd2, buff, count);

    close(fd1);
    close(fd2);

    if (check) {
        chdir(srcDir);
        unlink(argv[1]);
    } else {
        unlink(argv[1]);
    }

    return 0;
}