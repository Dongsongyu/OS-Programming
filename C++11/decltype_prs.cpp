/*************************************************************************
	> File Name: decltype_prs.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 15 Dec 2024 10:22:34 AM CST
 ************************************************************************/

#include<iostream>
#include<list>
using namespace std;

template<class T>
class Container {
public:
	void print(T &t) {
		for(m_it = t.begin(); m_it != t.end(); ++m_it) {
			cout << "value : " << *m_it << endl;
		}
	}
private:
	decltype(T().begin()) m_it;
};

int main()
{
	list<int> ls{1,2,3,4,5,6,7};
	const list<int> ls1 {1,2,3,4,5,6,7};
	list<int>::iterator it = ls.begin();
	Container<list<int>> c;
	Container<const list<int>> c1;
	c.print(ls);
	cout << endl;
	c1.print(ls1);

	return 0;
}