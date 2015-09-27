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
 * File: 203-Remove_Linked_List_Elements.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/remove-linked-list-elements/
 * Remove all elements from a linked list of integers that have value val.

 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 *
 *
 * Date: 2015.09.27
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <vector>

using std::vector;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution_Reverse_Linked_List {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) {
            return NULL;
        }

        ListNode *newHead = NULL;
        ListNode *p = head;
        ListNode *pNewHead = newHead;
        while (p != NULL) {
            if (p->val != val) {
                if (pNewHead == NULL) {
                    newHead = pNewHead = p;
                } else {
                    pNewHead->next = p;
                    pNewHead = pNewHead->next;
                }
                p = p->next;
            } else {
                if (pNewHead != NULL) {
                    pNewHead->next = p->next;
                }
                ListNode *tmp = p;
                p = p->next;
                delete tmp;
            }
        }  // while

        return newHead;
    }
};

ListNode *createList(vector<int> &elements) {
    vector<int>::iterator iter = elements.begin();;
    ListNode *list = NULL;

    int elem;
    ListNode *current, *next;
    for (iter = elements.begin(); iter < elements.end(); iter++) {
        int elem = *iter;
        next = new ListNode(elem);
        if (list == NULL) {
            list = next;
            current = next;
        } else {
            current->next = next;
            current = current->next;
        }
    }

    return list;
}

void dump_ListNode(ListNode *head) {
    ListNode *p = head;

    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }

    printf("\n");
}

void release_ListNode(ListNode *head) {
    ListNode *p = head;
    ListNode *tmp = NULL;

    while (p != NULL) {
        tmp = p;
        p = p->next;
        delete tmp;
    }
}

void testcase() {
    Solution_Reverse_Linked_List solution;
    ListNode *head;
    vector<int> elements;
    int val = 0;

    elements.clear();
    head = createList(elements);
    dump_ListNode(head);
    head = solution.removeElements(head, val);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    val = 0;
    elements.push_back(1);
    head = createList(elements);
    dump_ListNode(head);
    head = solution.removeElements(head, val);
    dump_ListNode(head);
    val = 1;
    head = solution.removeElements(head, val);
    release_ListNode(head);
    printf("\n");

    val = 1;
    elements.clear();
    elements.push_back(2);
    elements.push_back(1);
    head = createList(elements);
    dump_ListNode(head);
    head = solution.removeElements(head, val);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    val = 1;
    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    head = createList(elements);
    dump_ListNode(head);
    head = solution.removeElements(head, val);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    val = 5;
    elements.clear();
    elements.push_back(5);
    elements.push_back(1);
    elements.push_back(3);
    elements.push_back(2);
    elements.push_back(4);
    head = createList(elements);
    dump_ListNode(head);
    head = solution.removeElements(head, val);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    val = 5;
    elements.clear();
    elements.push_back(5);
    elements.push_back(5);
    elements.push_back(5);
    elements.push_back(5);
    elements.push_back(5);
    head = createList(elements);
    dump_ListNode(head);
    head = solution.removeElements(head, val);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    val = 5;
    elements.clear();
    elements.push_back(1);
    elements.push_back(5);
    elements.push_back(5);
    head = createList(elements);
    dump_ListNode(head);
    head = solution.removeElements(head, val);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    val = 5;
    elements.clear();
    elements.push_back(5);
    elements.push_back(5);
    elements.push_back(1);
    elements.push_back(1);
    elements.push_back(1);
    head = createList(elements);
    dump_ListNode(head);
    head = solution.removeElements(head, val);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    val = 5;
    elements.clear();
    elements.push_back(5);
    elements.push_back(1);
    elements.push_back(5);
    elements.push_back(2);
    elements.push_back(5);
    elements.push_back(3);
    elements.push_back(4);
    elements.push_back(6);
    elements.push_back(5);
    elements.push_back(5);
    head = createList(elements);
    dump_ListNode(head);
    head = solution.removeElements(head, val);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");
}

int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

