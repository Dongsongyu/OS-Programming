/*************************************************************************
	> File Name: 4_2.shared_ptr.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 17 Dec 2024 06:09:06 PM CST
 ************************************************************************/

#include<iostream>
#include<memory>
using namespace std;

//删除器模板
template<typename T>
shared_ptr<T> make_share_array(size_t size) {
	//返回匿名对象
	return shared_ptr<T>(new T[size], default_delete<T[]> ());
}

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
	//通过构造函数来初始化
	shared_ptr<int> ptr1(new int(3));
	cout << "ptr1 use_count : " << ptr1.use_count() << endl;
	//通过移动构造和拷贝构造函数初始化
	shared_ptr<int> ptr2 = move(ptr1);
	cout << "ptr1 use_count : " << ptr1.use_count() << endl;
	cout << "ptr2 use_count : " << ptr2.use_count() << endl;

	shared_ptr<int> ptr3 = ptr2;
	cout << "ptr3 use_count : " << ptr3.use_count() << endl;
	cout << "ptr2 use_count : " << ptr2.use_count() << endl;

	//通过make_shared初始化
	shared_ptr<int> ptr4 = make_shared<int>(8);
	shared_ptr<Test> ptr5 = make_shared<Test>(8);
	shared_ptr<Test> ptr6 = make_shared<Test>("Hello world!");

	//通过reset初始化
	ptr6.reset();//指针重置
	cout << "ptr6 use_count : " << ptr6.use_count() << endl;

	ptr5.reset(new Test(99));
	cout << "ptr5 use_count : " << ptr5.use_count() << endl;

	//获取原始指针
	Test *t = ptr5.get();
	t->setValue(1000);
	t->print();

	ptr5->setValue(999);
	ptr5->print();
	
	shared_ptr<Test> ppp(new Test(100), [] (Test *t) {
		//释放内存的操作
		cout << "----------------------" << endl;
		delete t;
	});

	// shared_ptr<Test> p1(new Test[5], [] (Test *t){
	// 	delete []t;
	// });

	shared_ptr<Test> p2(new Test[5], default_delete<Test []>());

	shared_ptr<Test> p3 = make_share_array<Test> (2);
	cout << p3.use_count() << endl;

	return 0;
}