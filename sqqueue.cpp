#include<iostream>
using namespace std;
#define maxsize 10
//这里是循环队列
typedef struct{
	int data[maxsize];
	int front,rear;
}sqqueue;
//初始化队列
void initsqueue(sqqueue &q){
	q.rear = 0;
	q.front = 0;
}
//判断队空
bool queueempty(sqqueue &q)
{
	if(q.rear == q.front)
		return true;
	else 
		return false;
}
//入队操作
bool enqueue(sqqueue &q,int x){
	if((q.rear + 1)%maxsize == q.front)
		return false;
	q.data[q.rear] = x;
	q.rear = (q.rear + 1)%maxsize;
	return true;
}
//出队操作
bool dequeue(sqqueue &q,int &x)
{
	if(queueempty(q))
		return false;
	x = q.data[q.front];
	q.front = (q.front + 1)%maxsize;
	return true;
}
//读取对头操作
bool gethead(sqqueue &q,int &x){
	if(queueempty(q))
		return false;
	x = q.data[q.front];
	return true;
}
