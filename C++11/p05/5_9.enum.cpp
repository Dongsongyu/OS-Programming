/*************************************************************************
	> File Name: 5_9.enum.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 19 Dec 2024 07:24:24 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

enum TestColor:char {Red = 'a', Green = 'b', Blue = 'c'};
enum class Color:char {Red, Green, Blue};
enum struct Color1 {Red, Green, Blue};

class Test {
public:
	Test() {}
	static void print() {}
	std::string str;
};

int main()
{
	cout << "TestColor Red: " << Red << "," << TestColor::Red << endl;
	cout << "red : " << (int)Color::Red << endl;
	int m = (int)Color::Green;
	cout << "Color size: " << sizeof(Color::Red) << endl;
	cout << "Color size: " << sizeof(Color1::Green) << endl;
	Test::print();

	return 0;
}