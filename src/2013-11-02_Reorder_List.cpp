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
 * File: 2013-12-02_Reorder_List.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/reorder-list/
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You must do this in-place without altering the nodes' values.
 *
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 *
 *
 * Date: 2014.11.05
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <vector>

using std::vector;

// Definition for singly-linked list.
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}ListNode;

class Solution_Reorder_list {
public:
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return;

        // first get list's length;
        ListNode *tail = head;
        int len = 1;
        while (tail->next != NULL) {
            len++;
            tail = tail->next;
        }

        int half = 0;
        if (len % 2 == 1) {
            half = len / 2 + 1;
        } else {
            half = len / 2;
        }

        ListNode *prev = head;
        ListNode *current = head;
        while (half > 0) {
            prev = current;
            current = current->next;
            half--;
        }

        // now prev is the fast half's tail, current is second half's begin;
        // tail is the head after second half reversed;
        prev->next = NULL;
        prev = current;
        while (prev != tail) {
            current = prev->next;
            prev->next = tail->next;
            tail->next = prev;
            prev = current;
        }


        // now merge the first half and last half;
        prev = head;
        current = tail;
        ListNode *tmp;
        while (current != NULL) {
            tmp = current->next;
            current->next = prev->next;
            prev->next = current;
            prev = prev->next->next;
            current = tmp;
        }

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
    Solution_Reorder_list solution;
    ListNode *head;
    vector<int> elements;

    elements.push_back(1);
    head = createList(elements);
    dump_ListNode(head);
    solution.reorderList(head);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    head = createList(elements);
    dump_ListNode(head);
    solution.reorderList(head);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    elements.push_back(3);
    elements.push_back(4);
    elements.push_back(5);
    head = createList(elements);
    dump_ListNode(head);
    solution.reorderList(head);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    elements.push_back(3);
    elements.push_back(4);
    elements.push_back(5);
    elements.push_back(6);
    head = createList(elements);
    dump_ListNode(head);
    solution.reorderList(head);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    elements.push_back(3);
    elements.push_back(4);
    elements.push_back(5);
    elements.push_back(6);
    elements.push_back(7);
    elements.push_back(8);
    elements.push_back(9);
    elements.push_back(10);
    elements.push_back(11);
    elements.push_back(12);
    head = createList(elements);
    dump_ListNode(head);
    solution.reorderList(head);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");
}


int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

