/*************************************************************************
	> File Name: 5.oj_595.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 09 Oct 2024 07:47:19 PM CST
 ************************************************************************/
#include<vector>
#include<iostream>
using namespace std;

int main()
{
    int n, flag = 0;
    cin >> n;
    vector<string> ops(n), s;
    string target;
    for(int i = 0; i < n; i++){
        cin >> ops[i];
    }
    cin >> target;
    for(int i = 0; i < n; i++){
        if(target == ops[i]){
            s.push_back(ops[i]);
            flag = 1;
            break;
        }
        if(ops[i] == "return") s.pop_back();
        else s.push_back(ops[i]);
    }
    if(flag){
        for(int i = 0; i < s.size(); i++){
            if(i) cout << "->";
            cout << s[i];
        }    
        cout << endl;
    }
    else cout << "NOT REFERENCED" << endl;

    return 0;
}
