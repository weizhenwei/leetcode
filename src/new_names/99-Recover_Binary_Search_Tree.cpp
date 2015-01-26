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
 * File: 99-Recover_Binary_Search_Tree.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/recover-binary-search-tree/
 * Two elements of a binary search tree (BST) are swapped by mistake.
 *
 * Recover the tree without changing its structure.
 *
 * Note:
 * A solution using O(n) space is pretty straight forward. Could you devise a
 * constant space solution?
 *
 *
 * Date: 2015.01.26
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <algorithm>
#include <limits>

using std::numeric_limits;
using std::swap;


// definition for binary tree;
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

// originates from:
// https://oj.leetcode.com/discuss/7319/an-elegent-time-complexity-and-space-complexity-algorithm
class Solution_Recover_Binary_Search_Tree {
public:
    void recover(TreeNode *root, TreeNode *&pre, TreeNode *&a, TreeNode *&b) {
        if (root) {
            recover(root->left, pre, a, b);

            if (root->val < pre->val) {
                if (!a) {
                    a = pre;
                }
                b = root;
            }
            pre = root;

            recover(root->right, pre, a, b);
        }
    }

    void recoverTree(TreeNode *root) {
        if (!root)
            return;

        TreeNode p = TreeNode(numeric_limits<int>::min());
        TreeNode *a, *b, *pre;
        a = b = NULL;
        pre = &p;
        recover(root, pre, a, b);

        if (a && b) {
            swap(a->val, b->val);
        }

        return;
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


int main(int argc, char *argv[]) {
    Solution_Recover_Binary_Search_Tree solution;
    
    return 0;
}

