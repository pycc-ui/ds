#include<iostream>
using namespace std;
typedef struct lnode{
	int data;
	struct lnode *next;
}lnode,*linklist;
//初始化
bool initlist(linklist &l){
	l = new lnode;
	if (l == NULL)return false;
	l -> next = NULL;
	l -> data = 1;
	return true;
}
//判断表空
bool empty(linklist l)
{
	if(l -> next == NULL) return true;
   	return false;	
}
//求表长
int length(linklist l){
	int leng = 0;
	lnode *q;
	q = l -> next;
	while(q!=NULL){
		q = q -> next;
		leng ++;
	}		
	return leng;
}
//获取第i位的指针
//使用前确保i在合理的范围之内
lnode *getlnodei(linklist l,int i)
{
	lnode *s = l;
	int j = 0;
	while(s != NULL){
			if(i == j){return s;}
			s = s -> next;
			j++;

	}
	return NULL;
}
//头插法建立链表
bool listheadinsert(linklist &l){
	if(!empty(l)){return false;}
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
bool listtailinsert(linklist &l){
	
	if(!empty(l)){return false;}
	lnode *s;
	lnode *q = l;
	int x;
	cin>>x;
	while(x != -1){
		s = new lnode;
		q -> next = s;
		s -> data = x;
		q = s;
		cin>>x;
	}//修改
	q -> next = NULL;
	return true;
}
//输出链表的各项值
void printlist(linklist l){
	lnode *s;
	s = l->next;
	while(s != NULL){
		cout<<s->data<<endl;
		s = s->next;
	}
}
//按值查找
int locateelem(linklist &l,int e)
{
	if (empty(l)){
		return 0;
	}
	lnode *s = l -> next;
	int lo = 0;
	while(s != NULL)
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
int getelem(linklist l,int i)
{	
	if (length(l) < i || i < 1 || empty(l)){
	 	return -1;
	}
	lnode *s = getlnodei(l,i);
	return s -> data;
}
//插入到第i个位置
bool insert(linklist &l,int i,int num){
	if(i < 1 || i > length(l)+1)
	{return false;}
	lnode *s;
	lnode *p = new lnode;
	s = getlnodei(l,i-1);
	p -> next = s -> next;
	s -> next = p;
	p -> data = num;
	return true;
}
//删除节点
bool pop(linklist &l,int i, int &e){
	if (i<1 || i> length(l)){
	return false;
	}
	lnode *s = getlnodei(l,i);
	lnode *p = getlnodei(l,i-1);
	e = s -> data;
	p -> next = s ->next;
	delete s;
	return true;
}
//销毁链表
int destroylist(linklist &l)
{
	if(empty(l)){delete l;return 1;}
	lnode *q;
	q = l->next;
	while(q -> next != NULL){
		l -> next = q -> next;
		delete q;
		q = l -> next;
	}
	delete q;
	delete l;
	return 2;

}
int main(){
	linklist l;
	initlist(l);
	listtailinsert(l);
	printlist(l);
	cout<<destroylist(l)<<endl;
	return 0;

}
