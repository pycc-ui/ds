#include<iostream>
#include"lilist.h"
using namespace std;
//初始化
Llist::Llist():l(new lnode{1,nullptr}){
	cout<<"Init a empty list"<<endl;
}
//判断表空
bool Llist::empty()const
{
   	return l->data == nullptr;	
}
//求表长
int Llist::length()const{
	int leng = 0;
	lnode *q;
	q = l -> next;
	while(q!=nullptr){
		q = q -> next;
		leng ++;
	}		
	return leng;
}
//获取第i位的指针
//使用前确保i在合理的范围之内
lnode* Llist::getlnodei(int i)const
{
	lnode *s = l;
	int j = 0;
	while(s != nullptr){
			if(i == j){return s;}
			s = s -> next;
			j++;

	}
	return nullptr;
}
//头插法建立链表
bool Llist::listheadinsert(){
	if(!empty()){return false;}
	lnode *s;
	int x;
	cin>>x;
	while(x != -1){
		s = new lnode;
		s -> data = x;
		s -> next = l -> next;
		l -> next = s;
		cin>>x;	
	}
	return true;
}
//尾插法建立链表
bool Llist::listtailinsert(){
	
	if(!empty()){return false;}
	lnode *s;
	lnode *q = l;
	int x;
	while(cin>>x){
		if(x == -1) break;
		s = new lnode;
		q -> next = s;
		s -> data = x;
		q = s;
	}//修改
	q -> next = nullptr;
	return true;
}
//输出链表的各项值
void Llist::printlist()const{
	lnode *s;
	s = l->next;
	while(s != nullptr){
		cout<<s->data<<endl;
		s = s->next;
	}
}
//按值查找
int Llist::locateelem(int e)const
{
	if (empty()){
		return 0;
	}
	lnode *s = l -> next;
	int lo = 0;
	while(s != nullptr)
	{
		lo ++;
		if(s -> data == e){
			return lo;
		}
		s = s-> next;
	}
	return 0;
}
//按位查找
int Llist::getelem(int i)const
{	
	if (length() < i || i < 1 || empty()){
	 	return -1;
	}
	return getlnodei(i) -> data;
}
//插入到第i个位置
bool Llist::insert(int i,int num){
	if(i < 1 || i > length()+1)
	{return false;}
	lnode *s;
	lnode *p = new lnode;
	s = getlnodei(i-1);
	p -> next = s -> next;
	s -> next = p;
	p -> data = num;
	return true;
}
//删除节点
bool Llist::pop(int i, int &e){
	if (i<1 || i> length()){
	return false;
	}
	lnode *s = getlnodei(i);
	lnode *p = getlnodei(i-1);
	e = s -> data;
	p -> next = s ->next;
	delete s;
	return true;
}
//销毁链表
Llist::~Llist()
{
	if(empty()){delete l;cout<<"empty,~"<<endl;}
	lnode *q;
	while(l != nullptr){
		q = l;
		l = l->next;
		delete q;
	}
	cout<<"destroy~"<<endl;

}
bool Lstack::stackempty()const{
	return empty();
}
bool Lstack::push(int x){
	return insert(1,x);
}
bool Lstack::pop(int &x){
	return Llist::pop(1,x);
}
bool Lstack::gettop(int &x)const{
	int e;
	e = this-> getelem(1);
	cout<<"e:"<<e<<endl;
	if(e == -1)return false;
	else{
		x = e;
		return true;
	}
}	
Lqueue::Lqueue():Llist(),tail(0){}
bool Lqueue::queueempty()const
{return empty();}
bool Lqueue::enqueue(int x)
{	
	return insert(++tail,x);
}
bool Lqueue::dequeue(int &x)
{	if (tail == 0)return false;
	tail--;	
	return pop(1,x);} 
bool Lqueue::gethead(int &x)const
{	int e;
	e = getelem(1);
	if(e == -1)return false;
	else{
		x = e;
		return true;
	}
}
int Llist::operator[](int i){
	return getelem(i+1);
}







