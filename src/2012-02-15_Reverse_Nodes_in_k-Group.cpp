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
 * File: 2012-02-15_Reverse_Nodes_in_k-Group.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/reverse-nodes-in-k-group/
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 *
 * If the number of nodes is not a multiple of k then left-out nodes in the end
 * should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 *
 * Only constant memory is allowed.
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 *
 *
 * Date: 2014.10.27
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

class Solution_Reverse_Nodes_in_KGroup {
public:
    ListNode *reverseKGoup(ListNode *head, int k) {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;

        ListNode *hhead = NULL;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        ListNode *begin = NULL;
        ListNode *end = NULL;
        ListNode *tmp = NULL;
        int counter = 0;

        prev = begin = end = next = tmp = head;
        counter = 0;
        while (counter < k && end != NULL) {
            end = next;
            if (next != NULL) {
                next = next->next;
            } else {
                break;
            }
            counter++;
        }
        if (counter < k)
            return head;

        hhead = end;
        prev = begin;
        while (begin != end) {
            tmp = begin->next;
            begin->next = end->next;
            end->next = begin;
            begin = tmp;
        }
        
        while (1) {
            begin = end = next;
            counter = 0;
            while (counter < k && end != NULL) {
                counter++;
                end = next;
                if (next != NULL) {
                    next = next->next;
                } else {
                    return hhead;
                }
            }
            if (counter < k)
                return hhead;

            prev->next = end;
            prev = begin;
            while (begin != end) {
                tmp = begin->next;
                begin->next = end->next;
                end->next = begin;
                begin = tmp;
            }
        }

        return hhead;
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
    Solution_Reverse_Nodes_in_KGroup solution;
    ListNode *head;
    vector<int> elements;
    int k = 0;

    elements.push_back(1);
    head = createList(elements);
    k = 1;
    printf("k = %d, before reverse:\n", k);
    dump_ListNode(head);
    head = solution.reverseKGoup(head, k);
    printf("k = %d, after reverse:\n", k);
    dump_ListNode(head);
    release_ListNode(head);

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    head = createList(elements);
    k = 2;
    printf("k = %d, before reverse:\n", k);
    dump_ListNode(head);
    head = solution.reverseKGoup(head, k);
    printf("k = %d, after reverse:\n", k);
    dump_ListNode(head);
    release_ListNode(head);

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    head = createList(elements);
    k = 3;
    printf("k = %d, before reverse:\n", k);
    dump_ListNode(head);
    head = solution.reverseKGoup(head, k);
    printf("k = %d, after reverse:\n", k);
    dump_ListNode(head);
    release_ListNode(head);

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    elements.push_back(3);
    elements.push_back(4);
    elements.push_back(5);
    head = createList(elements);
    k = 3;
    printf("k = %d, before reverse:\n", k);
    dump_ListNode(head);
    head = solution.reverseKGoup(head, k);
    printf("k = %d, after reverse:\n", k);
    dump_ListNode(head);
    release_ListNode(head);

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    elements.push_back(3);
    elements.push_back(4);
    elements.push_back(5);
    elements.push_back(6);
    head = createList(elements);
    k = 3;
    printf("k = %d, before reverse:\n", k);
    dump_ListNode(head);
    head = solution.reverseKGoup(head, k);
    printf("k = %d, after reverse:\n", k);
    dump_ListNode(head);
    release_ListNode(head);

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
    head = createList(elements);
    k = 3;
    printf("k = %d, before reverse:\n", k);
    dump_ListNode(head);
    head = solution.reverseKGoup(head, k);
    printf("k = %d, after reverse:\n", k);
    dump_ListNode(head);
    release_ListNode(head);
}

int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

