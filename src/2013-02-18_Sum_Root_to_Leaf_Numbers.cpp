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
 * File: 2013-02-18_Sum_Root_to_Leaf_Numbers.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/sum-root-to-leaf-numbers/
 * Given a binary tree containing digits from 0-9 only,
 * each root-to-leaf path could represent a number.
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 * Find the total sum of all root-to-leaf numbers.
 * For example,
 *    1
 *   / \
 *  2   3
 *  The root-to-leaf path 1->2 represents the number 12.
 *  The root-to-leaf path 1->3 represents the number 13.
 *  Return the sum = 12 + 13 = 25.
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

class Solution_Root_to_Leaf_Numbers {
public:
    vector<vector<int> > allPath(TreeNode *root) {
        vector<vector<int> > result;
        if (root == NULL) {
            return result;
        }
        if (root->left == NULL && root->right == NULL) {
            vector<int> elem;
            elem.push_back(root->val);
            result.push_back(elem);
            return result;
        }
        
        vector<vector<int> > left = allPath(root->left);
        vector<vector<int> > right = allPath(root->right);
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

    int sumNumbers(TreeNode *root) {
        vector<vector<int> > allpaths = allPath(root);

        int sum = 0;
        for (int i = 0; i < allpaths.size(); i++) {
            int elem = 0;
            for (int j = 0; j < allpaths[i].size(); j++) {
                elem = elem * 10 + allpaths[i][j];
            }

            sum += elem;
        }

        return sum;
    }
};

static TreeNode *buildTree() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right =  new TreeNode(3);

    TreeNode *left = root->left;
    left->left = new TreeNode(4);
    left->left->left = new TreeNode(5);
    left->left->right = new TreeNode(6);

    TreeNode *right = root->right;
    right->left = new TreeNode(7);
    right->right = new TreeNode(8);
    right->right->left = new TreeNode(9);
    right->right->right = new TreeNode(0);

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
    Solution_Root_to_Leaf_Numbers solution;

    TreeNode *root = buildTree();

    vector<vector<int> > result = solution.allPath(root);
    print_vector(result);
    int sum = solution.sumNumbers(root);
    printf("sum = %d\n", sum);

    releaseTree(root);

    return 0;
}

