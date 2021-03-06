#include "test_avl_tree.h"
#include <memory>

/**
 * /test Test empty tree.
 */
TEST(AVLTreeTest, AVLTreeTest_EmptyTest) {
    avl_tree d;
    EXPECT_EQ(nullptr, d.preorder());
    EXPECT_EQ(nullptr, d.inorder());
    EXPECT_EQ(nullptr, d.postorder());
}

/**
 * /test Test search with non existing key.
 */
TEST(AVLTreeTest, AVLTreeTest_SearchTest_NonExistingKey) {
    avl_tree d;
    EXPECT_EQ(nullptr, d.search(42));
}

/**
 * /test Test insertion on left side.
 */
TEST(AVLTreeTest, AVLTreeTest_InsertionTest_Left) {
    avl_tree d;
    EXPECT_EQ(nullptr, d.search(42));

    EXPECT_TRUE(d.insert(69));
    EXPECT_FALSE(d.insert(69));
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.insert(42));

    auto root = d.search(69);
    EXPECT_EQ(2, root->height);

    auto node = d.search(42);
    EXPECT_EQ(node, root->left);
    EXPECT_EQ(nullptr, root->right);
    EXPECT_EQ(42, node->key);
    EXPECT_EQ(1, node->height);
}

/**
 * /test Test insertion on right side.
 */
TEST(AVLTreeTest, AVLTreeTest_SearchTest_Right) {
    avl_tree d;
    EXPECT_EQ(nullptr, d.search(42));

    EXPECT_TRUE(d.insert(69));
    EXPECT_FALSE(d.insert(69));
    EXPECT_TRUE(d.insert(1337));
    EXPECT_FALSE(d.insert(1337));

    auto root = d.search(69);
    EXPECT_EQ(2, root->height);

    auto node = d.search(1337);
    EXPECT_EQ(node, root->right);
    EXPECT_EQ(nullptr, root->left);
    EXPECT_EQ(1337, node->key);
    EXPECT_EQ(1, node->height);
}

/**
 * /test Test finding root.
 */
TEST(AVLTreeTest, AVLTreeTest_SearchTest_Root) {
    avl_tree d;
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.insert(42));
    auto node = d.search(42);
    EXPECT_EQ(nullptr, node->right);
    EXPECT_EQ(nullptr, node->left);
    EXPECT_EQ(42, node->key);
    EXPECT_EQ(1, node->height);
}

/**
 * /test Test inserting single element.
 */
TEST(AVLTreeTest, AVLTreeTest_InsertTest_Root) {
	avl_tree d;
	EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.insert(42));

	EXPECT_THAT(*d.preorder(), testing::ElementsAre(42));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(42));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(42));
}

/**
 * /test Test inserting node bigger than root.
 */
TEST(AVLTreeTest, AVLTreeTest_InsertTest_2_Rightside) {
    avl_tree d;
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.insert(42));
    EXPECT_TRUE(d.insert(1337));
    EXPECT_FALSE(d.insert(1337));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(42, 1337));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(42, 1337));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(1337, 42));
}

/**
 * /test Test inserting node smaller than root.
 */
TEST(AVLTreeTest, AVLTreeTest_InsertTest_2_Leftside) {
    avl_tree d;
    EXPECT_TRUE(d.insert(1337));
    EXPECT_FALSE(d.insert(1337));
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.insert(42));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(1337, 42));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(42, 1337));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(42, 1337));
}

TEST(AVLTreeTest, AVLTreeTest_InsertTest_3) {
    avl_tree d;
    EXPECT_TRUE(d.insert(69));
    EXPECT_FALSE(d.insert(69));
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.insert(42));
    EXPECT_TRUE(d.insert(1337));
    EXPECT_FALSE(d.insert(1337));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(69, 42, 1337));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(42, 69, 1337));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(42, 1337, 69));
}

TEST(AVLTreeTest, AVLTreeTest_InsertTest_3_Bigger) {
    avl_tree d;
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.insert(42));
    EXPECT_TRUE(d.insert(69));
    EXPECT_FALSE(d.insert(69));
    EXPECT_TRUE(d.insert(1337));
    EXPECT_FALSE(d.insert(1337));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(69, 42, 1337));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(42, 69, 1337));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(42, 1337, 69));
}

TEST(AVLTreeTest, AVLTreeTest_InsertTest_3_Smaller) {
    avl_tree d;
    EXPECT_TRUE(d.insert(1337));
    EXPECT_FALSE(d.insert(1337));
    EXPECT_TRUE(d.insert(69));
    EXPECT_FALSE(d.insert(69));
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.insert(42));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(69, 42, 1337));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(42, 69, 1337));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(42, 1337, 69));
}

