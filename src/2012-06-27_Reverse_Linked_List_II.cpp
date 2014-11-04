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
 * File: 2012-06-27_Reverse_Linked_List_II.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/reverse-linked-list-ii/
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *
 * return 1->4->3->2->5->NULL.
 *
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 *
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

class Solution_Reverse_Linked_List {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head->next == NULL || m == n)
            return head;

        int gogogo = 1;
        ListNode *prev = head;
        ListNode *start = head;
        ListNode *end = head;

        while (gogogo < m) {
            prev = start;
            start = start->next;
            gogogo++;
        }

        end = start;
        while (gogogo < n) {
            end = end->next;
            gogogo++;
        }

        if (start == head) {
            head = end;
            ListNode *next;
            while (start != end) {
                next = start->next;
                start->next = end->next;
                end->next = start;
                start = next;
            }
        } else {
            prev->next = end;
            ListNode *next;
            while (start != end) {
                next = start->next;
                start->next = end->next;
                end->next = start;
                start = next;
            }
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
    Solution_Reverse_Linked_List solution;
    ListNode *head;
    vector<int> elements;
    int m, n;

    elements.push_back(1);
    head = createList(elements);
    dump_ListNode(head);
    m = 1;
    n = 1;
    head = solution.reverseBetween(head, m, n);
    printf("m = %d, n = %d\n", m, n);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    head = createList(elements);
    dump_ListNode(head);
    m = 1;
    n = 2;
    head = solution.reverseBetween(head, m, n);
    printf("m = %d, n = %d\n", m, n);
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
    m = 2;
    n = 4;
    head = solution.reverseBetween(head, m, n);
    printf("m = %d, n = %d\n", m, n);
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
    m = 1;
    n = 4;
    head = solution.reverseBetween(head, m, n);
    printf("m = %d, n = %d\n", m, n);
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
    m = 2;
    n = 5;
    head = solution.reverseBetween(head, m, n);
    printf("m = %d, n = %d\n", m, n);
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
    m = 1;
    n = 5;
    head = solution.reverseBetween(head, m, n);
    printf("m = %d, n = %d\n", m, n);
    dump_ListNode(head);
    release_ListNode(head);

}


int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

