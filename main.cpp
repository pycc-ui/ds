#include<iostream>
#include"lilist.h"
int main(){

	using namespace std;
	Llist er;
	er.listtailinsert();
	er.printlist();
	cout<<"length is:"<<er.length()<<endl;
	cout<<"2 locate :"<<er.locateelem(2)<<endl;
	cout<<"The 3 is:"<<er.getelem(3)<<endl;
	er.insert(3,99);
	er.printlist();
	int e;
	er.pop(3,e);
	cout<<"pop is:"<<e<<endl;
	er.printlist();
 	return 0;
}
