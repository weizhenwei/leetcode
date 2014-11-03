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
 * File: 2012-04-22_Remove_Duplicates_from_Sorted_list.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 *
 * Date: 2014.11.03
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

class Solution_Remove_Duplicates_from_Sorted_list {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *current = head;
        ListNode *next = head;
        while (head->next != NULL && head->val == head->next->val) {
            current = head;
            head = head->next;
            delete current;
        }
        if (head->next == NULL) {
            return head;
        }

        current = head->next;
        next = current->next;
        while (current->next != NULL) {
            next = current->next;
            while (next != NULL && current->val == next->val) {
                current->next = next->next;
                delete next;
                next = current->next;
            }
            current = current->next;
            if (current == NULL)
                break;
        }

        return head;
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
    Solution_Remove_Duplicates_from_Sorted_list solution;
    ListNode *head;
    vector<int> elements;

    elements.push_back(1);
    head = createList(elements);
    dump_ListNode(head);
    head = solution.deleteDuplicates(head);
    dump_ListNode(head);
    release_ListNode(head);

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    head = createList(elements);
    dump_ListNode(head);
    head = solution.deleteDuplicates(head);
    dump_ListNode(head);
    release_ListNode(head);

    elements.clear();
    elements.push_back(1);
    elements.push_back(1);
    elements.push_back(1);
    elements.push_back(2);
    elements.push_back(3);
    elements.push_back(3);
    elements.push_back(3);
    elements.push_back(4);
    elements.push_back(5);
    elements.push_back(5);
    elements.push_back(5);
    elements.push_back(5);
    head = createList(elements);
    dump_ListNode(head);
    head = solution.deleteDuplicates(head);
    dump_ListNode(head);
    release_ListNode(head);

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    elements.push_back(3);
    elements.push_back(4);
    elements.push_back(5);
    head = createList(elements);
    dump_ListNode(head);
    head = solution.deleteDuplicates(head);
    dump_ListNode(head);
    release_ListNode(head);

    elements.clear();
    elements.push_back(1);
    elements.push_back(1);
    elements.push_back(1);
    elements.push_back(1);
    elements.push_back(1);
    elements.push_back(1);
    elements.push_back(1);
    elements.push_back(2);
    elements.push_back(3);
    elements.push_back(4);
    elements.push_back(5);
    head = createList(elements);
    dump_ListNode(head);
    head = solution.deleteDuplicates(head);
    dump_ListNode(head);
    release_ListNode(head);

    elements.clear();
    elements.push_back(1);
    elements.push_back(1);
    elements.push_back(1);
    elements.push_back(1);
    elements.push_back(1);
    elements.push_back(1);
    elements.push_back(1);
    head = createList(elements);
    dump_ListNode(head);
    head = solution.deleteDuplicates(head);
    dump_ListNode(head);
    release_ListNode(head);
}


int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

