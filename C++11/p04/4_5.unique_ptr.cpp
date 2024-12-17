/*************************************************************************
	> File Name: 4_5.unique_ptr.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 17 Dec 2024 06:49:18 PM CST
 ************************************************************************/

#include<iostream>
#include<memory>
#include<functional>
using namespace std;

class Test {
public:
	Test() {
		cout << "construct Test..." << endl;
	}
	Test(int x) : m_num(x) {
		cout << "construct Test, x = " << x << endl;
	}
	Test(string str) {
		cout << "construct Test, str = " << str << endl;
	}
	~Test() {
		cout << "destruct Test..." << endl;
	}
	void setValue(int v) {
		m_num = v;
	}
	void print() {
		cout << "m_num : " << m_num << endl;
	}
private:
	int m_num;
};

int main()
{
	//通过构造函数初始化
	unique_ptr<int> ptr1 (new int(9));
	//通过移动构造函数初始化
	unique_ptr<int> ptr2 = move(ptr1);
	//通过reset初始化
	ptr2.reset(new int (8));
	//获取原始指针
	unique_ptr<Test> ptr3(new Test (1));
	Test* pt = ptr3.get();
	pt->setValue(2);
	pt->print();

	ptr3->setValue(4);
	ptr3->print();

	using ptrFunc = void(*) (Test *);//删除器的类型
	unique_ptr<Test, function<void(Test *)>> ptr4(new Test("hello"), [=] (Test* t) {
		cout << "----------------------" << endl;
		delete t;
	});

	//独占的智能指针可以管理数组类型的地址,能够自动释放
	unique_ptr<Test []> ptr5(new Test[3]);
	//在C++11中shared_ptr不支持下面的写法,c++11 以后才被支持
	shared_ptr<Test []> ptr6(new Test[3]);

	return 0;
}