/*************************************************************************
	> File Name: pool_socket/client.c
	> Author: 
	> Mail: 
	> Created Time: Sun 13 Oct 2024 04:47:11 PM CST
 ************************************************************************/

#include<stdio.h>
#include<fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include<pthread.h>
#include "socket.h"

int main()
{
    //1.创建用于通信的套接字
    int fd = createSocket();
    if(fd == -1){
        return -1;
    }

    //2.连接服务器
    int ret = connectToHost(fd, "106.54.35.218", 10000);
    if(ret == -1){
        return -1;
    }

    //3.通信
    int fd1 = open("english.txt", O_RDONLY);
    int length = 0;
    char tmp[1000];
    while((length = read(fd1, tmp, rand() % 1000)) > 0){
        //发送数据
        sendMsg(fd, tmp, length);

        //接收数据
        memset(tmp, 0, sizeof(tmp));
        usleep(300);
    }
    sleep(10);
    //关闭文件描述符
    closeSocket(fd);

    return 0;
}
