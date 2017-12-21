#ifndef AVLTREE_TREE_H
#define AVLTREE_TREE_H

#include<iostream>

class avl_tree {
	public:
		struct node {
			node *left = nullptr;
			node *right = nullptr;
			int key;

			node(int);
		};
		~avl_tree();
		const node *search(int);
		const bool insert(int);
		const bool remove(int);
		const bool is_balanced();
		const node *search(node *, int);
		const bool insert(node *, int);
		const bool remove(node *, int);
		const int get_height(node *);
		node *right_right(node *);
		node *left_left(node *);
		node *pop_right_child(node *);
		const int balanceFactor(node *);
	private:
		node *root = nullptr;
		void balance();
	
		
};


#endif // AVLTREE_TREE_H
