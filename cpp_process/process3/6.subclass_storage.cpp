/*************************************************************************
	> File Name: 6.subclass_storage.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Dec 2024 02:21:21 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Base1 {
public:
	Base1() : b1(0x11111111) {}
	int b1;
};

class Base2 {
public:
	Base2() : b2(0x22222222) {}
	int b2;
};

class A : public Base2, public Base1 {
public:
	A() : a(0x33333333) {}
	int a;
};

class B : public Base1, public A {
public:
	B() : x(0x44444444) {}
	int x;
};

void output_address(void *_p, size_t n) {
	unsigned char *p = (unsigned char *)(_p);
	printf("%p : ", p);
	for(int i = 0; i < n; i++){
		if(i % 8 == 0) printf("\n");
		printf("%02x ", p[i]);
	}
	printf("\n");

	return ;
}

int main()
{
	A a;
	output_address(&a, sizeof(a));
	B b;
	output_address(&b, sizeof(b));
	return 0;
}