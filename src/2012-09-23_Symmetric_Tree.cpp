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
 * File: 2012-09-23_Symmetric_Tree.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/symmetric-tree/
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 *
 * For example, this binary tree is symmetric:
 *
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 * But the following is not:
 *     1
 *    / \
 *   2   2
 *    \   \
 *    3    3
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 *
 *
 * Date: 2014.11.10
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>

// definition for binary tree;
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

class Solution_Symmetric_Tree {
public:

    void rotateTree(TreeNode *root) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            return;
        }
        
        rotateTree(root->left);
        rotateTree(root->right);

        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }

    bool isSame(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) {
            return true;
        } else if (p == NULL || q == NULL) {
            return false;
        }

        if (p->val == q->val) {
            bool l = isSame(p->left, q->left);
            bool r = isSame(p->right, q->right);
            return l && r;
        } else {
            return false;
        }
    }

    bool isSymmetric(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        if (root->left == NULL && root->right == NULL) {
            return true;
        }

        rotateTree(root->left);

        return isSame(root->left, root->right);
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
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right =  new TreeNode(2);

    TreeNode *left = root->left;
    left->left = new TreeNode(3);
    left->right = new TreeNode(4);

    TreeNode *right = root->right;
    right->left = new TreeNode(4);
    right->right = new TreeNode(3);

    return root;
}

static void releaseTree(TreeNode *root) {
    if (root != NULL) {
        releaseTree(root->left);
        releaseTree(root->right);
        delete root;
    }
}

int main(int argc, char *argv[]) {
    Solution_Symmetric_Tree solution;

    TreeNode *root = buildTree();
    bool symmetric = solution.isSymmetric(root);
    printf("symmetric = %d\n", symmetric);
    releaseTree(root);

    root = buildTree2();
    symmetric = solution.isSymmetric(root);
    printf("symmetric = %d\n", symmetric);
    releaseTree(root);

}

