/*************************************************************************
	> File Name: 4_7.weak_ptr.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 17 Dec 2024 07:07:59 PM CST
 ************************************************************************/

#include<iostream>
#include<memory>
using namespace std;

/*
*shared_ptr注意事项:
*不能使用一个原始地址初始化多个共享智能指针
*函数不能返回管理了this的共享智能指针对象
*共享智能指针对象不能循环使用(乱伦:存在包含和被包含的关系 )
*/

struct Test : public enable_shared_from_this<Test> {
	shared_ptr<Test> getSharedPtr() {
		return shared_from_this();
	}
	~Test() {
		cout << "class Test is disstruct ..." << endl;
	}
};

int main()
{
	// Test* t = new Test;
	// shared_ptr<Test> ptr1(t);
	// shared_ptr<Test> ptr2 = ptr1;

	shared_ptr<Test> sp1(new Test);
	cout << "use_count : " << sp1.use_count() << endl;
	shared_ptr<Test> sp2 = sp1->getSharedPtr();
	cout << "use_count : " << sp2.use_count() << endl;

	return 0;
}