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
 * File: 2012-09-28_Binary_Tree_Zigzag_Level_Order_Traversal.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its level order traversal as:
 *     [
 *      [3],
 *      [20, 9],
 *      [15,7]
 *     ]
 *
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

class Solution_Level_Order_Traversal {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > levelorder;
        if (root == NULL) {
            return levelorder;
        }

        vector<TreeNode *> nodeQueue;
        nodeQueue.push_back(root);

        while (!nodeQueue.empty()) {
            vector<int> elem;
            elem.clear();
            int size = nodeQueue.size();
            int i = 0; 
            while (i < size) {
                elem.push_back(nodeQueue[i]->val);
                if (nodeQueue[i]->left != NULL) {
                    nodeQueue.push_back(nodeQueue[i]->left);
                }
                if (nodeQueue[i]->right != NULL) {
                    nodeQueue.push_back(nodeQueue[i]->right);
                }
                i++;
            }

            levelorder.push_back(elem);

            nodeQueue.erase(nodeQueue.begin(), nodeQueue.begin() + size);
        }  // while

        int i = 0;
        for (i = 1; i < levelorder.size(); i+=2) {
            int j = 0;
            int k = levelorder[i].size() - 1;
            while (j < k) {
                int tmp = levelorder[i][k];
                levelorder[i][k] = levelorder[i][j];
                levelorder[i][j] = tmp;

                j++;
                k--;
            }  // for
        }  // for

        return levelorder;
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

static void print_vector(vector<vector<int> > v) {
    vector<vector<int> >::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
        vector<int>::iterator iiter;
        for (iiter = (*iter).begin(); iiter != (*iter).end(); iiter++) {
            printf("%d ", *iiter);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Level_Order_Traversal solution;

    TreeNode *root = buildTree();

    vector<vector<int> > levelorder = solution.levelOrder(root);
    print_vector(levelorder);
    releaseTree(root);

    levelorder.clear();
    root = buildTree2();
    levelorder = solution.levelOrder(root);
    print_vector(levelorder);
    releaseTree(root);

    return 0;
}

