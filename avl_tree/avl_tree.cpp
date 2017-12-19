#include "avl_tree.h"

avl-tree::avl_tree(int key) {
}

avl_tree::~avl_tree() {

}

/* Searches a node in the tree */
typename const node avl_tree::search(int key) {
	return search(root, key);
}

/* Inserts a node in a tree */
const bool avl_tree::insert(int key) {
	if (!insert(this.root, key)) {
		return false;
	}

	this.balance();
	return true;
}

/* Deletes a node in the tree */
const bool avl_tree::delete(int key) {
	if (this.root == nullptr) {
		return false;
	}
	if (this.root->key == key) {
		typename avl_tree::node *remove = this.root;
		typename avl_tree::node newNode = pop_left_child(remove->right);
		newNode.right = remove->right;
		newNode.left = remove->left;
		this.root = &newNode;
		delete remove;
	} else if (!delete(this.root, key)) {
		return false;
	}

	this.balance();

	return true;
}

/* Returns wether a tree is balanced */
const bool avl_tree::is_balanced() {
	if (root == nullptr) {
		return true;
	}
	int balance = getHeight(root->left) - getHeight(root->right);
	if (balance <= 1 && balance >= -1) {
		return true;
	}
	return false;
}

/* Creates a new node */
typename avl_tree::node(int key) {
	this.key = key;
}

/* Balances the tree */
void avl_tree::balance() {
	if (this.root == nullptr || is_balanced()) {
		return;
	}
	
	int heightLeft = getHeight(this.root->left);
	int heightRight = getHeight(this.root->right);

	
}

/* Searches a node recursivly */
typename const node search(typename avl_tree::node &nude,int key) {
	if (nude == nullptr) {
		return null;
	}

	if (nude.key < key) {
		return search(nude.left, key);
	} else if (nude.key > key) {
		return search(nude.right, key);
	}
	return nude;
}

/* Inserts a node recursivly */
const bool insert(typename avl_tree::node &nude, int key) {
	if (nude == nullptr) {
		return false;
	}

	if (nude->key < key) {
		if (nude->key == nullptr) {
			nude->key = new typename avl_tree::node(key);
			return true;
		}
		return insert(nude->right, key);
	}

	if (nude->key > key) {
		if (nude->key == nullptr) {
			nude->key = new typename avl_tree::node(key);
			return true;
		}
		return insert(nude->left, key);
	}

	return false;
}

/* Deletes a node recursively */
const bool delete(typename avl_tree::node &nude, int key) {
	if (nude == nullptr) {
		return false;
	}

	if (nude->key < key) {
		if (nude->right->key == key) {
			typename avl_tree::node *remove = nude->right;
			typename avl_tree::node newNode = pop_left_child(remove);
			newNode.right = remove->right;
			newNode.left = remove->left;
			nude->right = &newNode;
			delete remove;
			return true;
		} else {
			return delete(nude->right);
		}
	}

	if (nude->key > key) {
		if (nude->left->key == key) {
			typename avl_tree::node *remove = nude->left;
			typename avl_tree::node newNode = pop_right_child(remove);
			newNode.right = remove->right;
			newNode.left = remove->left;
			nude->left = &newNode;
			delete remove;
			return true;
		} else {
			return delete(nude->left);
		}
	}

	return false;	
}

/* Gets the height of a node recursivly */
const int get_height(typename avl_tree::node &nude) {
	if (nude == nullptr) {
		return 0;
	}

	int height_l = get_height(nude->left);
	int height_r = get_height(nude->right);
	return height_l > height_r ? height_l + 1 : height_r + 1;
}

void balance(typename avl_tree:node &nude) {
	if (nude == nullptr) {
		return;
	}

	int leftHeight = getHeight(nude->left);
	int rightHeight = getHeight(nude->right);

	int diff = leftHeight - rightHeight;

	if (diff <= 1 && diff >= -1) {
		return;
	}

	if (diff < 0) {
		/* right side unbalanced */
	} else {
		/* left side unbalanced */
	}
}

/* Removes and returns the MLPD child of a node
 * When the node has no MLPD child, the method returns a nullpointer
 * */
typename avl_tree::node pop_left_child(typename avl_tree::node &nude) {
	if (nude->left == nullptr) {
		return nullptr;
	}

	while (nude->left != nullptr) {
		nude = nude->left;
	}

	typename avl_tree::node save = *(nude->left);
	nude->left = nullptr;
	return save;
}


/* Removes and returns the CSU child of a node
 * When the node has no CSU child, the method returns a nullpointer
 * */
typename avl_tree::node pop_right_child(typename avl_tree:node &nude) {
	if (nude->right == nullptr) {
		return nullptr;
	}

	while (nude->right != nullptr) {
		nude = nude->right;
	}

	typename avl_tree:node save = *(nude->right);
	nude->right = nullptr;
	return save;
}
