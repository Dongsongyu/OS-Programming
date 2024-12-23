/*************************************************************************
	> File Name: myserver.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 21 Dec 2024 03:18:35 PM CST
 ************************************************************************/

#include <iostream> // 引⼊标准输⼊输出库
#include <map> // 引⼊标准映射容器库
#include <functional>// 引⼊函数对象库，⽤于定义函数类型
#include <string> // 引⼊字符串处理库
#include <sys/socket.h> // 引⼊socket编程接⼝
#include <sys/epoll.h> //
#include <stdlib.h> // 引⼊标准库，⽤于通⽤⼯具函数
#include <netinet/in.h> // 引⼊⽹络字节序转换函数
#include <string.h> // 引⼊字符串处理函数
#include <fcntl.h>
#include <unistd.h> // 引⼊UNIX标准函数库
#include <sstream>
//#include "logger.h"
#include "Database.h"

//测试命令curl http://localhost:8080/register
#define PORT 8080
#define MAX_EVENTS 100

using RequestHandler = std::function<std::string(const std::string&)>;//定义请求处理函数类型

//分别为GET和POST请求设置路由表
std::map<std::string, RequestHandler> get_routes;
std::map<std::string, RequestHandler> post_routes;
Database db("users.db");//创建数据库连接对象


//parseFormBody函数中使用
std::map<std::string, std::string> parseFormBody(const std::string& body) {
	std::map<std::string, std::string> params;
	std::istringstream stream(body);
	std::string pair;

	LOG_INFO("parsing body: %s", body.c_str());

	while(std::getline(stream, pair, '&')) {
		std::string::size_type pos = pair.find('=');
		if(pos != std::string::npos) {
			std::string key = pair.substr(0, pos);
			std::string value = pair.substr(pos+1);
			params[key] = value;
			LOG_INFO("Parsed key_value pair: %s = %s", key.c_str(), value.c_str());
		} else {
			//错误处理
			std::string error_msg = "Error parsing: " + pair;
			LOG_ERROR(error_msg.c_str());
			std::cerr << error_msg << std::endl;
		}
	}
	return params;
}

//初始化路由表
void setupRoutes()
{
	LOG_INFO("Setting up routes");//记录路由位置
	//GET请求处理
	//根路径处理
	get_routes["/"] = [](const std::string& request){
		return "HelloWorld";
	};

	//注册处理
	get_routes["/register"] = [](const std::string& request){
		LOG_ERROR("Please use POST to register!");
		//TODO: 实现用户注册逻辑
		return "Please use POST to register!";
	};

	//登录处理
	get_routes["/login"] = [](const std::string& request){
		LOG_ERROR("Please use POST to login!");
		//TODO: 实现用户登录逻辑
		return "Please use POST to login!";
	};

	//POST请求处理
	post_routes["/register"] = [](const std::string& request){
		//解析用户名和密码
		//例如从请求中解析username和password
		auto params = parseFormBody(request);
		std::string username = params["username"];
		std::string password = params["password"];
		
		//调用数据库方法进行注册
		if(db.registerUser(username, password)) {
			return "Register Success!";
		} else {
			return "Register Failed!";
		}
	};

	post_routes["/login"] = [](const std::string& request){
		//解析用户名和密码
		//例如从请求中解析username和password
		auto params = parseFormBody(request);
		std::string username = params["username"];
		std::string password = params["password"];
		
		//调用数据库方法进行注册
		if(db.loginUser(username, password)) {
			return "Login Success!";
		} else {
			return "Login Failed!";
		}
	};
	//TODO : 添加其他路径和处理函数
}

//解析http请求
std::tuple<std::string, std::string, std::string> parseHttpRequest(const std::string& request){
	LOG_INFO("Parsing HTTP request"); //记录了请求解析
	//找到第一个空格,确定HTTP方法的结束位置
	size_t method_end = request.find(" ");
	//提取HTTP方法(如GET、POST)
	std::string method = request.substr(0, method_end);

	//找到第二个空格,确定URI的结束位置
	size_t uri_end = request.find(" ", method_end + 1);
	//提取URI(统一资源标识符)
	std::string uri = request.substr(method_end + 1, uri_end - method_end - 1);

	//提取请求体(对于post请求)
	std::string body;
	if(method == "POST") {
		size_t body_start = request.find("\r\n\r\n");
		if(body_start != std::string::npos) {
			body = request.substr(body_start + 4);
		}
	}
	//返回解析出的HTTP方法和URI
	return {method, uri, body};
}

//处理HTTP请求
std::string handleHttpRequest(const std::string& method, const std::string& uri, const std::string& body){
	LOG_INFO("Handling HTTP request for URI : %s", uri.c_str()); //记录请求处理
	//检查GET请求和URI是否在路由表中
	if(method == "GET" && get_routes.count(uri) > 0) {
		//根据URI调用相应的处理函数
		return get_routes[uri](body);
	}
	//检查POST请求和URI是否在路由表中
	else if (method == "POST" && post_routes.count(uri) > 0) {
		//根据URI调用相应的处理函数
		return post_routes[uri](body);
	}

	//如果请求方法和URI不匹配任何路由,则返回404错误
	else {
		LOG_ERROR("404 NOT Found");
		return "404 NOT Found";
	}
}

