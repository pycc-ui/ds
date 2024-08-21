#include<iostream>
using namespace std;
#define maxsize 10
typedef struct{
	int data[maxsize];
	int top;
}sqstack;
//判断栈空
bool stackempty(sqstack  &s){
	if (s.top == -1)
		return true;
	else
		return false;
}
//初始化
void initstack(sqstack &s){
	s.top = -1;
}
//入栈
bool push(sqstack &s,int x){
	if(s.top == maxsize - 1)
		return false;
	else
		{
		s.data[++s.top] = x;
		return true;
	}	
}
//出栈
bool pop(sqstack &s,int &x){
	if(s.top == -1)
		return false;
	x = s.data[s.top--];
	return true;	
}
//返回栈顶元素
bool gettop(sqstack &s,int &x){
	if(s.top == -1)
		return false;
	x = s.data[s.top];
	return true;
}
//销毁栈
//链栈,与单链表差不多
int main(){
	sqstack s;
	initstack(s);
	push(s,10);
	cout<<s.data[s.top]<<endl;
	push(s,20);
	cout<<s.data[s.top]<<endl;
	int x;
	pop(s,x);
	cout<<x<<endl;
	cout<<s.data[s.top]<<endl;
	return 0;
}
