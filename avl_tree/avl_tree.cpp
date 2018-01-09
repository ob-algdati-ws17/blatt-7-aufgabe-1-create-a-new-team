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
		return true;
	}
	return insert(this->root, key);
}

/* Inserts a node recursivly */
const bool avl_tree::insert(typename avl_tree::node *nude, int key) {
	bool changed = false;
	if (nude->key < key) {
		if (nude->right == nullptr) {
			nude->right = new typename avl_tree::node(key);
			changed = true;
		} else {
			changed = insert(nude->right, key);
		}
	} else if (nude->key > key) {
		if (nude->left == nullptr) {
			nude->left = new typename avl_tree::node(key);
			changed = true;
		} else {
			changed = insert(nude->left, key);
		}
	}

	if (changed) {
		update_height(nude);
		balance(nude);
	}

	return changed;
}

/* Deletes a node in the tree */
const bool avl_tree::remove(int key) {
	if (this->root == nullptr) {
		return false;
	}

	bool changed = false;

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
			if (this->root != check->left) {
				this->root->left = check->left;
			}
			this->root->right = check->right;
		}
		delete check;
		changed = true;
	} else {
		changed = remove(this->root, key);
	}

	if (changed) {
		update_height(this->root);
		balance(this->root);
	}

	return changed;
}

/* Deletes a node recursively */
const bool avl_tree::remove(typename avl_tree::node *nude, int key) {
	if (nude == nullptr) {
		return false;
	}

	typename avl_tree::node *check;
	bool changed = false;

	if (nude->key < key) {
		check = nude->right;
		if (check != nullptr && check->key == key) {
			if (check->left == nullptr && check->right == nullptr) {
				nude->right = nullptr;
			} else if (check->left == nullptr) {
				nude->right = check->right;
			} else if (check->right == nullptr) {
				nude->right = check->left;
			} else {
				nude->right = pop_right_child(check->left);
				if (nude->right != check->left) {
					nude->right->left = check->left;
				}
                		nude->right->right = check->right;
			}
			delete check;
			changed = true;
			update_height(nude->right);
			balance(nude->right);
		} else {
			changed = remove(check, key);
		}
	} else {
		check = nude->left;
		if (check != nullptr && check->key == key) {
			if (check->left == nullptr && check->right == nullptr) {
				nude->left = nullptr;
			} else if (check->left == nullptr) {
				nude->left = check->right;
			} else if (check->right == nullptr) {
				nude->left = check->left;
			} else {
				nude->left = pop_right_child(check->left);
				if (nude->left != check->left) {
					nude->left->left = check->left;
				}
				nude->left->right = check->right;
			}
			delete check;
			changed = true;
			update_height(nude->left);
			balance(nude->left);
		} else {
			changed = remove(check, key);
		}
	}

	if (changed) {
		update_height(nude);
		balance(nude);
	}

	return changed;
}

void avl_tree::balance(typename avl_tree::node *nude) {
	if (nude == nullptr) {
		return;
	}

	int balance = balance_factor(nude);
	
	if (balance >= 2) {
		/* left heavy */
		int diff = balance_factor(nude->left);
		if (diff < 0) {
			/* double rotation */
			left_rotation(nude->left);
		}
		
		right_rotation(nude);
	} else if (balance <= -2) {
		/* right heavy */
		int diff = balance_factor(nude->right);
		if (diff > 0) {
			/* double rotation */
			right_rotation(nude->right);
		}
		left_rotation(nude);
	}

	update_height(nude);
}

void avl_tree::update_height(typename avl_tree::node *nude) {
	if (nude == nullptr) {
		return;
	}

	int left = (nude->left != nullptr ? nude->left->height : 0) + 1;
	int right = (nude->right != nullptr ? nude->right->height : 0) + 1;
	nude->height = left > right ? left : right;
}

/* Returns the balance factor of the node */
const int avl_tree::balance_factor(typename avl_tree::node *nude) {
	int left = nude->left != nullptr ? nude->left->height : 0;
	int right = nude->right != nullptr ? nude->right->height : 0;
	return left - right;
}

/* Removes and returns the CSU child of a node
 * When the node has no CSU child, the method returns the node itself
 * */
typename avl_tree::node *avl_tree::pop_right_child(typename avl_tree::node *nude) {
	if (nude->right == nullptr) {
		return nude;
	}

	auto tmp = pop_right_child(nude->right);

	if (tmp == nude->right) {
		nude->right = tmp->left;
		tmp->left = nullptr;
		update_height(tmp);
	}

	update_height(nude);

	return tmp;
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
	update_height(r);
	update_height(nude);
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
	update_height(r);
	update_height(nude);
}

/********************************************************************
 * Traversal
 *******************************************************************/

vector<int> *avl_tree::preorder() const {
    if (root == nullptr)
        return nullptr;
    return root->preorder();
}

vector<int> *avl_tree::node::preorder() const {
    auto vec = new vector<int>();
    // Wurzel in vec
    vec->push_back(key);
    // linken Nachfolger in vec
    if (left != nullptr) {
        auto left_vec = left->preorder();
        vec->insert(vec->end(), left_vec->begin(), left_vec->end());
    }
    // rechten Nachfolger in vec
    if (right != nullptr) {
        auto right_vec = right->preorder();
        vec->insert(vec->end(), right_vec->begin(), right_vec->end());
    }
    return vec;
}

vector<int> *avl_tree::inorder() const {
    if (root == nullptr)
        return nullptr;
    return root->inorder();
}

vector<int> *avl_tree::node::inorder() const {
    auto vec = new vector<int>();
    // linken Nachfolger in vec
    if (left != nullptr) {
        auto left_vec = left->inorder();
        vec->insert(vec->end(), left_vec->begin(), left_vec->end());
    }
    // Wurzel in vec
    vec->push_back(key);
    // rechten Nachfolger in vec
    if (right != nullptr) {
        auto right_vec = right->inorder();
        vec->insert(vec->end(), right_vec->begin(), right_vec->end());
    }
    return vec;
}

vector<int> *avl_tree::postorder() const {
    if (root == nullptr)
        return nullptr;
    return root->postorder();
}

vector<int> *avl_tree::node::postorder() const {
    auto vec = new vector<int>();
    // linken Nachfolger in vec
    if (left != nullptr) {
        auto left_vec = left->postorder();
        vec->insert(vec->end(), left_vec->begin(), left_vec->end());
    }
    // rechten Nachfolger in vec
    if (right != nullptr) {
        auto right_vec = right->postorder();
        vec->insert(vec->end(), right_vec->begin(), right_vec->end());
    }
    // Wurzel in vec
    vec->push_back(key);
    return vec;
}
