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
 * File: 2012-03-30_Merge_Two_Sorted_Lists.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/merge-two-sorted-lists/
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
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

class Solution_Merge_Two_Sorted_Lists {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }

        ListNode *head = NULL;
        ListNode *tmp = NULL;
        if (l1->val <= l2->val) {
            head = tmp = l1;
            l1 = l1->next;
        } else {
            head = tmp = l2;
            l2 = l2->next;
        }
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                tmp ->next = l1;
                tmp = tmp->next;
                l1 = l1->next;
            } else {
                tmp->next = l2;
                tmp = tmp->next;
                l2 = l2->next;
            }
        }

        if (l1 != NULL) {
            tmp->next = l1;
        } else if (l2 != NULL) {
            tmp->next = l2;
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
    Solution_Merge_Two_Sorted_Lists solution;
    ListNode *list1;
    ListNode *list2;
    vector<int> elements;
    ListNode *list = NULL;


    elements.clear();
    elements.push_back(1);
    list1 = createList(elements);
    printf("list1:");
    dump_ListNode(list1);

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    list2 = createList(elements);
    printf("list2:");
    dump_ListNode(list2);

    list = solution.mergeTwoLists(list1, list2);
    printf("after merge list:");
    dump_ListNode(list);
    release_ListNode(list);


    elements.clear();
    elements.push_back(3);
    list1 = createList(elements);
    printf("list1:");
    dump_ListNode(list1);

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    list2 = createList(elements);
    printf("list2:");
    dump_ListNode(list2);

    list = solution.mergeTwoLists(list1, list2);
    printf("after merge list:");
    dump_ListNode(list);
    release_ListNode(list);


    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    elements.push_back(3);
    elements.push_back(4);
    elements.push_back(5);
    list1 = createList(elements);
    printf("list1:");
    dump_ListNode(list1);

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    elements.push_back(3);
    elements.push_back(4);
    elements.push_back(5);
    elements.push_back(6);
    list2 = createList(elements);
    printf("list2:");
    dump_ListNode(list2);


    list = solution.mergeTwoLists(list1, list2);
    printf("after merge:");
    dump_ListNode(list);
    release_ListNode(list);

    list1 = NULL;
    printf("list1:");
    dump_ListNode(list1);
    list2 = NULL;
    printf("list2:");
    dump_ListNode(list2);
    list = solution.mergeTwoLists(list1, list2);
    printf("after merge:");
    dump_ListNode(list);
    release_ListNode(list);

    list1 = NULL;
    printf("list1:");
    dump_ListNode(list1);
    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    elements.push_back(3);
    elements.push_back(4);
    elements.push_back(5);
    elements.push_back(6);
    list2 = createList(elements);
    printf("list2:");
    dump_ListNode(list2);
    list = solution.mergeTwoLists(list1, list2);
    printf("after merge:");
    dump_ListNode(list);
    release_ListNode(list);
}

int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

