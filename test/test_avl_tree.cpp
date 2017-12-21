#include "test_avl_tree.h"
#include <memory>

TEST(AVLTreeTest, Build) {
	avl_tree d;
	d.insert(4);
	d.insert(3);
	d.insert(2);
	d.remove(4);
	d.insert(5);
}
