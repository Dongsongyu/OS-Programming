/*************************************************************************
	> File Name: oj_170.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 21 Sep 2024 05:05:49 PM CST
 ************************************************************************/
//禁止吸烟问题
#include<iostream>
using namespace std;
#include<string>

int main()
{
    string s;
    string olds = "Ban_smoking", news = "No_smoking";
    int n;
    cin >> n;
    while(n--){
        cin >> s;
        do{
            int pos = s.find(olds);
            if(pos == -1) break;
            s.replace(pos, olds.size(), news);
        }while(1);
    cout << s << endl;
    }

    return 0;
}
