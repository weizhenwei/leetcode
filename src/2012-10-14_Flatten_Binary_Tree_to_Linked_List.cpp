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
 * File: 2012-10-14_Flatten_Binary_Tree_to_Linked_List.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/
 * Given a binary tree, flatten it to a linked list in-place.
 *
 * For example,
 * Given
 *          1
 *         / \
 *        2   5
 *       / \   \
 *      3   4   6
 *  The flattened tree should look like:
 *          1
 *           \
 *            2
 *             \
 *              3
 *               \
 *                4
 *                 \
 *                  5
 *                   \
 *                    6
 *
 * Hints: If you notice carefully in the flattened tree, each node's
 *        right child points to the next node of a pre-order traversal.
 *
 * Date: 2014.11.11
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

class Solution_Flatten_Binary_Tree_to_Linked_List {
public:
    void flatten(TreeNode *root) {
        stack<TreeNode *> tmpStack;
        TreeNode *ptr = root;
        if (ptr == NULL) {
            return;
        }


        if (ptr->right != NULL) {
            tmpStack.push(ptr->right);
        }
        if (ptr->left != NULL) {
            tmpStack.push(ptr->left);
        }

        TreeNode *tmp = NULL;
        ptr = root;
        while (!tmpStack.empty()) {
            tmp = tmpStack.top();
            tmpStack.pop();

            ptr->left = NULL;
            ptr->right = tmp;
            ptr = ptr->right;

            if (tmp->right != NULL) {
                tmpStack.push(tmp->right);
            }
            if (tmp->left != NULL) {
                tmpStack.push(tmp->left);
            }
        }  // while
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

static void printTree(TreeNode *root) {
    TreeNode *ptr = root;
    while (ptr != NULL) {
        printf("%d ", ptr->val);
        if (ptr->right != NULL) {
            ptr = ptr->right;
        } else {
            break;
        }
    }  // while

    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Flatten_Binary_Tree_to_Linked_List solution;

    TreeNode *root = buildTree();

    solution.flatten(root);
    printTree(root);

    releaseTree(root);

    return 0;
}

