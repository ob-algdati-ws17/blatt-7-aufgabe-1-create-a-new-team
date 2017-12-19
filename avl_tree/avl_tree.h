#ifndef AVLTREE_TREE_H
#define AVLTREE_TREE_H

#include<iostream>

class avl_tree {
	private:
		struct node {
			node *left = nullptr;
			node *right = nullptr;
			int key;

			node(int);
		};
		node *root = nullptr;
		void balance();
	public:
		avl_tree(int);
		~avl_tree();
		const typename avl_tree::node search(int);
		const bool insert(int);
		const bool remove(int);
		const bool is_balanced();
};

#endif // AVLTREE_TREE_H
