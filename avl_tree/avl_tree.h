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
	private:
		node *root = nullptr;
		void balance();
		static const node *search(node *, int);
		static const bool insert(node *, int);
		static const bool remove(node *, int);
		static const int get_height(node *);
		static node *right_rotation(node *);
		static node *left_rotation(node *);
		static node *pop_right_child(node *);
		static const int balance_factor(node *);
		static void recursive_delete(node *);
};


#endif // AVLTREE_TREE_H
