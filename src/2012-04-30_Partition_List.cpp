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
 * File: 2012-04-30_Partition_List.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/partition-list/
 * Given a linked list and a value x, partition it such that all nodes less than
 * x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 *
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
 *
 *
 * Date: 2014.11.06
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

class Solution_Partition_List {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *smaller = NULL;
        ListNode *smaller_next = NULL;
        ListNode *bigger = NULL;
        ListNode *bigger_next = NULL;
        ListNode *tmp = NULL;
        ListNode *tmp_next = NULL;

        tmp = head;
        while (tmp != NULL) {
            if (tmp->val >= x) {
                if (bigger == NULL) {
                    tmp_next = tmp->next;
                    tmp->next = NULL;
                    bigger = tmp;
                    bigger_next = bigger;
                    tmp = tmp_next;
                } else {
                    tmp_next = tmp->next;
                    tmp->next = bigger_next->next;
                    bigger_next->next = tmp;
                    bigger_next = bigger_next->next;
                    tmp = tmp_next;
                }
            } else {
                if (smaller == NULL) {
                    tmp_next = tmp->next;
                    tmp->next = NULL;
                    smaller = tmp;
                    smaller_next = smaller;
                    tmp = tmp_next;
                } else {
                    tmp_next = tmp->next;
                    tmp->next = smaller_next->next;
                    smaller_next->next = tmp;
                    smaller_next = smaller_next->next;
                    tmp = tmp_next;
                }
            }
        }  // while

        if (smaller == NULL) {
            if (bigger == NULL) {
                return NULL;
            } else {
                return bigger;
            }
        } else {
            head = smaller;
            if (bigger == NULL) {
                return head;
            } else {
                smaller_next->next = bigger;
                return head;
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
    Solution_Partition_List solution;
    ListNode *head;
    vector<int> elements;
    int x = 0;

    elements.clear();
    elements.push_back(1);
    head = createList(elements);
    dump_ListNode(head);
    x = 1;
    head = solution.partition(head, x);
    printf("x = %d\n", x);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    head = createList(elements);
    dump_ListNode(head);
    x = 0;
    head = solution.partition(head, x);
    printf("x = %d\n", x);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    head = createList(elements);
    dump_ListNode(head);
    x = 2;
    head = solution.partition(head, x);
    printf("x = %d\n", x);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(2);
    elements.push_back(1);
    head = createList(elements);
    dump_ListNode(head);
    x = 1;
    head = solution.partition(head, x);
    printf("x = %d\n", x);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    head = createList(elements);
    dump_ListNode(head);
    x = 0;
    head = solution.partition(head, x);
    printf("x = %d\n", x);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    head = createList(elements);
    dump_ListNode(head);
    x = 1;
    head = solution.partition(head, x);
    printf("x = %d\n", x);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    head = createList(elements);
    dump_ListNode(head);
    x = 2;
    head = solution.partition(head, x);
    printf("x = %d\n", x);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    head = createList(elements);
    dump_ListNode(head);
    x = 3;
    head = solution.partition(head, x);
    printf("x = %d\n", x);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");


    elements.clear();
    elements.push_back(1);
    elements.push_back(1);
    elements.push_back(1);
    elements.push_back(1);
    elements.push_back(1);
    elements.push_back(1);
    head = createList(elements);
    dump_ListNode(head);
    x = 1;
    head = solution.partition(head, x);
    printf("x = %d\n", x);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    elements.push_back(4);
    elements.push_back(3);
    elements.push_back(9);
    elements.push_back(2);
    elements.push_back(5);
    head = createList(elements);
    dump_ListNode(head);
    x = 4;
    head = solution.partition(head, x);
    printf("x = %d\n", x);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    elements.push_back(4);
    elements.push_back(3);
    elements.push_back(9);
    elements.push_back(2);
    elements.push_back(5);
    head = createList(elements);
    dump_ListNode(head);
    x = 0;
    head = solution.partition(head, x);
    printf("x = %d\n", x);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    elements.push_back(4);
    elements.push_back(3);
    elements.push_back(9);
    elements.push_back(2);
    elements.push_back(5);
    head = createList(elements);
    dump_ListNode(head);
    x = 1;
    head = solution.partition(head, x);
    printf("x = %d\n", x);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    elements.push_back(4);
    elements.push_back(3);
    elements.push_back(9);
    elements.push_back(2);
    elements.push_back(5);
    head = createList(elements);
    dump_ListNode(head);
    x = 9;
    head = solution.partition(head, x);
    printf("x = %d\n", x);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    elements.push_back(4);
    elements.push_back(3);
    elements.push_back(9);
    elements.push_back(2);
    elements.push_back(5);
    head = createList(elements);
    dump_ListNode(head);
    x = 10;
    head = solution.partition(head, x);
    printf("x = %d\n", x);
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
    x = 3;
    head = solution.partition(head, x);
    printf("x = %d\n", x);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    elements.push_back(4);
    elements.push_back(3);
    elements.push_back(2);
    elements.push_back(5);
    elements.push_back(2);
    head = createList(elements);
    dump_ListNode(head);
    x = 3;
    head = solution.partition(head, x);
    printf("x = %d\n", x);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");
}


int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

