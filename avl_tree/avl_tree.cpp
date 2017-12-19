#include "avl_tree.h"

avl-tree::avl_tree(int key) {
}

avl_tree::~avl_tree() {

}

typename const node avl_tree::search(int key) {
	return this.search(root, key);
}

const bool avl_tree::insert(int key) {
	return this.insert(this.root, key);
}

const bool avl_tree::delete(int key) {
	return this.delete(this.root, key);
}

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

typename avl_tree::node(int key) {
	this.key = key;
}

typename const node avl_tree::search(typename avl_tree::node &nude,int key) {
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

const bool avl_tree::insert(typename avl_tree::node &nude, int key) {
	return true;
}

const bool avl_tree::delete(typename avl_tree::node &nude, int key) {
	return true;
}

const int get_height(typename avl_tree::node &nude) {
	if (nude->left == nullptr && nude->right == nullptr) {
		return 0;
	}

	int height_l = get_height(nude->left);
	int height_r = get_height(nude->right);
	return height_l > height_r ? height_l + 1 : height_r + 1;
}
