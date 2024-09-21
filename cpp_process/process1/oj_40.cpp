/*************************************************************************
	> File Name: oj_40.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 21 Sep 2024 08:53:48 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<vector>

#define MAX_N 500
class BigInt : public vector<int>{
public :
    BigInt(int x = 0){
        push_back(0);
        process_digit();
    }
    BigInt &operator=(int x){
        clear();
        push_back(x);
        process_digit();
        return *this;
    }

    BigInt &operator+=(const BigInt &obj){
        for(int i = 0; i < obj.size(); i++){
            if(i == size()) push_back(obj[i]);
            else at(i) += obj[i];
        }
        process_digit();
        return *this;
    }

    BigInt operator+(const BigInt &obj){
        BigInt ret(*this);
        ret += obj;
        return ret;
    }
private:
    void process_digit(){
        for(int i = 0; i < size(); i++){
            if(at(i) < 10) continue;
            if(i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        return ;
    }
};

BigInt f[MAX_N + 5];

ostream &operator<<(ostream &out, const BigInt &a){
    for(int i = a.size() - 1; i >= 0; i--){
        out << a[i];
    }
    return out;
}

int main()
{
    int n;
    cin >> n;
    f[0] = 1;
    f[1] = 0;
    f[2] = 1;
    for(int i = 3; i <= n; i++){
        f[i] = f[i - 2] + f[i - 3];
    }
    cout << f[n] << endl;
    
    return 0;
}
