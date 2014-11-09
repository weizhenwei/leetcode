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
 * File: 2013-11-05_Binary_Tree_Preorder_Traversal.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/binary-tree-preorder-traversal/
 * Given a binary tree, return the preorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 *  return [1,2,3].
 *
 *  Note: Recursive solution is trivial, could you do it iteratively?
 *
 *
 * Date: 2014.11.09
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

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

class Solution_Preorder_Traversal {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> preorder;
        stack<TreeNode *> tmpStack;
        TreeNode *ptr = root;
        if (ptr == NULL) {
            return preorder;
        }

        preorder.push_back(ptr->val);
        if (ptr->right != NULL) {
            tmpStack.push(ptr->right);
        }
        if (ptr->left != NULL) {
            tmpStack.push(ptr->left);
        }

        while (!tmpStack.empty()) {
            ptr = tmpStack.top();
            preorder.push_back(ptr->val);
            tmpStack.pop();

            if (ptr->right != NULL) {
                tmpStack.push(ptr->right);
            }
            if (ptr->left != NULL) {
                tmpStack.push(ptr->left);
            }
        }  // while

        return preorder;
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

static void releaseTree(TreeNode *root) {
    if (root != NULL) {
        releaseTree(root->left);
        releaseTree(root->right);
        delete root;
    }
}

static void print_vector(vector<int> v) {
    vector<int>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
        printf("%d ", *iter);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Preorder_Traversal solution;

    TreeNode *root = buildTree();

    vector<int> preorder = solution.preorderTraversal(root);
    print_vector(preorder);

    releaseTree(root);

    return 0;
}

