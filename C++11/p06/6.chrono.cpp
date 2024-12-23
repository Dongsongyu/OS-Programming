/*************************************************************************
	> File Name: 6.chrono.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 22 Dec 2024 03:55:18 PM CST
 ************************************************************************/

#include<iostream>
#include<chrono>
using namespace std;
using namespace chrono;

void durationCastTest() {
	//分钟->小时
	hours h = duration_cast<hours>(minutes(60));
	//小时->分钟
	minutes m1 = hours(1);

	//浮点->整型(会损失精度)
	using mydouble = duration<double>;
	seconds ss = duration_cast<seconds>(mydouble(2.5));

	//整型->浮点
	mydouble dd = seconds(9);

	duration<int, ratio<1, 100>> t1(100);
	duration<double, ratio<1, 1000>> t2(12.56);

	using myInt = duration<int, ratio<1, 100>>;
	duration<int, ratio<1, 100>> t3 = duration_cast<myInt>(t2);
	duration<double, ratio<1, 1000>> t4 = t1;
}

template<typename Duration>
using MyTimePoint = time_point<system_clock, Duration>;

int main()
{
	//基秒的时间点
	MyTimePoint<seconds> mPoint(seconds(1));
	MyTimePoint<milliseconds> millPoint(milliseconds(1));

	MyTimePoint<milliseconds> ms = mPoint;
	MyTimePoint<seconds> mms= time_point_cast<seconds>(millPoint);
	durationCastTest();

	return 0;
}