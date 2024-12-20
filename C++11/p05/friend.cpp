/*************************************************************************
	> File Name: friend.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 19 Dec 2024 07:16:49 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Tom;
using Honey = Tom;
class Jack {
	//friend class Tom;//C++98
	friend Tom;//C++11
private:
	string name = "jack";
	void print() {
		cout << "my name is " << name << endl;
	}
};

class Lucy {
	friend Honey;
protected:
	string name = "lucy";
	void print() {
		cout << "my name is " << name << endl;
	}
};

class Tom {
public:
	void print() {
		cout << j.name << endl << l.name << endl;
		j.print();
		l.print();
	}
private:
	Jack j;
	Lucy l;
};

int main()
{
	Tom t;
	t.print();
	
	return 0;
}