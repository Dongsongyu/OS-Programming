/*************************************************************************
	> File Name: 5.random_data.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 09 Dec 2024 08:31:26 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	srand(time(0));
	printf("26\n");
	for(int i = 0; i < 26; i++) {
		printf("%c %d\n", 'a' + i, rand() % 100000);
	}

	return 0;
}

