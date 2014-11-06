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
 * File: 2013-11-12_Insertion_Sort_List.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/insertion-sort-list/
 * Sort a linked list using insertion sort.
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

class Solution_Insertion_Sort_List {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *flag = head;
        ListNode *flag_prev = head;
        ListNode *target = head;
        ListNode *target_prev = head;
        ListNode *target_next = head;
        while (flag != NULL) {
            target = flag;
            int min = target->val;
            ListNode *tmp_prev = flag;
            ListNode *tmp = flag->next;
            while (tmp != NULL) {
                if (tmp->val < min) {
                    min = tmp->val;
                    target_prev = tmp_prev;
                    target = tmp;
                    target_next = tmp->next;
                }
                tmp_prev = tmp;
                tmp = tmp->next;
            }

            if (flag == head) {
                if (target == flag) {
                    flag_prev = flag;
                    flag = flag->next;
                } else {
                    if (flag->next == target) {
                        head = target;
                        flag->next = target->next;
                        target->next = flag;
                    } else {
                        head = target;
                        flag_prev = flag->next;
                        flag->next = target_next;
                        target->next = flag_prev;
                        target_prev->next = flag;
                    }

                    flag = target;
                    flag_prev = flag;
                    flag = flag->next;
                }
            } else {
                if (target == flag) {
                    flag_prev = flag;
                    flag = flag->next;
                } else {
                    if (flag->next == target) {
                        flag->next = target->next;
                        target->next = flag;
                        flag_prev->next = target;
                    } else {
                        flag_prev->next = target;
                        target->next = flag->next;
                        target_prev->next = flag;
                        flag->next = target_next;
                    }

                    flag = target;
                    flag_prev = flag;
                    flag = flag->next;
                }
            }
        }  // while

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
    Solution_Insertion_Sort_List solution;
    ListNode *head;
    vector<int> elements;

    elements.push_back(1);
    head = createList(elements);
    dump_ListNode(head);
    head = solution.insertionSortList(head);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(2);
    elements.push_back(1);
    head = createList(elements);
    dump_ListNode(head);
    head = solution.insertionSortList(head);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    head = createList(elements);
    dump_ListNode(head);
    head = solution.insertionSortList(head);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");


    elements.clear();
    elements.push_back(5);
    elements.push_back(1);
    elements.push_back(3);
    elements.push_back(2);
    elements.push_back(4);
    head = createList(elements);
    dump_ListNode(head);
    head = solution.insertionSortList(head);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    elements.push_back(1);
    elements.push_back(1);
    elements.push_back(1);
    elements.push_back(3);
    elements.push_back(2);
    elements.push_back(2);
    elements.push_back(2);
    elements.push_back(2);
    elements.push_back(2);
    elements.push_back(3);
    elements.push_back(4);
    elements.push_back(5);
    elements.push_back(6);
    elements.push_back(6);
    head = createList(elements);
    dump_ListNode(head);
    head = solution.insertionSortList(head);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(12);
    elements.push_back(11);
    elements.push_back(1);
    elements.push_back(9);
    elements.push_back(4);
    elements.push_back(10);
    elements.push_back(2);
    elements.push_back(8);
    elements.push_back(3);
    elements.push_back(6);
    elements.push_back(7);
    elements.push_back(5);
    head = createList(elements);
    dump_ListNode(head);
    head = solution.insertionSortList(head);
    dump_ListNode(head);
    release_ListNode(head);
    printf("\n");
}


int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

