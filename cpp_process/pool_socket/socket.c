/*************************************************************************
	> File Name: socket.c
	> Author: 
	> Mail: 
	> Created Time: Sun 13 Oct 2024 04:23:26 PM CST
 ************************************************************************/

#include<stdio.h>
#include "socket.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include<pthread.h>

//创建监听的套接字
int createSocket()
{
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd == -1){
        perror("socket");
        exit(0);
    }
    printf("套接字创建成功, fd = %d\n", lfd);
    return lfd;
}

//绑定本地的ip和端口,设置监听
int setListen(int lfd, unsigned short port)
{
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(10000);
    addr.sin_addr.s_addr = INADDR_ANY;//0 = 0.0.0.0
    int ret = bind(lfd, (struct sockaddr*)&addr, sizeof(addr));
    if(ret == -1)
    {
        perror("bind");
        exit(0);
    }

    // 3. 设置监听
    ret = listen(lfd, 128);
    if(ret == -1)
    {
        perror("listen");
        exit(0);
    }
    printf("设置监听成功\n");
    return ret;
}

//阻塞并等待客户端的连接
int accetpConn(int lfd, struct sockaddr_in *addr)
{
    int cfd = -1;
    if(addr == NULL){
        cfd = accept(lfd, NULL, NULL);
    }
    else{
        int addrlen = sizeof(struct sockaddr_in);
        cfd = accept(lfd, (struct sockaddr*)addr, &addrlen);
    }
    if(cfd == -1){
        perror("accept");
        return -1;
    }
    printf("成功和客户端连接..\n");
    return cfd;
}

//接收指定字节个数的字符串
int readn(int fd, char* buf, int size)
{
    char* pt = buf;
    int count = size;
    while(count > 0){
        int len = recv(fd, pt, count, 0);
        if(len == -1){
            return -1;
        }
        else if(len == 0){
            return size = count;
        }
        pt += len;
        count -= len;
    }
    return size;
}

//接收数据
int recvMsg(int cfd, char** msg)
{
    int len = 0;
    readn(cfd, (char*)&len, 4);
    len = ntohs(len);
    printf("要接收的数据块的大小:%d\n", len);

    char* data = (char*)malloc(len + 1);
    int length = readn(cfd, data, len);
    if(length != len)
    {
        printf("接收数据失败...\n");
        close(cfd);
        free(data);
        return -1;
    }
    data[len] = '\0';
    *msg = data;

    return length;
}

//发送指定长度字符串
int writen(int fd, const char* msg, int size)
{
    const char* buf = msg;
    int count = size;
    while(count > 0){
        int len = send(fd, buf, count, 0);
        if(len == -1){
            return -1;
        }
        else if(len == 0){
            continue;
        }
        buf += len;
        count -= len;
    }
    return size;
}

//发送数据
int sendMsg(int cfd, const char* msg, int len)
{
    if(cfd < 0 || msg == NULL || len <= 0){
        return -1;
    }

    char* data = (char*)malloc(len + 4);
    int biglen = htons(len);
    memcpy(data, &biglen, 4);
    memcpy(data + 4, msg, len);

    int ret = writen(cfd, data, len+4);
    if(ret == -1){
        close(cfd);
    }
    return ret;
}

//连接服务器
int connectToHost(int fd,const char* ip, unsigned short port)
{
    //2.连接服务器ip port
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(10000);   // 大端端口
    inet_pton(AF_INET, "106.54.35.218", &addr.sin_addr.s_addr);

    int ret = connect(fd, (struct sockaddr*)&addr, sizeof(addr));
    if(ret == -1)
    {
        perror("connect");
        exit(0);
    }
    printf("成功和服务器建立连接...\n");
    return ret;
}

int closeSocket(int fd)
{
    int ret = close(fd);
    if(ret == -1){
        perror("close");
    }
    return ret;
}