TEST(AVLTreeTest, AVLTreeTest_InsertTest_4) {
    avl_tree d;
    EXPECT_FALSE(d.remove(1));
    EXPECT_TRUE(d.insert(1));
    EXPECT_FALSE(d.remove(42));
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.remove(69));
    EXPECT_TRUE(d.insert(69));
    EXPECT_FALSE(d.remove(420));
    EXPECT_TRUE(d.insert(420));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(42, 1, 69, 420));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(1, 42, 69, 420));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(1, 420, 69, 42));
}

TEST(AVLTreeTest, AVLTreeTest_InsertTest_5) {
    avl_tree d;
    EXPECT_FALSE(d.remove(1));
    EXPECT_TRUE(d.insert(1));
    EXPECT_FALSE(d.remove(42));
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.remove(69));
    EXPECT_TRUE(d.insert(69));
    EXPECT_FALSE(d.remove(420));
    EXPECT_TRUE(d.insert(420));
    EXPECT_FALSE(d.remove(666));
    EXPECT_TRUE(d.insert(666));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(42, 1, 420, 69, 666));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(1, 42, 69, 420, 666));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(1, 69, 666, 420, 42));
}

TEST(AVLTreeTest, AVLTreeTest_InsertTest_6) {
    avl_tree d;
    EXPECT_FALSE(d.remove(1));
    EXPECT_TRUE(d.insert(1));
    EXPECT_FALSE(d.remove(42));
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.remove(69));
    EXPECT_TRUE(d.insert(69));
    EXPECT_FALSE(d.remove(420));
    EXPECT_TRUE(d.insert(420));
    EXPECT_FALSE(d.remove(666));
    EXPECT_TRUE(d.insert(666));
    EXPECT_FALSE(d.remove(1337));
    EXPECT_TRUE(d.insert(1337));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(420, 42, 1, 69, 666, 1337));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(1, 42, 69, 420, 666, 1337));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(1, 69, 42, 1337, 666, 420));
}

TEST(AVLTreeTest, AVLTreeTest_InsertTest_7) {
    avl_tree d;
    EXPECT_FALSE(d.remove(1));
    EXPECT_TRUE(d.insert(1));
    EXPECT_FALSE(d.remove(42));
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.remove(69));
    EXPECT_TRUE(d.insert(69));
    EXPECT_FALSE(d.remove(420));
    EXPECT_TRUE(d.insert(420));
    EXPECT_FALSE(d.remove(666));
    EXPECT_TRUE(d.insert(666));
    EXPECT_FALSE(d.remove(1337));
    EXPECT_TRUE(d.insert(1337));
    EXPECT_FALSE(d.remove(9001));
    EXPECT_TRUE(d.insert(9001));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(420, 42, 1, 69, 1337, 666, 9001));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(1, 42, 69, 420, 666, 1337, 9001));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(1, 69, 42, 666, 9001, 1337, 420));
}

TEST(AVLTreeTest, AVLTreeTest_RemoveTest_1) {
    avl_tree d;
    EXPECT_FALSE(d.remove(42));
    EXPECT_TRUE(d.insert(42));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(42));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(42));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(42));

    EXPECT_TRUE(d.remove(42));
    EXPECT_FALSE(d.remove(42));

    EXPECT_EQ(nullptr, d.preorder());
}

TEST(AVLTreeTest, AVLTreeTest_RemoveTest_Root_Right) {
    avl_tree d;
    EXPECT_FALSE(d.remove(42));
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.remove(1337));
    EXPECT_TRUE(d.insert(1337));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(42, 1337));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(42, 1337));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(1337, 42));

    EXPECT_TRUE(d.remove(42));
    EXPECT_FALSE(d.remove(42));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(1337));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(1337));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(1337));
}

TEST(AVLTreeTest, AVLTreeTest_RemoveTest_Root_Left) {
    avl_tree d;
    EXPECT_FALSE(d.remove(1337));
    EXPECT_TRUE(d.insert(1337));
    EXPECT_FALSE(d.remove(42));
    EXPECT_TRUE(d.insert(42));

    EXPECT_TRUE(d.remove(1337));
    EXPECT_FALSE(d.remove(1337));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(42));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(42));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(42));
}

