/*************************************************************************
	> File Name: socket.h
	> Author: 
	> Mail: 
	> Created Time: Sun 13 Oct 2024 04:17:23 PM CST
 ************************************************************************/

#ifndef _SOCKET_H
#define _SOCKET_H
#include <netinet/in.h>  // 确保包含 struct sockaddr_in 的定义
//服务器
//int bindSocket(int lfd, unsigned short port);
//绑定+监听
int setListen(int lfd, unsigned short port);
int accetpConn(int lfd, struct sockaddr_in *addr);

//客户端
int connectToHost(int fd, const char* ip, unsigned short port);

//共用
int createSocket();
int sendMsg(int fd, const char* msg, int len);
int recvMsg(int fd, char** msg);
int closeSocket(int fd);

#endif
