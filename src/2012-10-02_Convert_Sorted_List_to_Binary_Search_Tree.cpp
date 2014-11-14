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
 * File: 2012-10-02_Convert_Sorted_List_to_Binary_Search_Tree.cpp
 *
 *
 * Brief: * https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 * Given singly linked list where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 *
 *
 * Date: 2014.11.14
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <vector>

using std::vector;

// definition for singly-linked list;
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

// definition for binary tree;
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution_Convert_Sorted_Array_to_Binary_Search_Tree {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) {
            return NULL;
        } else if (head->next == NULL) {
            return new TreeNode(head->val);
        } else if (head->next->next == NULL) {
            TreeNode *root = new TreeNode(head->val);
            TreeNode *right = new TreeNode(head->next->val);
            root->right = right;
            return root;
        } else if (head->next->next->next == NULL) {
            TreeNode *root = new TreeNode(head->next->val);
            TreeNode *left = new TreeNode(head->val);
            TreeNode *right = new TreeNode(head->next->next->val);
            root->left = left;
            root->right = right;
            return root;
        } else {
            ListNode *tmp = head;
            int size = 0;
            while (tmp != NULL) {
                size++;
                tmp = tmp->next;
            }

            int half = size / 2;

            ListNode *lleft = head;
            ListNode *lright = head;
            int i = 0;
            ListNode *prev = NULL;
            while (i < half) {
                prev = lright;
                lright = lright->next;
                i++;
            }

            // now prev points to left's right most, right points to root;
            prev->next = NULL;
            TreeNode *root = new TreeNode(lright->val);
            lright = lright->next;

            TreeNode *left = sortedListToBST(lleft);
            TreeNode *right = sortedListToBST(lright);
            root->left = left;
            root->right = right;
            return root;
        }
    }
};

static ListNode *buildList() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    return head;
}

static ListNode *buildList2() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    return head;
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

static void printList(ListNode *head) {
    ListNode *tmp = head;
    while (tmp != NULL) {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Convert_Sorted_Array_to_Binary_Search_Tree solution;

    ListNode *head = buildList();
    printf("list:");
    printList(head);
    TreeNode *root = solution.sortedListToBST(head);
    printf("binary search tree:");
    printTreePreorder(root);
    printf("\n");
    releaseTree(root);

    head = buildList2();
    printf("list:");
    printList(head);
    root = solution.sortedListToBST(head);
    printf("binary search tree:");
    printTreePreorder(root);
    printf("\n");
    releaseTree(root);

    return 0;
}

