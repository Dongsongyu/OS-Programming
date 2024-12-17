/*************************************************************************
	> File Name: 3_4.using_prs.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 15 Dec 2024 03:36:40 PM CST
 ************************************************************************/

#include <iostream>
#include <functional>
#include <map>
using namespace std;

template <typename T>
class Container {
public:
	void print(T& t) {
			for (const auto& [key, value] : t) {
    		cout << key << ", " << value << endl;
		}
	}
};

template <typename T>
using mymap = map<int, T>;

int main(void)
{
    // map的value指定为string类型
    mymap<string> m;
    m.insert(make_pair(1, "luffy"));
    m.insert(make_pair(2, "ace"));
	Container<mymap<string>> c;
	c.print(m);

    // map的value指定为int类型
    mymap<int> m1;
	m1.insert(std::make_pair(1, 100));  
	m1.insert(std::make_pair(2, 200));  
	Container<mymap<int>> c1;
	c1.print(m1);

    return 0;
}
