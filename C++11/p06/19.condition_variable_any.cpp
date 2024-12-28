/*************************************************************************
	> File Name: 19.condition_variable_any.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 27 Dec 2024 09:51:36 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<thread>
#include<condition_variable>
#include<mutex>
using namespace std;

//任务队列类
class TaskQueue {
public:
	//添加数据
	void put(const int& task) {
		lock_guard<mutex> locker(myMutex);//锁定的是从21到27行的代码块，执行效率可能较低
		notFull.wait(myMutex, [=] () {
			return taskQueue.size() != maxSize;
		});//阻塞生产者线程
		taskQueue.push(task);
		cout << "添加任务: " << task << ",线程ID: " << this_thread::get_id() << endl;
		//唤醒消费者
		notEmpty.notify_one();
	}

	//取数据
	void take() {
		myMutex.lock();//直接使用互斥锁对象比较灵活
		notEmpty.wait(myMutex, [=] () {
			return !taskQueue.empty();
		});//阻塞消费者线程
		int node = taskQueue.front();
		taskQueue.pop();
		cout << "删除任务: " << node << ", 线程ID: " << this_thread::get_id() << endl;
		myMutex.unlock();
		//唤醒生产者
		notFull.notify_all();
	}

	bool isFull() {
		lock_guard<mutex> locker(myMutex);
		if(maxSize == taskQueue.size()) {
			return true;
		}
		return false;
	}

	bool isEmpty() {
		lock_guard<mutex> locker(myMutex);
		if(taskQueue.size() == 0) {
			return true;
		}
		return false;
	}

	int taskSize() {
		lock_guard<mutex> locker(myMutex);
		return taskQueue.size();
	}
private:
	int maxSize = 100;
	queue<int> taskQueue;
	mutex myMutex;
	condition_variable_any notFull; //生产者
	condition_variable_any notEmpty; //消费者
};

int main()
{
	thread t1[5];
	thread t2[5];
	TaskQueue taskQ;
	for(int i = 0; i < 5; ++i) {
		t1[i] = thread(&TaskQueue::put, &taskQ, 100 + i);//生产者线程
		t2[i] = thread(&TaskQueue::take, &taskQ);//消费者线程
	}

	for(int i = 0; i < 5; ++i) {
		t1[i].join();
		t2[i].join();
	}

	return 0;
}