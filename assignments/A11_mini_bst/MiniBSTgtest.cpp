/**
* @file MiniBSTgtest.cpp
* @brief
*
* @author james 
* @date  7/8/2026.
*/

#include <algorithm>
#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "mini_bst.h"


class MiniBSTTest: public ::testing::Test {
protected:
    BSTNode* root = nullptr;
    static constexpr std::array<std::string, 7> expectedBalanced{"m", "g", "t", "d", "j", "p", "w"};
    static constexpr std::array<std::string, 4> leftHeavy{"m", "g", "d", "a"};

    void TearDown() override {
        destroyTestTree(root);
    }

    static void destroyTestTree(BSTNode*& node) {
        if (node) {
            destroyTestTree(node->left);
            destroyTestTree(node->right);
            delete node;
            node = nullptr;
        }
    }

    static std::vector<KeyType> getKeys(BSTNode* root) {
        std::vector<KeyType> result;
        mini_bst::keys(root, result);
        return result;
    }

    void buildBalancedTree() {
        mini_bst::clear(root);

        root = new BSTNode{expectedBalanced[0]};
        root->left = new BSTNode{expectedBalanced[1]};
        root->right = new BSTNode{expectedBalanced[2]};

        root->left->left = new BSTNode{expectedBalanced[3]};
        root->left->right = new BSTNode{expectedBalanced[4]};

        root->right->left = new BSTNode{expectedBalanced[5]};
        root->right->right = new BSTNode{expectedBalanced[6]};

        root->height = 2;

        root->left->height = 1;
        root->right->height = 1;

        root->left->left->height = 0;
        root->left->right->height = 0;
        root->right->left->height = 0;
        root->right->right->height = 0;
    }

    void buildLeftHeavyTree() {
        mini_bst::clear(root);

        root = new BSTNode{leftHeavy[0]};
        root->left = new BSTNode{leftHeavy[1]};
        root->left->left = new BSTNode{leftHeavy[2]};
        root->left->left->left = new BSTNode{leftHeavy[3]};

        root->height = 3;
        root->left->height = 2;
        root->left->left->height = 1;
        root->left->left->left->height = 0;
    }

    void buildSimpleTree() {
        mini_bst::clear(root);

        root = new BSTNode{expectedBalanced[0]};
        root->left = new BSTNode{expectedBalanced[1]};
        root->right = new BSTNode{expectedBalanced[2]};

        root->height = 1;
        root->left->height = 0;
        root->right->height = 0;
    }

    void expectSimpleTreeUnchanged(BSTNode* oldRoot,
                                   BSTNode* oldLeft,
                                   BSTNode* oldRight) {
        ASSERT_NE(root, nullptr);
        ASSERT_NE(root->left, nullptr);
        ASSERT_NE(root->right, nullptr);

        EXPECT_EQ(root, oldRoot);
        EXPECT_EQ(root->left, oldLeft);
        EXPECT_EQ(root->right, oldRight);

        EXPECT_EQ(root->key, expectedBalanced[0]);
        EXPECT_EQ(root->left->key, expectedBalanced[1]);
        EXPECT_EQ(root->right->key, expectedBalanced[2]);

        EXPECT_EQ(root->height, 1);
        EXPECT_EQ(root->left->height, 0);
        EXPECT_EQ(root->right->height, 0);
    }
};

TEST_F(MiniBSTTest, EmptyTreeHasExpectedBehavior) {
    EXPECT_EQ(mini_bst::search(root, "apple"), nullptr);

    std::vector<KeyType> result;
    mini_bst::keys(root, result);
    EXPECT_TRUE(result.empty());

    EXPECT_EQ(mini_bst::node_height(root), -1);
    EXPECT_EQ(mini_bst::balance_factor(root), 0);

    mini_bst::clear(root);
    EXPECT_EQ(root, nullptr);
}

TEST_F(MiniBSTTest, InsertFirstBSTNodeCreatesRoot) {
    BSTNode* node = new BSTNode{"m"};

    EXPECT_TRUE(mini_bst::insert(root, node));

    ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->key, "m");
    EXPECT_EQ(root->left, nullptr);
    EXPECT_EQ(root->right, nullptr);
    EXPECT_EQ(root->height, 0);
}

