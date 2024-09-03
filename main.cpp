#include<iostream>
#include"lilist.h"
using namespace std;
int main(){
	Lqueue a;
	a.enqueue(10);
	a.enqueue(90);
	a.printlist();
	cout<<"index"<<endl;
	cout<<a[1]<<endl;
	int b;
	a.gethead(b);
	cout<<"head:"<<b<<endl;
	a.dequeue(b);
	a.printlist();
	cout<<"pop:"<<b<<endl;
	return 0;
}
