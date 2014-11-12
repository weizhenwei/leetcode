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
 * File: 2012-10-02_Convert_Sorted_Array_to_Binary_Search_Tree.cpp
 *
 *
 * Brief: * https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 *
 *
 * Date: 2014.11.11
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <vector>

using std::vector;

// definition for binary tree;
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution_Convert_Sorted_Array_to_Binary_Search_Tree {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0) {
            return NULL;
        } else if (num.size() == 1) {
            return new TreeNode(num[0]);
        } else if (num.size() == 2) {
            TreeNode *root = new TreeNode(num[0]);
            TreeNode *right = new TreeNode(num[1]);
            root->right = right;
            return root;
        } else if (num.size() == 3) {
            TreeNode *root = new TreeNode(num[1]);
            TreeNode *left = new TreeNode(num[0]);
            TreeNode *right = new TreeNode(num[2]);
            root->left = left;
            root->right = right;
            return root;
        } else {
            int half = num.size() / 2;
            vector<int> lleft;
            for (int i = 0; i < half; i++) {
                lleft.push_back(num[i]);
            }
            vector<int> rright;
            for (int i = half + 1; i < num.size(); i++) {
                rright.push_back(num[i]);
            }

            TreeNode *root = new TreeNode(num[half]);
            TreeNode *left = sortedArrayToBST(lleft);
            TreeNode *right = sortedArrayToBST(rright);
            root->left = left;
            root->right = right;
            return root;
        }
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

static void printTreePreorder(TreeNode *root) {
    if (root == NULL)
        return;
    printf("%d ", root->val);
    printTreePreorder(root->left);
    printTreePreorder(root->right);
}

int main(int argc, char *argv[]) {
    Solution_Convert_Sorted_Array_to_Binary_Search_Tree solution;
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
    num.push_back(5);
    num.push_back(6);
    num.push_back(7);

    TreeNode *root = solution.sortedArrayToBST(num);
    printTreePreorder(root);

    releaseTree(root);

    return 0;
}