//设置非阻塞模式的函数
void setNonBlocking(int sock) {
	int opts = fcntl(sock, F_GETFL);//获取文件描述符的状态标志
	if(opts < 0) {
		LOG_ERROR("fcntl(F_GETFL) failed on socket %d: %s", sock, strerror(errno));//记录详细错误信息
		exit(EXIT_FAILURE);
	}
	opts != O_NONBLOCK;//设置非阻塞标志
	if(fcntl(sock, F_SETFL, opts) < 0) {
		LOG_ERROR("fcntl(F_GETFL) failed on socket %d: %s", sock, strerror(errno));
		exit(EXIT_FAILURE);
	}
	LOG_INFO("Set socket %d to non-blocking", sock);
}

//处理客户端请求的函数
void handleClientSocket(int client_fd) {
	char buffer[4096];
	std::string request;

	//读取数据直到没有更多可读数据
	while (true) {
		ssize_t bytes_read = read(client_fd, buffer, sizeof(buffer) - 1);
		if (bytes_read > 0) {
			buffer[bytes_read] = '\0';
			request += buffer;
		} else if (bytes_read == -1 && (errno == EAGAIN || errno == EWOULDBLOCK)) {
			//没有更多数据可读,退出循环
			break;
		} else {
			//发生错误或连接关闭
			LOG_ERROR("Read error or connection closed on fd %d", client_fd);
			close(client_fd);
			return ;
		}
	}

	//解析并请求请求
	if (!request.empty()) {
		auto [method, uri, body] = parseHttpRequest(request);
		std::string response_body = handleHttpRequest(method, uri, body);
		std::string response = "Http/1.1 200 OK\nContent-Type: text/plain\n";
		send(client_fd, response.c_str(), response.length(), 0);
	}

	//关闭客户端连接
	close(client_fd);
	LOG_INFO("Closed connection on fd %d", client_fd);
}

int main()
{
	int server_fd, new_socket;//声明服务器的socket描述符和新客户端连接的socket描述符
	struct sockaddr_in address;//声明用于存储IPv4地址信息的结构体
	int addrlen = sizeof(address);//获取地址结构的长度,用于后续函数调用中
	struct epoll_event ev, events[MAX_EVENTS];//epoll_event结构体用于描述
	int epollfd;

	//创建服务器的socket
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == -1) {
		LOG_ERROR("Socket creation failed");
		return -1;
	}
	setNonBlocking(server_fd); //设置服务器套接字为非阻塞模式
	LOG_INFO("Socket created");

	//设置服务器地址结构体
	address.sin_family = AF_INET;//设置地址簇为IPv4
	address.sin_addr.s_addr = INADDR_ANY;//服务器绑定到本地机器的所有可用网络接口
	address.sin_port = htons(PORT);//设置服务器端口号,使用htons确保端口号的字节序正确(主机字节序转换成网络字节序)

	//将服务器的socket绑定到指定到IP地址和端口号
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
		LOG_ERROR("Bind failed");
		return -1;
	}

	//设置服务器的socket为监听模式
	if (listen(server_fd, 3) < 0) {
		LOG_ERROR("Listen failed");
		return -1;
	}
	LOG_INFO("Server listening on port %d", PORT);

	//初始化路由表,用于定义不同的URI对应的处理函数
	setupRoutes();
	LOG_INFO("Routes set up");

	//创建epoll实例
	epollfd = epoll_create1(0);//创建一个新的epoll实例
	if(epollfd == -1) {
		LOG_ERROR("epoll_createl failed");
		return -1;
	}
	LOG_INFO("Epoll instance created with fd %d", epollfd);

	//配置服务器套接字的epoll事件
	ev.events = EPOLLIN | EPOLLET;//监听可读事件并启用边缘触发
	ev.data.fd = server_fd;//关联服务器套接字
	if (epoll_ctl(epollfd, EPOLL_CTL_ADD, server_fd, &ev) == -1) {
		LOG_ERROR("Failed to add server_fd to epoll");
		exit(EXIT_FAILURE);
	}
	LOG_INFO("Server socket added to epoll instance");

	//服务器主循环,持续运行以处理客户端连接
	while(true){
		LOG_INFO("Waiting for events...");
		int nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);//等待事件
		if(nfds == -1) {
			LOG_ERROR("epoll_wait failed");
			exit(EXIT_FAILURE);
		}
		LOG_INFO("%d events ready", nfds);

		//遍历发生事件的文件描述符
		for (int n = 0; n < nfds; ++n) {
			if (events[n].data.fd == server_fd) {
				LOG_INFO("Server socket event triggered");
				while((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) != -1) {
					setNonBlocking(new_socket);//设置客户端套接字为非阻塞
					ev.events = EPOLLIN | EPOLLET;//监听可读事件,启用边缘触发
					if(epoll_ctl(epollfd, EPOLL_CTL_ADD, new_socket, &ev) == -1){
						LOG_ERROR("Failed to add new socket to epoll");
						close(new_socket);
					}
					LOG_INFO("New connection accepted : fd %d", new_socket);
				}

				if(new_socket == -1 && errno != EAGAIN && errno != EWOULDBLOCK) {
					LOG_ERROR("Accept returned error: %d", errno);
				}
			} else {
				//如果是客户端套接字,处理客户端请求
				LOG_INFO("Handling client socket event: fd %d", events[n].data.fd);
				handleClientSocket(events[n].data.fd);
			}
		}
	}

	close(server_fd);
	LOG_INFO("Server shutdown");
	return 0;
}