TEST(AVLTreeTest, AVLTreeTest_RemoveTest_Root_Rang2) {
    avl_tree d;
    EXPECT_FALSE(d.remove(69));
    EXPECT_TRUE(d.insert(69));
    EXPECT_FALSE(d.remove(1));
    EXPECT_TRUE(d.insert(1));
    EXPECT_FALSE(d.remove(420));
    EXPECT_TRUE(d.insert(420));
    EXPECT_FALSE(d.remove(42));
    EXPECT_TRUE(d.insert(42));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(69, 1, 42, 420));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(1, 42, 69, 420));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(42, 1, 420, 69));

    EXPECT_TRUE(d.remove(69));
    EXPECT_FALSE(d.remove(69));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(42, 1, 420));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(1, 42, 420));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(1, 420, 42));
}

TEST(AVLTreeTest, AVLTreeTest_RemoveTest_Inbetween_Right) {
    avl_tree d;
    EXPECT_FALSE(d.remove(1));
    EXPECT_TRUE(d.insert(1));
    EXPECT_FALSE(d.remove(42));
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.remove(69));
    EXPECT_TRUE(d.insert(69));
    EXPECT_FALSE(d.remove(420));
    EXPECT_TRUE(d.insert(420));
    EXPECT_FALSE(d.remove(666));
    EXPECT_TRUE(d.insert(666));
    EXPECT_FALSE(d.remove(1337));
    EXPECT_TRUE(d.insert(1337));
    EXPECT_FALSE(d.remove(9001));
    EXPECT_TRUE(d.insert(9001));

    EXPECT_TRUE(d.remove(1337));
    EXPECT_FALSE(d.remove(1337));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(420, 42, 1, 69, 666, 9001));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(1, 42, 69, 420, 666, 9001));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(1, 69, 42, 9001, 666, 420));
}

TEST(AVLTreeTest, AVLTreeTest_RemoveTest_Inbetween_Left) {
    avl_tree d;
    EXPECT_FALSE(d.remove(1));
    EXPECT_TRUE(d.insert(1));
    EXPECT_FALSE(d.remove(42));
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.remove(69));
    EXPECT_TRUE(d.insert(69));
    EXPECT_FALSE(d.remove(420));
    EXPECT_TRUE(d.insert(420));
    EXPECT_FALSE(d.remove(666));
    EXPECT_TRUE(d.insert(666));
    EXPECT_FALSE(d.remove(1337));
    EXPECT_TRUE(d.insert(1337));
    EXPECT_FALSE(d.remove(9001));
    EXPECT_TRUE(d.insert(9001));

    EXPECT_TRUE(d.remove(42));
    EXPECT_FALSE(d.remove(42));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(420, 1, 69, 1337, 666, 9001));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(1, 69, 420, 666, 1337, 9001));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(69, 1, 666, 9001, 1337, 420));
}


TEST(AVLTreeTest, AVLTreeTest_RemoveTest_Inbetween_Right_More) {
    avl_tree d;
    EXPECT_FALSE(d.remove(1));
    EXPECT_TRUE(d.insert(1));
    EXPECT_FALSE(d.remove(42));
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.remove(69));
    EXPECT_TRUE(d.insert(69));
    EXPECT_FALSE(d.remove(420));
    EXPECT_TRUE(d.insert(420));
    EXPECT_FALSE(d.remove(666));
    EXPECT_TRUE(d.insert(666));
    EXPECT_FALSE(d.remove(1337));
    EXPECT_TRUE(d.insert(1337));
    EXPECT_FALSE(d.remove(9001));
    EXPECT_TRUE(d.insert(9001));
    EXPECT_FALSE(d.remove(665));
    EXPECT_TRUE(d.insert(665));
    EXPECT_FALSE(d.remove(667));
    EXPECT_TRUE(d.insert(667));

    EXPECT_TRUE(d.remove(1337));
    EXPECT_FALSE(d.remove(1337));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(420, 42, 1, 69, 667, 666, 665, 9001));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(1, 42, 69, 420, 665, 666, 667, 9001));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(1, 69, 42, 665, 666, 9001, 667, 420));
}

