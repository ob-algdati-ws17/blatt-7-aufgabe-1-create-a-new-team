#include "test_avl_tree.h"
#include <memory>

TEST(AVLTreeTest, AVLTreeTest_EmptyTest) {
    avl_tree d;
    EXPECT_EQ(nullptr, d.preorder());
}

TEST(AVLTreeTest, AVLTreeTest_SearchTest_NonExistingKey) {
    avl_tree d;
    EXPECT_EQ(nullptr, d.search(42));
}

TEST(AVLTreeTest, AVLTreeTest_SearchTest_1) {
    avl_tree d;
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.insert(42));
    auto node = d.search(42);
    EXPECT_EQ(42, node->key);
    EXPECT_EQ(1, node->height);
}

TEST(AVLTreeTest, AVLTreeTest_InsertTest_1) {
	avl_tree d;
	EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.insert(42));

	EXPECT_THAT(*d.preorder(), testing::ElementsAre(42));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(42));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(42));
}

TEST(AVLTreeTest, AVLTreeTest_InsertTest_2_Bigger) {
    avl_tree d;
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.insert(42));
    EXPECT_TRUE(d.insert(1337));
    EXPECT_FALSE(d.insert(1337));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(42, 1337));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(42, 1337));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(1337, 42));
}

TEST(AVLTreeTest, AVLTreeTest_InsertTest_2_Smaller) {
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

TEST(AVLTreeTest, AVLTreeTest_RemoveTest_Root_2) {
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

TEST(AVLTreeTest, AVLTreeTest_RemoveTest_Root_3) {
    avl_tree d;
    EXPECT_FALSE(d.remove(42));
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.remove(69));
    EXPECT_TRUE(d.insert(69));
    EXPECT_FALSE(d.remove(1337));
    EXPECT_TRUE(d.insert(1337));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(69, 42, 1337));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(42, 69, 1337));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(42, 1337, 69));

    EXPECT_TRUE(d.remove(69));
    EXPECT_FALSE(d.remove(69));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(42, 1337));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(42, 1337));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(1337, 42));
}

TEST(AVLTreeTest, AVLTreeTest_RemoveTest_Inbetween) {
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