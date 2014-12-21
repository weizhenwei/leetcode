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
 * File: 2012-12-07_Binary_Tree_Maximum_Path_Sum.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/
 * Given a binary tree, find the maximum path sum.
 *
 * The path may start and end at any node in the tree.
 *
 * For example:
 * Given the below binary tree,
 *
 *        1
 *       / \
 *      2   3
 * Return 6.
 *
 *
 * Date: 2014.12.21
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <limits.h>
#include <algorithm>

using std::max;

// definition for binary tree;
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

// originate from:
// https://oj.leetcode.com/discuss/17214/simple-o-n-algorithm-with-one-traversal-through-the-tree
class Solution_Same_Tree {
    int maxToRoot(TreeNode *root, int &re) {
        if (!root) {
            return 0;
        }
        int l = maxToRoot(root->left, re);
        int r = maxToRoot(root->right, re);
        if (l < 0)
            l = 0;
        if (r < 0)
            r = 0;
        if (l + r + root->val > re)
            re = l + r + root->val;

        return root->val +=max(l, r);
    }
public:
    int maxPathSum(TreeNode *root) {
        int max = INT_MIN;
        maxToRoot(root, max);

        return max;
    }
};

int main(int argc, char *argv[]) {
    Solution_Same_Tree solution;

    TreeNode *p = new TreeNode(1);;
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    int max = solution.maxPathSum(p);
    printf("max = %d\n", max);

    delete p->left;
    delete p->right;
    delete p;

    return 0;
}

