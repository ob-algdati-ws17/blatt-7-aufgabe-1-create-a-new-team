#include "avl_tree.h"

/* Constructor for a new node */
avl_tree::node::node(int key)
	: key(key) {}

/* Deletes all the nodes */
avl_tree::~avl_tree() {
	recursive_delete(this->root);
}

/* Deletes the nodes of the tree recursivly */
void avl_tree::recursive_delete(typename avl_tree::node *nude) {
	if (nude == nullptr) {
		return;
	}

	recursive_delete(nude->left);
	recursive_delete(nude->right);
	delete nude;
}

/* Searches a node in the tree */
const typename avl_tree::node *avl_tree::search(int key) {
	return search(root, key);
}

/* Searches a node recursivly */
const typename avl_tree::node *avl_tree::search(typename avl_tree::node *nude, int key) {
	if (nude == nullptr) {
		return nullptr;
	}

	if (nude->key > key) {
		return search(nude->left, key);
	} else if (nude->key < key) {
		return search(nude->right, key);
	}
	return nude;
}

/* Inserts a node in a tree */
const bool avl_tree::insert(int key) {
	if (this->root == nullptr) {
		this->root = new typename avl_tree::node(key);
	}

	if (!insert(this->root, key)) {
		return false;
	}

	this->balance();
	return true;
}

/* Inserts a node recursivly */
const bool avl_tree::insert(typename avl_tree::node *nude, int key) {
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
			if (this->root != check->left) {
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
				nude->right->right = check->right;
				if (nude->right != check->left) {
					nude->right->left = check->left;
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
					nude->left->left = check->left;
				}
			}
			delete check;
		} else {
			return remove(check, key);
		}
	}

	return true;

}

void avl_tree::balance() {
	balance(this->root);
}

void avl_tree::balance(typename avl_tree::node *nude) {
	if (nude == nullptr) {
		return;
	}
	balance(nude->left);
	balance(nude->right);

	int balance = balance_factor(nude);
	
	if (balance == 1) {
		/* left heavy */
		int diff = get_height(nude->left->left) - get_height(nude->left->right);
		if (diff < 0) {
			/* double rotation */
			left_rotation(nude->left);
		}
		
		right_rotation(nude);
	} else if (balance == -1) {
		/* right heavy */
		int diff = get_height(nude->right->left) - get_height(nude->right->right);
		if (diff > 0) {
			/* double rotation */
			right_rotation(nude->right);
		}
		left_rotation(nude);
	}
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

/* Returns a three-state-bool representing, how the tree is unbalanced */
const int avl_tree::balance_factor(typename avl_tree::node *nude) {
	if (nude == nullptr) {
		return 0;
	}
	int diff = get_height(nude->left) - get_height(nude->right);
	if (diff < -1) {
		return -1;
	}
	if (diff > 1) {
		return 1;
	}
	return 0;
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

	if (save->left != nullptr) {
		nude->right = save->left;
		save->left = nullptr;
	}
	return save;
}


/* Does a MLPD turn and returns the new top */
void avl_tree::left_rotation(typename avl_tree::node *nude) {
	if (nude == nullptr) {
		return;
	}

	typename avl_tree::node *r;
	typename avl_tree::node tmp = *nude;

	r = nude->right; // new top

	*nude = *r;
	*r = tmp;

	r->right = nude->left;
	nude->left = r;
}

/* Does a CSU turn and nude now points to the new top */
void avl_tree::right_rotation(typename avl_tree::node *nude) {
	if (nude == nullptr) {
		return;
	}
	
	typename avl_tree::node *r;
	typename avl_tree::node tmp = *nude;

	r = nude->left; // new top

	*nude = *r;
	*r = tmp;

	r->left = nude->right;
	nude->right = r;
}
