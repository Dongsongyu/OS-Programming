/*************************************************************************
	> File Name: 3.swap.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 21 Sep 2024 03:38:14 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void swap(int &pa, int &pb){
    int c = pa;
    pa = pb;
    pb = c;

    return ;
}

#define P(msg){\
    printf("%s = %d\n", #msg, msg);\
}

void inc(int &x){
    x += 1;
    return ;
}

int main()
{
    int a = 3, b = 6;
    int &c = b;
    P(a);
    P(b);P(c);
    swap(a,b);
    P(a);
    P(b);P(c);
    inc(a),inc(a),inc(b);
    P(a);
    P(b);P(c);

    return 0;
}
