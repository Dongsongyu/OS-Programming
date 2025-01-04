/*************************************************************************
	> File Name: 5.oj_284.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 04 Jan 2025 09:57:00 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

struct Data {
    Data(int p, int d) : p(p), d(d) {}
    int p, d;
    bool operator<(const Data &obj) const {
        if (d != obj.d) return d < obj.d;
        return p > obj.p;
    }
};

typedef pair<int, int> PII;

int main()
{
    int n;
    cin >> n;
    vector<Data> arr;
    set<PII> s;
    for (int i = 0, p, d; i < n; i++) {
        cin >> p >> d;
        arr.push_back(Data(p, d));
    }
    sort(arr.begin(), arr.end());
    /*for(int i = 0; i < n; i++) {
        cout << i <<": " << arr[i].d << ", " << arr[i].p << endl;
    }*/
    for (int i = 0; i < n; i++) {
        if (arr[i].d > s.size()) {
            s.insert(PII(arr[i].p, i));
        } else if (arr[i].d == s.size()) {
            if (arr[i].p > s.begin()->first) {
                s.erase(s.begin());
                s.insert(PII(arr[i].p, i));
            }
        }
    }
    int ans = 0;
    for (auto x : s) {
        ans += x.first;
    }
    cout << ans << endl;

    return 0;
}