TEST_F(MiniBSTTest, InsertUpdatesHeightsOnBalancedShape) {
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[0]}));
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[1]}));
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[2]}));
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[3]}));
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[4]}));
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[5]}));
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[6]}));

    ASSERT_NE(root, nullptr);

    EXPECT_EQ(root->height, 2);

    ASSERT_NE(root->left, nullptr);
    ASSERT_NE(root->right, nullptr);

    EXPECT_EQ(root->left->height, 1);
    EXPECT_EQ(root->right->height, 1);

    EXPECT_EQ(root->left->left->height, 0);
    EXPECT_EQ(root->left->right->height, 0);
    EXPECT_EQ(root->right->left->height, 0);
    EXPECT_EQ(root->right->right->height, 0);
}

TEST_F(MiniBSTTest, InsertUpdatesHeightsOnUnbalancedShape) {
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{leftHeavy[0]}));
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{leftHeavy[1]}));
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{leftHeavy[2]}));
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{leftHeavy[3]}));

    ASSERT_NE(root, nullptr);

    EXPECT_EQ(root->height, 3);
    EXPECT_EQ(root->left->height, 2);
    EXPECT_EQ(root->left->left->height, 1);
    EXPECT_EQ(root->left->left->left->height, 0);
}

TEST_F(MiniBSTTest, SearchFindsInsertedKeys) {
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[0]}));
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[1]}));
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[2]}));
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[3]}));
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[4]}));

    BSTNode* found = mini_bst::search(root, expectedBalanced[1]);

    ASSERT_NE(found, nullptr);
    EXPECT_EQ(found->key, expectedBalanced[1]);

    EXPECT_EQ(mini_bst::search(root, "missing"), nullptr);
}

TEST_F(MiniBSTTest, SizeReturnsZeroForEmptyTree) {
    EXPECT_EQ(mini_bst::size(root), 0);
}

TEST_F(MiniBSTTest, SizeUpdatesAfterInsert) {
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[0]}));
    EXPECT_EQ(mini_bst::size(root), 1);

    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[1]}));
    EXPECT_EQ(mini_bst::size(root), 2);

    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[2]}));
    EXPECT_EQ(mini_bst::size(root), 3);

    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[3]}));
    EXPECT_EQ(mini_bst::size(root), 4);

    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[4]}));
    EXPECT_EQ(mini_bst::size(root), 5);

    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[5]}));
    EXPECT_EQ(mini_bst::size(root), 6);

    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[6]}));
    EXPECT_EQ(mini_bst::size(root), 7);
}

TEST_F(MiniBSTTest, SizeUnchangedAfterInsertDuplicate) {
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[0]}));
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[1]}));
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[2]}));
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[3]}));
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[4]}));
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[5]}));
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{expectedBalanced[6]}));

    EXPECT_FALSE(mini_bst::insert(root, new BSTNode{expectedBalanced[3]}));
    EXPECT_EQ(mini_bst::size(root), 7);
}

TEST_F(MiniBSTTest, SizeReturnsZeroAfterClear) {
    // EXPECT_TRUE(insert(root, new BSTNode{"m"}));
    // EXPECT_TRUE(insert(root, new BSTNode{"g"}));
    // EXPECT_TRUE(insert(root, new BSTNode{"t"}));
    // EXPECT_TRUE(insert(root, new BSTNode{"d"}));
    // EXPECT_TRUE(insert(root, new BSTNode{"j"}));
    // EXPECT_TRUE(insert(root, new BSTNode{"p"}));
    // EXPECT_TRUE(insert(root, new BSTNode{"w"}));

    buildBalancedTree();
    EXPECT_EQ(mini_bst::size(root), 7);

    mini_bst::clear(root);
    EXPECT_EQ(root, nullptr);
    EXPECT_EQ(mini_bst::size(root), 0);
}


TEST_F(MiniBSTTest, KeysReturnsInSortedOrder) {
    // EXPECT_TRUE(insert(root, new BSTNode{"m"}));
    // EXPECT_TRUE(insert(root, new BSTNode{"g"}));
    // EXPECT_TRUE(insert(root, new BSTNode{"t"}));
    // EXPECT_TRUE(insert(root, new BSTNode{"d"}));
    // EXPECT_TRUE(insert(root, new BSTNode{"j"}));
    // EXPECT_TRUE(insert(root, new BSTNode{"p"}));
    // EXPECT_TRUE(insert(root, new BSTNode{"w"}));
buildBalancedTree();
    std::vector expected(expectedBalanced.begin(), expectedBalanced.end());
    std::ranges::sort(expected.begin(), expected.end());
    EXPECT_EQ(getKeys(root), expected);
}


