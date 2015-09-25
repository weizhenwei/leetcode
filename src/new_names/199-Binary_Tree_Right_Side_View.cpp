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
 * File: 199-Binary_Tree_Right_Side_View.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/binary-tree-right-side-view/
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.

 * For example:
 * Given the following binary tree,
 *       1            <---
 *     /   \
 *    2     3         <---
 *     \     \
 *      5     4       <---
 * You should return [1, 3, 4].
 *
 * Date: 2015.09.25
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <vector>

using std::vector;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// definition for binary tree;
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

class Solution_Binary_Tree_Side_View {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        vector<TreeNode*> theQueue;
        theQueue.push_back(root);
        while (theQueue.size() > 0) {
            int size = theQueue.size();
            result.push_back(theQueue[size-1]->val);
            for (int i = 0; i < size; i++) {
                if (theQueue[i]->left) {
                    theQueue.push_back(theQueue[i]->left);
                }
                if (theQueue[i]->right) {
                    theQueue.push_back(theQueue[i]->right);
                }
            }
            theQueue.erase(theQueue.begin(), theQueue.begin() + size);
        }  // while

        return result;
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

static void testcase()
{
    Solution_Binary_Tree_Side_View solution;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    vector<int> view = solution.rightSideView(root);
    for (int i = 0; i < view.size(); i++) {
        printf("%d ", view[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    testcase();
    
    return 0;
}