TEST(AVLTreeTest, AVLTreeTest_RemoveTest_Inbetween_Left_More) {
    avl_tree d;
    EXPECT_FALSE(d.remove(1));
    EXPECT_TRUE(d.insert(1));
    EXPECT_FALSE(d.remove(42));
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.remove(69));
    EXPECT_TRUE(d.insert(69));
    EXPECT_FALSE(d.remove(420));
    EXPECT_TRUE(d.insert(420));
    EXPECT_FALSE(d.remove(666));
    EXPECT_TRUE(d.insert(666));
    EXPECT_FALSE(d.remove(1337));
    EXPECT_TRUE(d.insert(1337));
    EXPECT_FALSE(d.remove(9001));
    EXPECT_TRUE(d.insert(9001));
    EXPECT_FALSE(d.remove(0));
    EXPECT_TRUE(d.insert(0));
    EXPECT_FALSE(d.remove(2));
    EXPECT_TRUE(d.insert(2));

    EXPECT_TRUE(d.remove(42));
    EXPECT_FALSE(d.remove(42));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(420, 2, 1, 0, 69, 1337, 666, 9001));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(0, 1, 2, 69, 420, 666, 1337, 9001));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(0, 1, 69, 2, 666, 9001, 1337, 420));
}

TEST(AVLTreeTest, AVLTreeTest_RemoveTest_Leafs) {
    avl_tree d;
    EXPECT_FALSE(d.remove(1));
    EXPECT_TRUE(d.insert(1));
    EXPECT_FALSE(d.remove(42));
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.remove(69));
    EXPECT_TRUE(d.insert(69));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(42, 1, 69));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(1, 42, 69));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(1, 69, 42));

    EXPECT_TRUE(d.remove(1));
    EXPECT_FALSE(d.remove(1));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(42, 69));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(42, 69));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(69, 42));

    EXPECT_TRUE(d.remove(69));
    EXPECT_FALSE(d.remove(69));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(42));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(42));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(42));
}

TEST(AVLTreeTest, AVLTreeTest_RemoveTest_Inbetween_FarLeft_FarRight) {
    avl_tree d;
    EXPECT_FALSE(d.remove(69));
    EXPECT_TRUE(d.insert(69));
    EXPECT_FALSE(d.remove(42));
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.remove(420));
    EXPECT_TRUE(d.insert(420));
    EXPECT_FALSE(d.remove(1));
    EXPECT_TRUE(d.insert(1));
    EXPECT_FALSE(d.remove(666));
    EXPECT_TRUE(d.insert(666));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(69, 42, 1, 420, 666));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(1, 42, 69, 420, 666));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(1, 42, 666, 420, 69));

    EXPECT_TRUE(d.remove(42));
    EXPECT_FALSE(d.remove(42));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(69, 1, 420, 666));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(1, 69, 420, 666));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(1, 666, 420, 69));

    EXPECT_TRUE(d.remove(420));
    EXPECT_FALSE(d.remove(420));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(69, 1, 666));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(1, 69, 666));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(1, 666, 69));
}


TEST(AVLTreeTest, AVLTreeTest_RemoveTest_Inbetween_InnerLeft_InnerRight) {
    avl_tree d;
    EXPECT_FALSE(d.remove(69));
    EXPECT_TRUE(d.insert(69));
    EXPECT_FALSE(d.remove(1));
    EXPECT_TRUE(d.insert(1));
    EXPECT_FALSE(d.remove(666));
    EXPECT_TRUE(d.insert(666));
    EXPECT_FALSE(d.remove(42));
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.remove(420));
    EXPECT_TRUE(d.insert(420));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(69, 1, 42, 666, 420));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(1, 42, 69, 420, 666));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(42, 1, 420, 666, 69));

    EXPECT_TRUE(d.remove(1));
    EXPECT_FALSE(d.remove(1));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(69, 42, 666, 420));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(42, 69, 420, 666));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(42, 420, 666, 69));

    EXPECT_TRUE(d.remove(666));
    EXPECT_FALSE(d.remove(666));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(69, 42, 420));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(42, 69, 420));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(42, 420, 69));
}

TEST(AVLTreeTest, AVLTreeTest_InsertTest_3_Double_Rotation_Right) {
    avl_tree d;
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.insert(42));
    EXPECT_TRUE(d.insert(1337));
    EXPECT_FALSE(d.insert(1337));
    EXPECT_TRUE(d.insert(69));
    EXPECT_FALSE(d.insert(69));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(69, 42, 1337));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(42, 69, 1337));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(42, 1337, 69));
}

TEST(AVLTreeTest, AVLTreeTest_InsertTest_3_Double_Rotation_Left) {
    avl_tree d;
    EXPECT_TRUE(d.insert(1337));
    EXPECT_FALSE(d.insert(1337));
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.insert(42));
    EXPECT_TRUE(d.insert(69));
    EXPECT_FALSE(d.insert(69));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(69, 42, 1337));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(42, 69, 1337));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(42, 1337, 69));
}
