/*
 *
 * Copyright (c) 2015, weizhenwei
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
 * File: 226-Invert_Binary_Tree.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/invert-binary-trees/
 * Invert a binary tree.
 *
 *      4
 *    /   \
 *   2     7
 *  / \   / \
 * 1   3 6   9
 *
 *    to
 *          4
 *        /   \
 *       7     2
 *      / \   / \
 *     9   6 3   1
 *
 *
 * Date: 2015.09.21
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

class Solution_Invert_Binary_Tree {
public:
    TreeNode* invertTreeRecursive(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return root;
        }
        
        if (root->left) {
            root->left = invertTreeRecursive(root->left);
        }
        if (root->right) {
            root->right = invertTreeRecursive(root->right);
        }
        TreeNode *tmpNode = root->left;
        root->left = root->right;
        root->right = tmpNode;
        
        return root;
    }

    TreeNode* invertTreeIterative(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return root;
        }

        stack<TreeNode*> theStack;
        theStack.push(root);
        while (!theStack.empty()) {
            TreeNode *topNode = theStack.top();
            if (topNode->left == NULL && topNode->right == NULL) {
                theStack.pop();
            } else {
                TreeNode *tmpNode = topNode->left;
                topNode->left = topNode->right;
                topNode->right = tmpNode;
                
                theStack.pop();
                if (topNode->left) {
                    theStack.push(topNode->left);
                }
                if (topNode->right) {
                    theStack.push(topNode->right);
                }
            }
        }  // while

        return root;
    }
};

static void print_tree(TreeNode *root) {
    if (root) {
        if (root->left) {
            if (root->left->left) {
                printf("root->left->left:%d\n", root->left->left->val);
            }
            printf("root->left:%d\n", root->left->val);
            if (root->left->right) {
                printf("root->left->right:%d\n", root->left->right->val);
            }
        }
        printf("root:%d\n", root->val);
        if (root->right) {
            if (root->right->left) {
                printf("root->right->left:%d\n", root->right->left->val);
            }
            printf("root->right:%d\n", root->right->val);
            if (root->right->right) {
                printf("root->right->right:%d\n", root->right->right->val);
            }
        }
    }
    
    printf("\n");
}

static void testcase() {
    Solution_Invert_Binary_Tree solution;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    print_tree(root);
    root = solution.invertTreeIterative(root);
    print_tree(root);

}

int main(int argc, char *argv[]) {
    testcase();
    
    return 0;
}

