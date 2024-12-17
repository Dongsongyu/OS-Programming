/*************************************************************************
	> File Name: myserver.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 17 Dec 2024 10:13:44 PM CST
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
//#include "logger.h"
#include "Database.h"

//测试命令curl http://localhost:8080/register
#define PORT 8080

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
std::pair<std::string, std::string> parseHttpRequest(const std::string& request){
	LOG_INFO("Parsing HTTP request"); //记录了请求解析
	//找到第一个空格,确定HTTP方法的结束位置
	size_t method_end = request.find(" ");
	//提取HTTP方法(如GET、POST)
	std::string method = request.substr(0, method_end);

	//找到第二个空格,确定URI的结束位置
	size_t uri_end = request.find(" ", method_end + 1);
	//提取URI(统一资源标识符)
	std::string uri = request.substr(method_end + 1, uri_end - method_end - 1);

	//返回解析出的HTTP方法和URI
	return {method, uri};
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

int main()
{
	int server_fd, new_socket;//声明服务器的socket描述符和新客户端连接的socket描述符
	struct sockaddr_in address;//声明用于存储IPv4地址信息的结构体
	int addrlen = sizeof(address);//获取地址结构的长度,用于后续函数调用中

	//创建服务器的socket
	server_fd = socket(AF_INET, SOCK_STREAM, 0);

	//设置服务器地址结构体
	address.sin_family = AF_INET;//设置地址簇为IPv4
	address.sin_addr.s_addr = INADDR_ANY;//服务器绑定到本地机器的所有可用网络接口
	address.sin_port = htons(PORT);//设置服务器端口号,使用htons确保端口号的字节序正确(主机字节序转换成网络字节序)

	//将服务器的socket绑定到指定到IP地址和端口号
	bind(server_fd, (struct sockaddr *)&address, sizeof(address));

	//设置服务器的socket为监听模式
	listen(server_fd, 3);

	//初始化路由表,用于定义不同的URI对应的处理函数
	setupRoutes();

	//服务器主循环,持续运行以处理客户端连接
	while(true){
		//等待并接受来自客户端的连接请求
		new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);

		//初始化缓冲区并读取客户端发送的数据
		char buffer[1024] = {0};
		read(new_socket, buffer, 1024);//读取数据到buffer中
		std::string request(buffer);//将buffer转换为std::string便于处理

		//解析请求
		auto [method, uri] = parseHttpRequest(request);

		//处理请求
		std::string response_body = handleHttpRequest(method, uri, request);
		
		// 如果返回的是"404 NOT Found"
		if (response_body == "404 NOT Found") {
			std::string response = "HTTP/1.1 404 Not Found\r\nContent-Type: text/plain\r\n\n" + response_body;
			send(new_socket, response.c_str(), response.size(), 0);
		} 
		else {
			std::string response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\n" + response_body;
			send(new_socket, response.c_str(), response.size(), 0);
		}

		// TODO: 实现多线程处理来提⾼性能
		// TODO: 添加⽇志系统以记录请求和响应
		// TODO: 实现更完善的错误处理机制

		// 处理完请求后关闭与客户端的连接，释放资源
		close(new_socket);
	}
	return 0;
}


