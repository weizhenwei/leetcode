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
 * File: 2013-11-07_Binary_Tree_Postorder_Traversal.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/binary-tree-postorder-traversal/
 * Given a binary tree, return the postorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 *  return [3,2,1].
 *
 *  Note: Recursive solution is trivial, could you do it iteratively?
 *
 *
 * Date: 2014.11.10
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

class Solution_Postorder_Traversal {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> postorder;
        if (root == NULL) {
            return postorder;
        }

        stack<TreeNode *> nodeStack;
        stack<int> directionStack;  // 0 = init, 1 = downleft, downright;
        nodeStack.push(root);
        directionStack.push(0);  // downleft;

        TreeNode *ptr = NULL;
        int direction = -1;
        while (!nodeStack.empty()) {
            ptr = nodeStack.top();
            direction = directionStack.top();

            if (direction == 0) {  // init;
                if (ptr->left != NULL) {  // next downleft;
                    direction = 1;
                    directionStack.pop();
                    directionStack.push(direction);
                } else if (ptr->right != NULL) {  // next downright;
                    direction = 2;
                    directionStack.pop();
                    directionStack.push(direction);
                }

                if (ptr->right != NULL) {
                    nodeStack.push(ptr->right);
                    directionStack.push(0);
                }
                if (ptr->left != NULL) {
                    nodeStack.push(ptr->left);
                    directionStack.push(0);
                }

                if (ptr->left == NULL && ptr->right == NULL) {
                    postorder.push_back(ptr->val);
                    nodeStack.pop();
                    directionStack.pop();
                }
            } else if (direction == 1)  {  // downleft;
                postorder.push_back(ptr->val);
                nodeStack.pop();
                directionStack.pop();
            } else if (direction == 2)  {  // downleft;
                postorder.push_back(ptr->val);
                nodeStack.pop();
                directionStack.pop();
            }
        }  // while

        return postorder;
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
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right =  new TreeNode(3);

    TreeNode *left = root->left;
    left->left = new TreeNode(4);
    left->right = new TreeNode(5);
    left->right->right = new TreeNode(6);

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
    Solution_Postorder_Traversal solution;

    TreeNode *root = buildTree();

    vector<int> preorder = solution.postorderTraversal(root);
    print_vector(preorder);
    releaseTree(root);

    preorder.clear();
    root = buildTree2();
    preorder = solution.postorderTraversal(root);
    print_vector(preorder);
    releaseTree(root);

    return 0;
}

