/*************************************************************************
	> File Name: 5.write.c
	> Author: 
	> Mail: 
	> Created Time: Sat 14 Dec 2024 04:59:58 PM CST
 ************************************************************************/

#include "./common/head.h"

int main()
{
    int fd, fd_out;
    if((fd = open("./x.c", O_RDWR | O_CREAT, 0644)) < 0) {
        perror("open");
        exit(1);
    }
    if ((fd_out = open("./x.x", O_RDWR | O_CREAT, 0644)) < 0) {
        perror("open fd_out");
        exit(1);
    }
    char buff[10] = {0};
    int buff_size = sizeof(buff);
    while(1){
        memset(buff, 0, buff_size);
        ssize_t rsize = read(fd, buff, buff_size - 1);
        if (rsize < 0) {
            perror("read");
            exit(1);
        } else if (rsize == 0) {
            break;
        } else {
            printf("%s", buff);
            write(fd_out, buff, rsize);
        }
    }
    close(fd);
    close(fd_out);
    return 0;
}
