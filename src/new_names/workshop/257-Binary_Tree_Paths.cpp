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
 * File: 257-Binary_Tree_Paths.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/binary-tree-paths/
 * Given a binary tree, return all root-to-leaf paths.
 *
 * For example, given the following binary tree:
 *
 *    1
 *  /   \
 * 2     3
 *  \
 *   5
 * All root-to-leaf paths are:
 *     ["1->2->5", "1->3"]
 *
 * Date: 2015.09.17
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>

using std::string;
using std::ostringstream;
using std::vector;

// definition for binary tree;
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution_Bnary_Tree_Paths {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> results;
        if (root == NULL) {
            return results;
        }
        ostringstream ostr;
        ostr << root->val;
        string strRoot = ostr.str();
        if (root->left == NULL && root->right == NULL) {
            results.push_back(strRoot);
            return results;
        }

        vector<string> leftTree, rightTree;
        if (root->left) {
            leftTree = binaryTreePaths(root->left);
        }
        if (root->right) {
            rightTree = binaryTreePaths(root->right);
        }
        for (int i= 0; i < leftTree.size(); i++) {
            results.push_back(strRoot + "->" + leftTree[i]);
        }
        for (int i= 0; i < rightTree.size(); i++) {
            results.push_back(strRoot + "->" + rightTree[i]);
        }

        return results;
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

void testcase() {
    Solution_Bnary_Tree_Paths solution;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    vector<string> paths = solution.binaryTreePaths(root);
    for (int i = 0; i < paths.size(); i++) {
        printf("%s\n", paths[i].c_str());
    }
}

int main(int argc, char *argv[]) {
    testcase();
    
    return 0;
}

