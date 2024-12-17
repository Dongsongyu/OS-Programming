/*************************************************************************
	> File Name: 3_17.right.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 16 Dec 2024 06:08:15 PM CST
 ************************************************************************/

//g++ -fno-elide-constructors -std=c++11 3_17.right.cpp  
#include<iostream>
#include<list>
using namespace std;

class Test {
public:
	Test() : m_num(new int(100)) {
		cout << "construct: my name is jarry" << endl;
		printf("m_num 地址: %p\n", m_num);
	}
	Test(const Test &a) : m_num(new int (*a.m_num)) {
		cout << "copy construct : my name is tom" << endl;
	}

	//移动构造函数->复用其他对象中的资源(堆内存)
	//m_num, 浅拷贝
	Test(Test &&a) : m_num(a.m_num) {
		a.m_num = nullptr;
		cout << "move construct..." << endl;
	}
	~Test() {
		cout << "destruct Test class..." << endl;
		delete m_num;
	}

	int *m_num;
};

Test getObj() {
	Test t;
	return t;
}

Test getObj1() {
	return Test();
}

//会造成悬空指针
// Test && getobj2() {
// 	return Test();
// }

int main()
{
	//要求右侧的对象是一个临时对象,才会调用移动构造函数
	//如果没有移动构造函数,则会调用拷贝构造函数
	Test t = getObj();
	cout << endl;
	Test && t1 = getObj();
	printf("m_num 地址: %p\n", t1.m_num);

	//如果没有移动构造函数,使用右值引用初始化要求更高一些
	//要求右侧是一个临时的不能取地址的对象
	cout << endl;
	Test && t2 = getObj1();
	printf("m_num 地址: %p\n", t2.m_num);

	//左值转换为右值
	//资源转移,后面不再使用
	Test && t3 = move(t2);
	Test && t4 = move(t);

	list<string> ls1 {
		"hello","world","nihao","shijie",
		"ace","sabo","lucy"
	};
	list<string> ls2 = ls1;
	list<string> ls2 = move(ls1);

	return 0;
}