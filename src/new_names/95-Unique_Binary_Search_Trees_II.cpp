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
 * File: 95-Unique_Binary_Search_Trees_II.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/unique-binary-search-trees-ii/
 * Given n, generate all structurally unique BST's (binary search trees) that
 * store values 1...n.
 *
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
 *
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 *
 *
 * Date: 2015.01.26
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
}TreeNode;

// originates from: https://oj.leetcode.com/discuss/21932/my-c-solution
class Solution_Unique_Binary_Search_Tree {
private:
    vector<TreeNode *> getTrees(int n, int offset) {
        vector<TreeNode *> ans;
        if (n == 0) {
            ans.push_back(NULL);
            return ans;
        }

        int i, j, k;
        for (i = 1; i <= n; i++) {
            // left nodes is smaller than i;
            vector<TreeNode *> left = getTrees(i - 1, offset);
            // right nodes is bigger than i;
            vector<TreeNode *> right = getTrees(n - i, i + offset);
            for (j = 0; j < left.size(); j++) {
                for (k = 0; k < right.size(); k++) {
                    TreeNode *root = new TreeNode(i + offset);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }  // k
            }  // j
        }  // i

        return ans;
    }
public:
    vector<TreeNode *>generateTrees(int n) {
        return getTrees(n, 0);
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
    Solution_Unique_Binary_Search_Tree solution;
    int n = 3;
    vector<TreeNode *> trees = solution.generateTrees(n);
    for (int i = 0; i < trees.size(); i++) {
        print_tree(trees[i]);
    }
    
    return 0;
}

