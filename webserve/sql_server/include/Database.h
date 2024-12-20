/*************************************************************************
	> File Name: Database.h
	> Author: 
	> Mail: 
	> Created Time: Tue 17 Dec 2024 10:13:31 PM CST
 ************************************************************************/

#include<sqlite3.h>
#include<Logger.h>
#include<string>

class Database {
private:
	sqlite3* db;

public:
	//构造函数,用于打开数据库并创建用户表
	Database(const std::string& db_path) {
		if(sqlite3_open(db_path.c_str(), &db) != SQLITE_OK) {
			throw std::runtime_error("Failed to open database");
		}
		//创建用户表的sql语句
		const char* sql = "create table if not exists users (username TEXT PRIMARY KEY, password TEXT);";
		char* errmsg;
		// sqlite3_exec是sqlite C API中的一个函数,用于执行一条或一组sql命令，并处理结果
		//这里如果执行sqlite3_exec 函数并尝试执行sql命令时发生任何错误
		//那么该条件将会成立,程序可能接下来会进行错误处理，比如打印或显示由errmsg指向的错误信息
		if(sqlite3_exec(db, sql, 0, 0, &errmsg) != SQLITE_OK) {
			throw std::runtime_error("Failed to create table: " + std::string(errmsg));
		}
	}

	//析构函数,用于关闭数据库连接
	~Database() {
		sqlite3_close(db);
	}

	//用户注册函数
	bool registerUser(const std::string& username, const std::string& password) {
    std::string sql = "insert into users (username, password) values (?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        LOG_INFO((std::string("Failed to prepare registration SQL for user: ") + username).c_str());
        return false;
    }

    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        LOG_INFO((std::string("Registration failed for user: ") + username).c_str());
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    LOG_INFO((std::string("User registered: ") + username + " with password: " + password).c_str());
    return true;
}

//用户登录函数
bool loginUser(const std::string& username, const std::string& password) {
    std::string sql = "select password from users where username = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        LOG_INFO((std::string("Failed to prepare login SQL for user: ") + username).c_str());
        return false;
    }

    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_ROW) {
        LOG_INFO((std::string("User not found: ") + username).c_str());
        sqlite3_finalize(stmt);
        return false;
    }

    const char* stored_password = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    if (stored_password == nullptr || password != std::string(stored_password)) {
        LOG_INFO((std::string("Login failed for user: ") + username + " with password: " + password).c_str());
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    LOG_INFO((std::string("User logged in: ") + username).c_str());
    return true;
}
};
