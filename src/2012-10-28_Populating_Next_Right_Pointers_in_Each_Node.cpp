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
 * File: 2012-10-28_Populating_Next_Right_Pointers_in_Each_Node.cpp
 *
 *
 * Brief:https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/
 * Given a binary tree
 *
 *     struct TreeLinkNode {
 *         TreeLinkNode *left;
 *         TreeLinkNode *right;
 *         TreeLinkNode *next;
 *     }
 *     Populate each next pointer to point to its next right node. If there is
 *     no next right node, the next pointer should be set to NULL. Initially,
 *     all next pointers are set to NULL.
 *     Note:
 *     You may only use constant extra space.
 *     You may assume that it is a perfect binary tree (ie,
 *     all leaves are at the same level, and every parent has two children).
 *     For example, Given the following perfect binary tree,
 *             1
 *            / \
 *           2   3
 *          / \ / \
 *         4  5 6  7
 *     After calling your function, the tree should look like:
 *              1 -> NULL
 *             /  \
 *            2 -> 3 -> NULL
 *           / \  / \
 *          4->5->6->7 -> NULL
 *
 * Date: 2014.11.12
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>

// definition for binary tree with next pointer;
typedef struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
} TreeLinkNode;

class Solution_Populate_Next_Pointers {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            return;
        }

        TreeLinkNode *leftMostNode = root;
        while (leftMostNode->left != NULL) {
            TreeLinkNode *tmpPtr = leftMostNode;
            leftMostNode = leftMostNode->left;

            while (tmpPtr != NULL) {
                tmpPtr->left->next = tmpPtr->right;
                if (tmpPtr->next != NULL) {
                    tmpPtr->right->next = tmpPtr->next->left;
                }

                tmpPtr = tmpPtr->next;
            }  // while
        }  // while 
    }
};

static TreeLinkNode *buildTree() {
    TreeLinkNode*root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right =  new TreeLinkNode(3);

    TreeLinkNode*left = root->left;
    left->left = new TreeLinkNode(4);
    left->right = new TreeLinkNode(5);

    TreeLinkNode *right = root->right;
    right->left = new TreeLinkNode(6);
    right->right = new TreeLinkNode(7);

    return root;
}

static void preorderPrintTree(TreeLinkNode *root) {
    if (root == NULL)
        return;

    if (root->next != NULL) {
        printf("node->val = %d, node->next->val = %d\n",
                root->val, root->next->val);
    } else {
        printf("node->val = %d, node->next = NULL\n", root->val);
    }

    preorderPrintTree(root->left);
    preorderPrintTree(root->right);
}

static void releaseTree(TreeLinkNode *root) {
    if (root != NULL) {
        releaseTree(root->left);
        releaseTree(root->right);
        delete root;
    }
}


int main(int argc, char *argv[]) {
    Solution_Populate_Next_Pointers solution;

    TreeLinkNode *root = buildTree();
    preorderPrintTree(root);
    solution.connect(root);
    preorderPrintTree(root);
    releaseTree(root);

    return 0;
}

