/*
 *
 * Copyright (c) 2014, weizhenwei
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * 
 * * Neither the name of the {organization} nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * File: 2012-08-31_Validate_Binary_Search_Tree.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/validate-binary-search-tree/
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 * The left subtree of a node contains only nodes with keys less than the node's
 * key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 * Date: 2014.11.11
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <assert.h>
#include <stdio.h>
#include <stack>
#include <vector>

using std::stack;
using std::vector;

// definition for binary tree;
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution_Validate_Binary_Search_Tree {
public:
    int findMax(TreeNode *root) {
        if (root->left == NULL && root->right == NULL) {
            return root->val;
        }
        int max = root->val;
        if (root->left != NULL) {
            int leftmax = findMax(root->left);
            if (max < leftmax)
                max = leftmax;
        }
        if (root->right != NULL) {
            int rightmax = findMax(root->right);
            if (max < rightmax)
                max = rightmax;
        }

        return max;
    }

    int findMin(TreeNode *root) {
        if (root->left == NULL && root->right == NULL) {
            return root->val;
        }
        int min = root->val;
        if (root->left != NULL) {
            int leftmin = findMin(root->left);
            if (min > leftmin)
                min = leftmin;
        }
        if (root->right != NULL) {
            int rightmin = findMin(root->right);
            if (min > rightmin)
                min = rightmin;
        }

        return min;
    }

    bool isValidBST(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        if (root->left != NULL) {
            int leftMax = findMax(root->left);
            if (leftMax >= root->val) {
                return false;
            }
        }
        if (root->right != NULL) {
            int rightMin = findMin(root->right);
            if (rightMin <= root->val) {
                return false;
            }
        }

        bool l, r;
        if (root->left != NULL) {
            l = isValidBST(root->left);
        } else {
            l = true;
        }
        if (root->right != NULL) {
            r = isValidBST(root->right);
        } else {
            r = true;
        }

        return l && r;
    }
};

static TreeNode *buildTree() {
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right =  new TreeNode(3);

    TreeNode *left = root->left;
    left->left = new TreeNode(4);
    left->right = new TreeNode(5);
    left->right->left = new TreeNode(6);

    TreeNode *right = root->right;
    right->left = new TreeNode(7);
    right->right = new TreeNode(8);
    right->right->left = new TreeNode(9);
    right->right->right = new TreeNode(10);

    return root;
}

static TreeNode *buildTree2() {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right =  new TreeNode(7);

    TreeNode *left = root->left;
    left->left = new TreeNode(2);
    left->right = new TreeNode(4);

    TreeNode *right = root->right;
    right->left = new TreeNode(6);
    right->right = new TreeNode(8);

    return root;
}

static TreeNode *buildTree3() {
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right =  new TreeNode(15);

    TreeNode *right = root->right;
    right->left = new TreeNode(6);
    right->right = new TreeNode(20);

    return root;
}

static void releaseTree(TreeNode *root) {
    if (root != NULL) {
        releaseTree(root->left);
        releaseTree(root->right);
        delete root;
    }
}

static void printTree(TreeNode *root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->val);
    printTree(root->left);
    printTree(root->right);
}

int main(int argc, char *argv[]) {
    Solution_Validate_Binary_Search_Tree solution;

    TreeNode *root = buildTree();
    bool valid = solution.isValidBST(root);
    printf("tree in preorder:");
    printTree(root);
    printf("\n");
    printf("is binary search tree:%d\n", valid);
    releaseTree(root);

    root = buildTree2();
    valid = solution.isValidBST(root);
    printf("tree in preorder:");
    printTree(root);
    printf("\n");
    printf("is binary search tree:%d\n", valid);
    releaseTree(root);

    root = buildTree3();
    valid = solution.isValidBST(root);
    printf("tree in preorder:");
    printTree(root);
    printf("\n");
    printf("is binary search tree:%d\n", valid);
    releaseTree(root);

    return 0;
}

