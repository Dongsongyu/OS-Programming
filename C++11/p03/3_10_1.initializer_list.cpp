/*************************************************************************
	> File Name: 3_10_1.initializer_list.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 15 Dec 2024 05:26:02 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Test
{
public:
    Test(std::initializer_list<string> list)
    {
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            cout << *it << " ";
            m_names.push_back(*it);
        }
        cout << endl;
    }
private:
    vector<string> m_names;
};

int main(void)
{
    Test t({ "jack", "lucy", "tom" });
    Test t1({ "hello", "world", "nihao", "shijie" });
    return 0;
}


