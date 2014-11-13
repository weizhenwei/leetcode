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
 * File: 2012-10-13_Path_Sum.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/path-sum/
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *              5
 *             / \
 *            4   8
 *           /   / \
 *          11  13  4
 *         /  \      \
 *        7    2      1
 * return
 *     [
 *       [5, 4, 11, 2],
 *       [5, 8, 4, 5]
 *     ]
 *
 *
 * Date: 2014.11.13
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

class Solution_Path_Sum_II {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        if (root == NULL) {
            return result;
        }
        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum) {
                vector<int> elem;
                elem.push_back(root->val);
                result.push_back(elem);
                return result;
             } else {
                 return result;
             }
        }
        
        int remain = sum - root->val;
        vector<vector<int> > left = pathSum(root->left, remain);
        vector<vector<int> > right = pathSum(root->right, remain);
        for (int i = 0; i < left.size(); i++) {
            left[i].insert(left[i].begin(), root->val);
            result.push_back(left[i]);
        }
        for (int i = 0; i < right.size(); i++) {
            right[i].insert(right[i].begin(), root->val);
            result.push_back(right[i]);
        }

        return result;
    }
};

static TreeNode *buildTree() {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right =  new TreeNode(8);

    TreeNode *left = root->left;
    left->left = new TreeNode(11);
    left->left->left = new TreeNode(7);
    left->left->right = new TreeNode(2);

    TreeNode *right = root->right;
    right->left = new TreeNode(13);
    right->right = new TreeNode(4);
    right->right->left = new TreeNode(5);
    right->right->right = new TreeNode(1);

    return root;
}

static void releaseTree(TreeNode *root) {
    if (root != NULL) {
        releaseTree(root->left);
        releaseTree(root->right);
        delete root;
    }
}

static void print_vector(vector<vector<int> > &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }

}

int main(int argc, char *argv[]) {
    Solution_Path_Sum_II solution;

    TreeNode *root = buildTree();

    int sum = 22;
    vector<vector<int> > result = solution.pathSum(root, sum);
    print_vector(result);

    releaseTree(root);

    return 0;
}

