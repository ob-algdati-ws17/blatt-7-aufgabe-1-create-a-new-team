#ifndef AVLTREE_TREE_H
#define AVLTREE_TREE_H

#include<iostream>

class avl_tree {
	public:
		struct node {
			node *left = nullptr;
			node *right = nullptr;
			int key;
			int height = 1;

			node(int);
		};
		~avl_tree();
		const node *search(int);
		const bool insert(int);
		const bool remove(int);
	private:
		node *root = nullptr;
		void balance();
		static const node *search(node *, int);
		static const bool insert(node *, int);
		static const bool remove(node *, int);
		static const int get_height(node *);
		static void right_rotation(node *);
		static void left_rotation(node *);
		static node *pop_right_child(node *);
		static const int balance_factor(node *);
		static const int balance_factor(const int);
		static void recursive_delete(node *);
		static void balance(node *);
		static void update_height(node *);
};


#endif // AVLTREE_TREE_H

