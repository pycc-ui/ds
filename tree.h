#ifndef TREE_H_
#define TREE_H_

template <class T>
class Bintree
{
	private:
		class Bitnode
		{
			private:
				T data;
				Bitnode *lchild;
				Bitnode *rchild;
			public:
				Bitnode();
				~Bitnode();
		};
		Bitnode *rootnode;
	public:
		Bintree();
		~Bintree();

};
#endif


