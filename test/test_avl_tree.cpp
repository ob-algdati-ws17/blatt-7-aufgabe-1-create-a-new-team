#include "test_avl_tree.h"
#include <memory>

TEST(AVLTreeTest, AVLTreeTest_InsertTest_1) {
	avl_tree d;
	EXPECT_EQ(nullptr, d.search(42));
	EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.insert(42));
	EXPECT_EQ(42, d.search(42)->key);
}

TEST(AVLTreeTest, AVLTreeTest_InsertTest_2_Right) {
    avl_tree d;
    EXPECT_EQ(nullptr, d.search(42));
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.insert(42));
    EXPECT_TRUE(d.insert(1337));
    EXPECT_FALSE(d.insert(1337));
    auto first = d.search(42);
    EXPECT_EQ(42, first->key);
    EXPECT_EQ(1337, first->right->key);
    EXPECT_EQ(nullptr, first->left);

    EXPECT_TRUE(d.remove(42));
    EXPECT_FALSE(d.remove(42));
    EXPECT_EQ(nullptr, d.search(42));
}

TEST(AVLTreeTest, AVLTreeTest_InsertTest_2_Left) {
    avl_tree d;
    EXPECT_EQ(nullptr, d.search(42));
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.insert(42));
    EXPECT_TRUE(d.insert(17));
    EXPECT_FALSE(d.insert(17));
    auto root = d.search(42);
    EXPECT_EQ(42, root->key);
    EXPECT_EQ(17, root->left->key);
    EXPECT_EQ(nullptr, root->right);

    EXPECT_TRUE(d.remove(42));
    EXPECT_FALSE(d.remove(42));
    EXPECT_EQ(nullptr, d.search(42));
}

TEST(AVLTreeTest, AVLTreeTest_RemoveTest_1) {
    avl_tree d;
    EXPECT_EQ(nullptr, d.search(42));
    EXPECT_FALSE(d.remove(42));
    EXPECT_TRUE(d.insert(42));
    EXPECT_EQ(42, d.search(42)->key);
    EXPECT_TRUE(d.remove(42));
    EXPECT_FALSE(d.remove(42));
    EXPECT_EQ(nullptr, d.search(42));
}
