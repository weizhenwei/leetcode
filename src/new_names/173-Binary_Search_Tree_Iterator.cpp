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
 * File: 173-Binary_Search_Tree_Iterator.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/binary-search-tree-iterator/
 * Implement an iterator over a binary search tree (BST). Your iterator will be
 * initialized with the root node of a BST.
 *
 * Calling next() will return the next smallest number in the BST.
 *
 * Note: next() and hasNext() should run in average O(1) time and uses O(h)
 * memory, where h is the height of the tree.
 *
 *
 * Date: 2015.01.08
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <assert.h>
#include <stdio.h>
#include <stack>

using std::stack;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    stack<TreeNode *> smallestNodes;

public:
    BSTIterator() { }
    BSTIterator(TreeNode *root) {
        if (root) {
            TreeNode *p = root;
            while (p) {
                smallestNodes.push(p);
                p = p->left;
            }  // while
        }  // if
    }

    /** @return whether we have a next smallest number; */
    bool hasNext() {
        return !smallestNodes.empty();
    }

    /** @return the next smallest number */
    int next() {
        assert(hasNext());
        TreeNode *node = smallestNodes.top();
        smallestNodes.pop();
        int val = node->val;

        node = node->right;
        while (node) {
            smallestNodes.push(node);
            node = node->left;
        }  // while

        return val;
    }
};

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(23);
    root->left = new TreeNode(2);
    root->right = new TreeNode(32);

    BSTIterator iterator = BSTIterator(root);

    int next = iterator.next();
    printf("next = %d\n", next);
    next = iterator.next();
    printf("next = %d\n", next);
    next = iterator.next();
    printf("next = %d\n", next);

    delete root->left;
    delete root->right;
    delete root;
    return 0;
}