TEST_F(MiniBSTTest, BalanceFactorUsesStoredHeights) {
    // EXPECT_TRUE(insert(root, new BSTNode{"m"}));
    // EXPECT_TRUE(insert(root, new BSTNode{"g"}));
    // EXPECT_TRUE(insert(root, new BSTNode{"d"}));

    buildLeftHeavyTree();

    ASSERT_NE(root, nullptr);

    // Assumes balanceFactor is height(left) - height(right).
    EXPECT_EQ(mini_bst::balance_factor(root), 3);
    EXPECT_EQ(mini_bst::balance_factor(root->left), 2);
    EXPECT_EQ(mini_bst::balance_factor(root->left->left), 1);
}

TEST_F(MiniBSTTest, DuplicateInsertReturnsFalseAndDoesNotChangeTree) {
    buildSimpleTree();

    BSTNode* oldRoot = root;
    BSTNode* oldLeft = root->left;
    BSTNode* oldRight = root->right;

    BSTNode* duplicate = new BSTNode{oldLeft->key};

    EXPECT_FALSE(mini_bst::insert(root, duplicate));

    // Failed insert should not take ownership of duplicate
    delete duplicate;

    expectSimpleTreeUnchanged(oldRoot, oldLeft, oldRight);

    std::vector<KeyType> expected{"g", "m", "t"};
    EXPECT_EQ(getKeys(root), expected);
}

TEST_F(MiniBSTTest, ClearDeletesTreeAndSetsRootToNull) {
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{"m"}));
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{"g"}));
    EXPECT_TRUE(mini_bst::insert(root, new BSTNode{"t"}));

    mini_bst::clear(root);

    EXPECT_EQ(root, nullptr);

    // Calling clear again should be safe.
    mini_bst::clear(root);
    EXPECT_EQ(root, nullptr);
}

TEST_F(MiniBSTTest, RemoveLeafNode) {
    buildSimpleTree();

    EXPECT_TRUE(mini_bst::remove(root, "g"));

    std::vector<KeyType> expected{"m", "t"};
    EXPECT_EQ(getKeys(root), expected);
    EXPECT_EQ(mini_bst::search(root, "g"), nullptr);
    EXPECT_EQ(root->height, 1);
}

TEST_F(MiniBSTTest, RemoveNodeWithOneChild) {
    buildSimpleTree();

    EXPECT_TRUE(mini_bst::remove(root, "g"));

    std::vector<KeyType> expected{"m", "t"};
    EXPECT_EQ(getKeys(root), expected);

    ASSERT_NE(root->right, nullptr);
    EXPECT_EQ(root->right->key, "t");
    EXPECT_EQ(root->height, 1);
}

TEST_F(MiniBSTTest, RemoveNodeWithTwoChildren) {
    buildBalancedTree();

    EXPECT_TRUE(mini_bst::remove(root, "g"));

    std::vector<KeyType> expected{"d", "j", "m", "p", "t", "w"};
    EXPECT_EQ(getKeys(root), expected);
    EXPECT_EQ(mini_bst::search(root, "g"), nullptr);
}

TEST_F(MiniBSTTest, RemoveTwoChildNodeReturnsDetachedSuccessor) {
    mini_bst::insert(root, new BSTNode{"m"});
    mini_bst::insert(root, new BSTNode{"g"});
    mini_bst::insert(root, new BSTNode{"t"});
    mini_bst::insert(root, new BSTNode{"p"});
    mini_bst::insert(root, new BSTNode{"w"});

    BSTNode* removed = mini_bst::remove(root, "m");

    ASSERT_NE(removed, nullptr);

    // The logical key removed was "m", but the physically detached node
    // is the successor.
    EXPECT_EQ(removed->key, "p");
    EXPECT_EQ(removed->left, nullptr);
    EXPECT_EQ(removed->right, nullptr);

    EXPECT_EQ(root->key, "p");

    delete removed;
}
