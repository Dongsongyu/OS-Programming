/*************************************************************************
	> File Name: oj_172.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 21 Sep 2024 08:43:13 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<set>

int main()
{
    set<string> s;
    string name;
    for(int i = 0; i < 10; i++){
        cin >> name;
        s.insert(name);
    }
    for(auto x : s){
        cout << x << endl;
    }

    return 0;
}
