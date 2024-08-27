#ifndef LINKLIST_H_
#define LINKLIST_H_
typedef struct lnode{
	int data;
	struct lnode *next;
}lnode,*linklist;
class Llist{
	private:
		linklist l;
		lnode *getlnodei(int i);
	public:
		Llist();
		~Llist();
		int length();
		bool empty();
		bool listheadinsert();
		bool listtailinsert();
		void printlist();
		int locateelem(int e);
		int getelem(int i);
		bool insert(int i,int num);
		bool pop(int i,int &e);
};
#endif
