/*************************************************************************
	> File Name: 5_10.union.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 19 Dec 2024 07:45:35 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

union Test {
	// string str;
	// Base b;
	static int num;
	static void print() {
		num = 1000;
	} //只能访问静态成员变量
	//不允许出现引用
	int num1;
};

int Test::num = 10;

class Teacher {
public:
	Teacher() {}
	void setText(string s) {
		name = s;
	}
private:
	string name;
};

//联合体所有成员变量共用同一个内存
union Student {
	Student() {
		new (&name)string;
	}
	~Student() {}
	int id;
	Teacher t;
	string name;
};

struct Foreigner {
	Foreigner(string a, string p) : addr(a), phone(p) {}
	string addr;
	string phone;
};

class Person {
public:
	enum class Category:char{Student, Local, Foreign};
	Person(int num) : number(num), c(Category::Student) {}
	Person(string str) : idNum(str), c(Category::Local) {}
	Person(string a, string p) : fore(a, p), c(Category::Foreign) {}
	~Person() {}
	void print() {
		switch(c) {
			case Category::Student:
			cout << "Student school number: " << number << endl;
			break;
			case Category::Local:
			cout << "Local people ID number: " << idNum << endl;
			break;
			case Category::Foreign:
			cout << "Foreigner address: " << fore.addr 
				<< ", phone: " << fore.phone << endl;
			break;
		}
	}
private:
	Category c;
	union {
		int number;
		string idNum;
		Foreigner fore;
	};
};

int main()
{
	Person p1(9727);
	Person p2("111122233XY");
	Person p3("砂隐村","17839043922");
	p1.print();
	p2.print();
	p3.print();
	cout << endl << endl << endl;

	Student s;
	s.name = "Lucy";
	s.t.setText("Daming");
	cout << "s.name = " << s.name << endl;
#if 0
	//不管联合体创建多少实例对象,Test静态成员变量有且只有一份
	Test t1;
	t1.num1 = 100;
	cout << t1.num << endl;
	cout << t1.num1 << endl;

	Test t2;
	t2.num = 50;
	cout << t2.num << endl;
	cout << t1.num << endl;
	t1.print();
#endif

	return 0;
}