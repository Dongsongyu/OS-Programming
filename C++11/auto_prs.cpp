/*************************************************************************
	> File Name: auto_prs.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 15 Dec 2024 09:56:54 AM CST
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;

class T1 {
public:
	static int get(){
		return 10;
	}
};

class T2 {
public:
	static string get() {
		return "hello, world!";
	}
};

template <class T>
void func(void) {
	auto ret = T::get();
	cout << "ret : " << ret << endl;
}

int main()
{
	map<int, string> mp;
	mp.insert(make_pair(1, "ace"));
	mp.insert(make_pair(2, "sabo"));
	mp.insert(make_pair(3, "luffy"));
	//map<int, string>::iterator it = mp.begin();
	for(auto it = mp.begin(); it != mp.end(); ++it) {
		cout << "key : " << it->first << ", value : " << it->second << endl;
	}

	func<T1>();
	func<T2>();
	return 0;
}