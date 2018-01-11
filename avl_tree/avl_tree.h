#ifndef AVLTREE_TREE_H
#define AVLTREE_TREE_H

#include <iostream>
#include <vector>

using namespace std;

/**
 * \brief Implementation of a binary AVL tree.
 *
 * This implementation only saves keys. These keys must be integers.
 */
class avl_tree {
	public:

		/**
		 * \brief Entry of AVL-Tree.
		 *
		 * Consists of key and pointers to its children.
		 */
		struct node {
			/**
			 * Left child of this node.
			 */
			node *left = nullptr;
			/**
			 * Right child of this node.
			 */
			node *right = nullptr;
			/**
			 * Key identifying this node.
			 */
			int key;
			/**
			 * Current height of this node.
			 */
			int height = 1;

			node(int);

			/**
			 * \brief Get subtree from this node in 'preorder'.
			 * \return subtree in 'preorder'
			 */
            vector<int> *preorder() const;  // (Hauptreihenfolge)
			/**
			 * \brief Get subtree from this node in 'inorder'.
			 * \return subtree in 'inorder'
			 */
            vector<int> *inorder() const;   // (Symmetrische Reihenfolge)
			/**
			 * \brief Get subtree from this node in 'postorder'.
			 * \return subtree in 'postorder'
			 */
            vector<int> *postorder() const; // (Nebenreihenfolge)
		};
		/**
		 * \brief Deconstructor deleting all nodes.
		 */
		~avl_tree();
		const node *search(int);
		const bool insert(int);
		const bool remove(int);
		/**
		 * \brief Get tree in 'preorder'.
		 * \sa avl_tree::node::preorder
		 * \return tree in 'preorder'
		 */
        vector<int> *preorder() const;  // (Hauptreihenfolge)
		/**
		 * \brief Get tree in 'inorder'.
		 * \sa avl_tree::node::inorder
		 * \return tree in 'inorder'
		 */
        vector<int> *inorder() const;   // (Symmetrische Reihenfolge)
		/**
		 * \brief Get tree in 'postorder'.
		 * \sa avl_tree::node::postorder
		 * \return tree in 'postorder'
		 */
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

