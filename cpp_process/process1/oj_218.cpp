/*************************************************************************
	> File Name: oj_218.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 21 Sep 2024 08:18:19 PM CST
 ************************************************************************/
#include<iostream>
using namespace std;
#include<map>
#include<vector>

int main()
{
    map<int, vector<int>> arr;
    int n;
    cin >> n;
    for(int i = 1, h; i <= n; i++){
        cin >> h;
        arr[h].push_back(i);
    }
    int flag = 0;
    for(auto x : arr){
        for(auto y : x.second){
            if(flag) cout << " ";
            cout << y;
        }
        flag = 1;
    }
    cout << endl;

    return 0;
}
