/*************************************************************************
	> File Name: condition.c
	> Author: 
	> Mail: 
	> Created Time: Mon 30 Sep 2024 10:56:33 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

pthread_cond_t cond;
pthread_mutex_t mutex;

//链表的节点类型
struct Node{
    int number;
    struct Node* next;
};
//链表头节点
struct Node* head = NULL;
//生产者
void * producer(void* arg)
{
    while(1){
        pthread_mutex_lock(&mutex);
        //创建新节点
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        //init Node
        newNode->number = rand() % 1000;
        newNode->next = head;
        head = newNode;
        printf("生产者, id : %ld ,number: %d\n", pthread_self(), newNode->number);
        pthread_mutex_unlock(&mutex);
        pthread_cond_broadcast(&cond);
        sleep(rand() % 5);
    }
    return NULL;
}
//消费者
void* consumer(void* arg)
{
    while(1){
        pthread_mutex_lock(&mutex);
        while(head == NULL){
            //阻塞消费者线程
            pthread_cond_wait(&cond, &mutex);
        }
        struct Node* node = head;
        printf("消费者, id : %ld, number : %d\n", pthread_self(), node->number);
        head = head->next;
        free(node);
        pthread_mutex_unlock(&mutex);

        sleep(rand() % 5);
    }
    return NULL;
}

int main()
{
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_t t1[5], t2[5];
    for(int i = 0; i < 5; ++i){
        pthread_create(&t1[i], NULL, producer, NULL);
    }
    for(int i = 0; i < 5; ++i){
        pthread_create(&t2[i], NULL, consumer, NULL);
    }
    for(int i = 0; i < 5; i++){
        pthread_join(t1[i], NULL);
        pthread_join(t2[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
