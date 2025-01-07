/*************************************************************************
	> File Name: 7.visitor.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Jan 2025 07:39:23 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A;
class B;
class C;

class Base {
public:
	class IVisitor {
	public:
		virtual void visit(A *) = 0;
		virtual void visit(B *) = 0;
		virtual void visit(C *) = 0;
	};
	virtual void accept(IVisitor *) = 0;
	virtual ~Base() {}

	int x;
};

class A : public Base {
public:
	void accept(IVisitor *vis) override {
		// F(this): --> F(A *);
		vis->visit(this);
		return ;
	}
};
class B : public Base {
public:
	void accept(IVisitor *vis) override {
		// F(this): --> F(B *);
		vis->visit(this);
		return ;
	}
};
class C : public Base {
public:
	void accept(IVisitor *vis) override {
		// F(this): --> F(C *);
		vis->visit(this);
		return ;
	}
};

class DynamicVistor : public Base::IVisitor {
	void visit(A *obj) override {
		cout <<"Class A: dynamic_cast" << endl;
		return ;
	}
	void visit(B *obj) override {
		cout << "Class B : dynamic_cast" << endl;
		return ;
	}
	void visit(C *obj) override {
		cout << "Class C : dynamic_cast" << endl;
		return ;
	}
};

class AddVisitor : public Base::IVisitor {
public:
	void visit(A *obj) override {
		result = obj->x + 1;
		return ;
	}
	void visit(B *obj) override {
		result = obj->x + 2;
		return ;
	}
	void visit(C *obj) override {
		result = obj->x + 3;
		return ;
	}
	int result;
};

int main()
{
	srand(time(0));
	Base* p;
	int flag;
	switch (rand() % 3) {
		case 0: p = new A(); break;
		case 1: p = new B(); break;
		case 2: p = new C(); break;
	}
	p->x = 1000;

	DynamicVistor vis1;
	p->accept(&vis1);

	AddVisitor vis2;
	p->accept(&vis2);
	cout << "result: " << vis2.result << endl;
	//type-1
	//调用简洁,后期修改简洁,新增功能需要修改类的代码
	//p->output();

	//type-2
	//不需要修改代码,但是不简洁,且后期修改成本高
	// if (dynamic_cast<A *>(p) != nullptr) {
	// 	cout << "Class A : dynamic_cast" << endl;
	// } else if (dynamic_cast<B *>(p) != nullptr) {
	// 	cout << "Class B : dynamic_cast" << endl;
	// } else if (dynamic_cast<C *>(p) != nullptr) {
	// 	cout << "Class C : dynamic_cast" << endl;
	// }

	return 0;
}