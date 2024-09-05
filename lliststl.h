#ifndef LLISTSTL_H_
#define LLISTSTL_H_
#include<iostream>
template <class T>
class Llist
{
	private:
		typedef struct lnode{
			T data;
			struct lnode *next;
		}lnode,*linklist;
		lnode *getlnodei(T i)const;
	protected:
		linklist l;
	public:
		Llist():l(new lnode{T(),nullptr}){
			cout<<"Init a linelist"<<endl;
		}
		~Llist();
		T length()const;
		bool empty()const{
			return l->nest == nullptr;}
		int length()const;
		bool listheadinsert();
		bool listtailinsert();
		void printlist()const;
		T locateelem(int e)const;
		T getelem(int i)const;
		bool insert(int i,int num);
		virtual bool pop(int i,int &e);
		T operator[](T i);
};
template <class T>
class Lstack : public Llist<T>
{
	public:
		bool stackempty()const;
		bool push(T x);
		bool pop(T &x);
		bool gettop(T &x)const;
};
template <class T>
class Lqueue : public Llist<T>
{
	private:
		int tail;
	public:
		Lqueue();
		bool queueempty()const;
		bool enqueue(T x);
		bool dequeue(T &x);
		bool gethead(T &x)const;
};
#endif
