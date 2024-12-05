/*************************************************************************
	> File Name: myserver.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 02 Dec 2024 08:57:51 PM CST
 ************************************************************************/
#include <iostream> // 引⼊标准输⼊输出库
#include <map> // 引⼊标准映射容器库
#include <functional>// 引⼊函数对象库，⽤于定义函数类型
#include <string> // 引⼊字符串处理库
#include <sys/socket.h> // 引⼊socket编程接⼝
#include <stdlib.h> // 引⼊标准库，⽤于通⽤⼯具函数
#include <netinet/in.h> // 引⼊⽹络字节序转换函数
#include <string.h> // 引⼊字符串处理函数
#include <unistd.h> // 引⼊UNIX标准函数库

//测试命令curl http://localhost:8080/register
#define PORT 8080

using RequestHandler = std::function<std::string(const std::string&)>;//定义请求处理函数类型

std::map<std::string, RequestHandler> route_table; //定义路由表,映射路径到对应的处理函数

//初始化路由表
void setupRoutes()
{
	//根路径处理
	route_table["/"] = [](const std::string& request){
		return "HelloWorld";
	};

	//注册处理
	route_table["/register"] = [](const std::string& request){
		//TODO: 实现用户注册逻辑
		return "RegisterSuccess!";
	};

	//登录处理
	route_table["/login"] = [](const std::string& request){
		//TODO: 实现用户注册逻辑
		return "Loginsuccess!";
	};

	//TODO : 添加其他路径和处理函数
}

int main()
{
	int server_fd, new_socket;//声明服务器的socket描述符和新客户端连接的socket描述符
	struct sockaddr_in address;//声明用于存储IPv4地址信息的结构体
	int addrlen = sizeof(address);//获取地址结构的长度,用于后续函数调用中

	//创建服务器的socket
	//AF_INET表示IPv4协议簇,SOCK_STREAM表示使用TCP传输协议
	//返回的server_fd是服务器的socket描述符,用于监听和处理客户端连接
	server_fd = socket(AF_INET, SOCK_STREAM, 0);

	//设置服务器地址结构体
	address.sin_family = AF_INET;//设置地址簇为IPv4
	address.sin_addr.s_addr = INADDR_ANY;//服务器绑定到本地机器的所有可用网络接口
	address.sin_port = htons(PORT);//设置服务器端口号,使用htons确保端口号的字节序正确(主机字节序转换成网络字节序)

	//将服务器的socket绑定到指定到IP地址和端口号
	//这一步确保服务器监听在指定的网络接口上
	bind(server_fd, (struct sockaddr *)&address, sizeof(address));

	//设置服务器的socket为监听模式
	//其中，第二个参数为等待连接队列的最大长度,表示最多有三个未处理连接请求可以排队等待
	listen(server_fd, 3);

	//初始化路由表,用于定义不同的URI对应的处理函数
	setupRoutes();

	//服务器主循环,持续运行以处理客户端连接
	while(true){
		//等待并接受来自客户端的连接请求
		//如果有客户端连接请求,accept会返回一个新的socket描述符,用于与该客户端通信
		new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);

		//初始化缓冲区并读取客户端发送的数据
		//这里假设最大请求大小为1024字节
		char buffer[1024] = {0};
		read(new_socket, buffer, 1024);//读取数据到buffer中
		std::string request(buffer);//将buffer转换为std::string便于处理

		//解析HTTP请求中的URI
		//从HTTP请求字符串中提取出请求行中的URI部分
		//假设HTTP请求的第一行格式为"METHOD URI HTTP/1.1"
		std::string uri = request.substr(request.find(" ") + 1);//获取第一个空格后的内容
		uri = uri.substr(0, uri.find(" "));//获取URI的结尾(即下一个空格前的部分)

		//根据请求的URI在路由表中查找对应的处理函数,并生成响应内容
		std::string response_body;
		if(route_table.count(uri) > 0) { //将路由表中存在该URI
			response_body = route_table[uri](request); //调用相应的处理函数，并将返回值作为响应部分
		}
		else{
			response_body = "404 Not Found";//如果路由表中没有匹配的URI，返回404响应
		}

		//构造HTTP响应,状态码为200 OK，内容类型为text/plain
		std::string response = "HTTP/1.1 200 OK\n\nContent-Type: text/plain\n\n" + response_body;
		//通过socket发送响应到客户端
		send(new_socket,response.c_str(), response.size(), 0);

		// TODO: 实现多线程处理来提⾼性能
		// TODO: 添加⽇志系统以记录请求和响应
		// TODO: 实现更完善的错误处理机制

		// 处理完请求后关闭与客户端的连接，释放资源
		close(new_socket);
	}
	return 0;
}

