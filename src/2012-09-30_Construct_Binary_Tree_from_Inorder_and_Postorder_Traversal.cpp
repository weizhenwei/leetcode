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
 * File: 2012-09-30_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 * Given inorder and post traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
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

class Solution_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() == 0 && postorder.size() == 0) {
            return NULL;
        }
        if (inorder.size() == 1 && postorder.size() == 1) {
            TreeNode *node = new TreeNode(inorder[0]);
            return node;
        }

        int size = postorder.size();
        int rootval = postorder[size - 1];
        int i = 0;
        for (i = 0; i < inorder.size(); i++) {
            if (inorder[i] == rootval) {
                break;
            }
        }

        if (i == inorder.size() - 1) {  // right subtree is NULL;
            vector<int>::iterator iter = inorder.end();
            iter--;
            inorder.erase(iter);

            vector<int>::iterator piter = postorder.end();
            piter--;
            postorder.erase(piter);

            TreeNode *root = new TreeNode(rootval);
            TreeNode *left = buildTree(inorder, postorder);
            root->left = left;
            root->right = NULL;
            return root;
        } else if (i == 0) {  // left subtree is NULL;
            inorder.erase(inorder.begin());
            vector<int>::iterator piter = postorder.end();
            piter--;
            postorder.erase(piter);

            TreeNode *root = new TreeNode(rootval);
            TreeNode *right = buildTree(inorder, postorder);
            root->left = NULL;
            root->right = right;
            return root;
        } else {  // left and right is not NULL;
            vector<int> inorderLeft =
                vector<int>(inorder.begin(), inorder.begin() + i);
            inorder.erase(inorder.begin(), inorder.begin() + i + 1);

            vector<int> postorderLeft =
                vector<int>(postorder.begin(), postorder.begin() + i);
            postorder.erase(postorder.begin(), postorder.begin() + i);
            vector<int>::iterator piter = postorder.end();
            piter--;
            postorder.erase(piter);

            TreeNode *root = new TreeNode(rootval);
            TreeNode *left = buildTree(inorderLeft, postorderLeft);
            TreeNode *right = buildTree(inorder, postorder);
            root->left = left;
            root->right = right;

            return root;
        }
    }
};

static TreeNode *buildTree1() {
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

static void printTree(TreeNode *root) {  // inorder print tree;
    if (root == NULL) {
        return;
    }

    printTree(root->left);
    printf("%d ", root->val);
    printTree(root->right);
}

static void print_vector(vector<int> v) {
    vector<int>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
        printf("%d ", *iter);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal solution;

    vector<int> inorder;
    inorder.push_back(4);
    inorder.push_back(2);
    inorder.push_back(5);
    inorder.push_back(1);
    inorder.push_back(6);
    inorder.push_back(3);
    inorder.push_back(7);
    vector<int> postorder;
    postorder.push_back(4);
    postorder.push_back(5);
    postorder.push_back(2);
    postorder.push_back(6);
    postorder.push_back(7);
    postorder.push_back(3);
    postorder.push_back(1);

    printf("inorder:");
    print_vector(inorder);
    printf("postorder:");
    print_vector(postorder);
    TreeNode *root = solution.buildTree(inorder, postorder);
    printf("built tree print in inorder:");
    printTree(root);
    printf("\n");
    releaseTree(root);

    inorder.clear();
    inorder.push_back(4);
    inorder.push_back(2);
    inorder.push_back(1);
    inorder.push_back(6);
    inorder.push_back(3);
    inorder.push_back(7);
    postorder.clear();
    postorder.push_back(4);
    postorder.push_back(2);
    postorder.push_back(6);
    postorder.push_back(7);
    postorder.push_back(3);
    postorder.push_back(1);

    printf("inorder:");
    print_vector(inorder);
    printf("postorder:");
    print_vector(postorder);
    root = solution.buildTree(inorder, postorder);
    printf("built tree print in inorder:");
    printTree(root);
    printf("\n");
    releaseTree(root);

    inorder.clear();
    inorder.push_back(4);
    inorder.push_back(2);
    inorder.push_back(5);
    inorder.push_back(1);
    postorder.clear();
    postorder.push_back(1);
    postorder.push_back(2);
    postorder.push_back(4);
    postorder.push_back(5);

    printf("inorder:");
    print_vector(inorder);
    printf("postorder:");
    print_vector(postorder);
    root = solution.buildTree(inorder, postorder);
    printf("built tree print in inorder:");
    printTree(root);
    printf("\n");
    releaseTree(root);

    return 0;
}

