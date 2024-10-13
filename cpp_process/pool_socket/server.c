/*************************************************************************
	> File Name: pool_socket/server.c
	> Author: 
	> Mail: 
	> Created Time: Sun 13 Oct 2024 04:46:35 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include<pthread.h>
#include "socket.h"

//信息结构体
struct SockInfo
{
    struct sockaddr_in addr;
    int fd;
};

struct SockInfo infos[512];

void* working(void* arg)
{
    struct SockInfo* pinfo = (struct SockInfo*)arg;
    // 打印客户端的地址信息
    char ip[32] = {0};
    printf("客户端的IP地址: %s, 端口: %d\n",
           inet_ntop(AF_INET, &pinfo->addr.sin_addr.s_addr, ip, sizeof(ip)),
           ntohs(pinfo->addr.sin_port));
    // 5. 和客户端通信
    while(1)
    {
        // 接收数据
        char* buf;
        int len = recvMsg(pinfo->fd, &buf);
        printf("接收数据 : %d :...\n", len);
        if(len > 0)
        {
            printf("客户端say: %s\n", buf);
            free(buf);
        }
        else
        {
            break;
        }
        sleep(1);
    }
    pinfo->fd = -1;
    return NULL;
}

int main()
{
    int fd = createSocket();
    if(fd == -1){
        return -1;
    }

    int ret = setListen(fd, 10000);
    if(ret == -1){
        return -1;
    }

    int max = sizeof(infos) / sizeof(infos[0]);
    for(int i = 0; i < max; i++){
        bzero(&infos[i], sizeof(infos[0]));
        infos[i].fd = -1;
    }

    while(1){
        struct SockInfo* pinfo;
        printf("max : %d\n", max);
        for(int i = 0; i < max; ++i){
            if(infos[i].fd == -1){
                pinfo = &infos[i];
                break;
            }
        }
        pinfo->fd = accetpConn(fd, &pinfo->addr);
        //创建子线程
        pthread_t tid;
        pthread_create(&tid, NULL, working, pinfo);
        pthread_detach(tid);

    }

    close(fd);
}

