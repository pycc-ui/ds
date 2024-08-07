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
//头插法建立链表
linklist listheadinsert(linklist l){
	lnode *s;int x;
	s = new lnode;
	cin>>x;
	while(x != -1){
		s -> data = x;
		s -> next = l -> next;
		l -> next = s;
		s = new lnode;
		cin>>x;	
	}
	delete s;
	return l;
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
lnode *locateelem(linklist &l,int e){
	lnode *p = l -> next;
	while(p != NULL && p -> data != e)
		p = p -> next; 
	return p;
}
//插入到第i个位置
linklist insert(linklist &l,int i,int num){
	lnode *p = l -> next;
	if (i<=1){
		lnode *k = new lnode;
		k ->next = l -> next;
		l -> next = k;
}
	int j = 1;
	while(j < i-1 && p != NULL){
		p = p -> next;
		j++;
}
	
	lnode *k = new lnode;
	k ->next = p -> next;
	p -> next = k;
	k -> data = num;
	return l;
}
//删除节点
linklist pop(linklist &l,int i){
	lnode *p = l -> next;
	lnode *q;
	if (i<=1){
		l -> next = p -> next;
		delete p;
}
	int j = 1;
	while(j < i-1 && p != NULL){
		p = p -> next;
		j++;
}
	q = p -> next;
	p -> next = q -> next;
	delete q;
	return l;
}
int main(){
	lnode *p;
	linklist l;
	initlist(l);
	cout<<l -> data<<endl;
	listheadinsert(l);	
	p = locateelem(l,10);
	cout<< "p:data:"<<endl;
	cout<<p -> data << endl;
	printlist(l);
	insert(l,3,67);
	cout<<"new"<<endl;
	printlist(l);
	cout<<"new"<<endl;
	pop(l,3);
	printlist(l);
	return 0;

}
