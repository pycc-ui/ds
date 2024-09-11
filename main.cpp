#include<iostream>
#include"lilist.h"
using namespace std;
int main(){
	Llist a;
	cin>>a;
	Llist b;
	b = a;
	b.printlist();
	int x;
	b.pop(1,x);
	b.printlist();
	cout<<"a"<<endl;
	cout<<a;
	Llist c = a +b;
	cout<<c;
	return 0;
}
