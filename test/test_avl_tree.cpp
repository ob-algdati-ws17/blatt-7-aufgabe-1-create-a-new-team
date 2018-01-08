#include "test_avl_tree.h"
#include <memory>

TEST(AVLTreeTest, AVLTreeTest_EmptyTest) {
    avl_tree d;
    EXPECT_EQ(nullptr, d.preorder());
}

TEST(AVLTreeTest, AVLTreeTest_InsertTest_1) {
	avl_tree d;
	EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.insert(42));

	EXPECT_THAT(*d.preorder(), testing::ElementsAre(42));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(42));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(42));
}

TEST(AVLTreeTest, AVLTreeTest_InsertTest_2_Right) {
    avl_tree d;
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.insert(42));
    EXPECT_TRUE(d.insert(1337));
    EXPECT_FALSE(d.insert(1337));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(42, 1337));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(42, 1337));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(1337, 42));
}

TEST(AVLTreeTest, AVLTreeTest_InsertTest_2_Left) {
    avl_tree d;
    EXPECT_TRUE(d.insert(1337));
    EXPECT_FALSE(d.insert(1337));
    EXPECT_TRUE(d.insert(42));
    EXPECT_FALSE(d.insert(42));

    EXPECT_THAT(*d.preorder(), testing::ElementsAre(1337, 42));
    EXPECT_THAT(*d.inorder(), testing::ElementsAre(42, 1337));
    EXPECT_THAT(*d.postorder(), testing::ElementsAre(42, 1337));
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


TEST(AVLTreeTest, AVLTreeTest_RemoveTest_Root) {
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
