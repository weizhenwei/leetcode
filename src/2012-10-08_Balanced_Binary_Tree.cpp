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
 * File: 2012-10-08_Balanced_Binary_Tree.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/balanced-binary-tree/
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 *
 *
 * Date: 2014.11.10
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>


// definition for binary tree;
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

class Solution_Balanced_Binary_Tree {
public:
    int depth(TreeNode *tree) {
        if(tree == NULL) {
            return 0;
        } else if (tree->left == NULL && tree->right == NULL) {
            return 1;
        } else {
            int left = depth(tree->left);
            int right = depth(tree->right);
            return left < right ? right + 1 : left + 1;
        }
    }
    bool isBalanced(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        
        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);
        if (l && r) {
            int left = depth(root->left);
            int right = depth(root->right);
            if (abs(left-right) > 1) {
                return false;
            } else {
                return true;
            }
        } else {
            return false;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution_Balanced_Binary_Tree solution;

    TreeNode *p = new TreeNode(1);;
    TreeNode *q = new TreeNode(1);;
    bool balanced = solution.isBalanced(p);
    printf("balanced = %d\n", balanced);

    delete p;
    p = NULL;
    balanced = solution.isBalanced(q);
    printf("balanced = %d\n", balanced);

    delete q;

    return 0;
}

