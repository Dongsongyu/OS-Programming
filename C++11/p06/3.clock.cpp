/*************************************************************************
	> File Name: 3.clock.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 21 Dec 2024 05:18:53 PM CST
 ************************************************************************/

#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

void clockTest() {
	//创建一个时间点对象
	system_clock::time_point epoch;

	chrono::hours h(10 * 24);
	system_clock::time_point epoch1 = epoch + h;
	system_clock::time_point epoch2(epoch + h);

	//当前的时间
	system_clock::time_point nowTime = system_clock::now();
	//时间点->时间段(单位秒)
	time_t allSec = system_clock::to_time_t(nowTime);
	cout << "当前的时间: " << ctime(&allSec) << endl;

	system_clock::time_point tp = system_clock::from_time_t(allSec);
}

void steadyClockTest() {
	auto p1 = steady_clock::now();
	auto p3 = high_resolution_clock::now();
	for(int i = 0; i < 1000 ; ++i) {
		cout << "*";
	}
	cout << endl;
	auto p2 = steady_clock::now();
	auto p4 = high_resolution_clock::now();
	auto d1 = p2 - p1;
	auto d2 = p4 - p3;
	cout << "count: " << d1.count() << endl;
	cout << "count: " << d2.count() << endl;
}

int main()
{
	clockTest();
	steadyClockTest();
	
	return 0;
}
