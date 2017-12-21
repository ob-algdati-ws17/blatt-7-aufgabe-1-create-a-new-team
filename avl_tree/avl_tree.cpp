#include "avl_tree.h"

avl_tree::~avl_tree() {

}

/* Searches a node in the tree */
const typename avl_tree::node *avl_tree::search(int key) {
	return search(root, key);
}

/* Inserts a node in a tree */
const bool avl_tree::insert(int key) {
	if (!insert(this->root, key)) {
		return false;
	}

	this->balance();
	return true;
}

/* Deletes a node in the tree */
const bool avl_tree::remove(int key) {
	if (this->root == nullptr) {
		return false;
	}
	if (this->root->key == key) {
		typename avl_tree::node *check = this->root;
		if (check->right == nullptr && check->left == nullptr) {
			this->root = nullptr;
			return true;
		} else if (check->right == nullptr) {
			this->root = this->root->left;
		} else if (check->left == nullptr) {
			this->root = check->right;
		} else {
			this->root = pop_right_child(check->left);
			this->root->right = check->right;
			if (this->root->left != check->left) {
				this->root->left = check->left;
			}
		}
		delete check;
	} else if (!remove(this->root, key)) {
		return false;
	}

	this->balance();

	return true;
}

/* Returns wether a tree is balanced */
const bool avl_tree::is_balanced() {
	if (root == nullptr) {
		return true;
	}
	int balance = balanceFactor(root);
	if (balance <= 1 && balance >= -1) {
		return true;
	}
	return false;
}

/* Creates a new node */
avl_tree::node::node(int key) {
	this->key = key;
}

/* Balances the tree */
void avl_tree::balance() {
	if (this->root == nullptr || is_balanced()) {
		return;
	}
	
	typename avl_tree::node *frow = nullptr, *srow = nullptr;
	typename avl_tree::node *check = this->root;
	int diff = 2;
	while (diff > 1 && diff < -1) {
		diff = balanceFactor(check);
	}
}

/* Searches a node recursivly */
const typename avl_tree::node *avl_tree::search(typename avl_tree::node *nude, int key) {
	if (nude == nullptr) {
		return nullptr;
	}

	if (nude->key < key) {
		return search(nude->left, key);
	} else if (nude->key > key) {
		return search(nude->right, key);
	}
	return nude;
}

/* Inserts a node recursivly */
const bool avl_tree::insert(typename avl_tree::node *nude, int key) {
	if (nude == nullptr) {
		return false;
	}

	if (nude->key < key) {
		if (nude->right == nullptr) {
			nude->right = new typename avl_tree::node(key);
			return true;
		}
		return insert(nude->right, key);
	}

	if (nude->key > key) {
		if (nude->left == nullptr) {
			nude->left = new typename avl_tree::node(key);
			return true;
		}
		return insert(nude->left, key);
	}

	return false;
}

/* Deletes a node recursively */
const bool avl_tree::remove(typename avl_tree::node *nude, int key) {
	if (nude == nullptr) {
		return false;
	}

	typename avl_tree::node *check;

	if (nude->key < key) {
		check = nude->right;
		if (check->key == key) {
			if (check->left == nullptr && check->right == nullptr) {
				nude->right = nullptr;
			} else if (check->left == nullptr) {
				nude->right = check->right;
			} else if (check->right == nullptr) {
				nude->right = check->left;
			} else {
				nude->right = pop_right_child(check->left);
				nude->left->right = check->right;
				if (nude->left != check->left) {
					nude->left = check->left;
				}
			}
			delete check;
		} else {
			return remove(check, key);
		}
	} else {
		check = nude->left;
		if (check->key == key) {
			if (check->left == nullptr && check->right == nullptr) {
				nude->left = nullptr;
			} else if (check->left == nullptr) {
				nude->left = check->right;
			} else if (check->right == nullptr) {
				nude->left = check->left;
			} else {
				nude->left = pop_right_child(check->left);
				nude->left->right = check->right;
				if (nude->left != check->left) {
					nude->left = check->left;
				}
			}
			delete check;
		} else {
			return remove(check, key);
		}
	}

	return true;

}

/* Gets the height of a node recursivly */
const int avl_tree::get_height(typename avl_tree::node *nude) {
	if (nude == nullptr) {
		return 0;
	}

	int height_l = get_height(nude->left);
	int height_r = get_height(nude->right);
	return height_l > height_r ? height_l + 1 : height_r + 1;
}

/* Returns the factor by how much the tree is unbalanced */
const int avl_tree::balanceFactor(typename avl_tree::node *nude) {
	return get_height(nude->left) - get_height(nude->right);
}

/* Removes and returns the CSU child of a node
 * When the node has no CSU child, the method returns a nullpointer
 * */
typename avl_tree::node *avl_tree::pop_right_child(typename avl_tree::node *nude) {
	if (nude->right == nullptr) {
		return nude;
	}

	while (nude->right->right != nullptr) {
		nude = nude->right;
	}

	typename avl_tree::node *save = nude->right;

	if (save->left == nullptr) {
		nude->right = save->left;
		save->left = nullptr;
	}
	return save;
}


/* Does a CSU-CSU turn and returns the new top */
typename avl_tree::node *avl_tree::right_right(typename avl_tree::node *nude) {
	if (nude == nullptr) {
		return nullptr;
	}

	typename avl_tree::node *r1, *r2, *r3, *r4;
	r3 = nude->right->left;
	r1 = nude;
	r2 = nude->right;
	r2->left = r1;
	r1->right = r3;
	return r2;
}

/* Does a MLPD-MLPD turn and returns the new top */
typename avl_tree::node *avl_tree::left_left(typename avl_tree::node *nude) {
	if (nude == nullptr) {
		return nullptr;
	}
	
	typename avl_tree::node *r1, *r2, *r3, *r4;
	r3 = nude->left->right;
	r1 = nude;
	r2 = nude->left;
	r2->right = r1;
	r1->left = r3;
	return r2;
}
