#ifndef LINKLIST_H_
#define LINKLIST_H_
typedef struct lnode{
	int data;
	struct lnode *next;
}lnode,*linklist;
class Llist
{
	private:
		lnode *getlnodei(int i)const;
	protected:
		linklist l;
	public:
		Llist();
		~Llist();
		int length()const;
		bool empty()const;
		bool listheadinsert();
		bool listtailinsert();
		void printlist()const;
		int locateelem(int e)const;
		int getelem(int i)const;
		bool insert(int i,int num);
		virtual bool pop(int i,int &e);
		int operator[](int i);
};
class Lstack : public Llist
{
	public:
		bool stackempty()const;
		bool push(int x);
		bool pop(int &x);
		bool gettop(int &x)const;
};
class Lqueue : public Llist
{
	private:
		int tail;
	public:
		Lqueue();
		bool queueempty()const;
		bool enqueue(int x);
		bool dequeue(int &x);
		bool gethead(int &x)const;
};
#endif
