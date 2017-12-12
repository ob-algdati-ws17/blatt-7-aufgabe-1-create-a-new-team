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

typename avl_tree::node(int key) {
	this.key = key;
}

typename const node avl_tree::search(typename avl_tree::node nude,int key) {
	return null;
}

const bool avl_tree::insert(typename avl_tree::node nude, int key) {
	return true;
}

const bool avl_tree::delete(typename avl_tree::node nude, int key) {
	return true;
}
