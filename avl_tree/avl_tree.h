#ifndef AVLTREE_TREE_H
#define AVLTREE_TREE_H

#include <iostream>
#include <vector>

using namespace std;

class avl_tree {
	public:
		struct node {
			node *left = nullptr;
			node *right = nullptr;
			int key;
			int height = 1;

			node(int);

            vector<int> *preorder() const;  // (Hauptreihenfolge)
            vector<int> *inorder() const;   // (Symmetrische Reihenfolge)
            vector<int> *postorder() const; // (Nebenreihenfolge)
		};
		~avl_tree();
		const node *search(int);
		const bool insert(int);
		const bool remove(int);
        vector<int> *preorder() const;  // (Hauptreihenfolge)
        vector<int> *inorder() const;   // (Symmetrische Reihenfolge)
        vector<int> *postorder() const; // (Nebenreihenfolge)
	private:
		node *root = nullptr;
		static const node *search(node *, int);
		static const bool insert(node *, int);
		static const bool remove(node *, int);
		static void right_rotation(node *);
		static void left_rotation(node *);
		static node *pop_right_child(node *);
		static const int balance_factor(node *);
		static void recursive_delete(node *);
		static void balance(node *);
		static void update_height(node *);
};


#endif // AVLTREE_TREE_H

