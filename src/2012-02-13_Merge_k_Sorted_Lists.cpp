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
 * File: 2012-02-12_Merge_k_Sorted_Lists.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/merge-k-sorted-lists/
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 *
 *
 * Date: 2014.10.27
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <vector>

using std::make_heap;
using std::push_heap;
using std::pop_heap;
using std::vector;

// Definition for singly-linked list.
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}ListNode;

class Solution_Merge_k_Sorted_Lists {
public:
    ListNode *mergeKListsStupid(vector<ListNode *> &lists) {
        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists[0];

        vector<ListNode *>::iterator iter;
        for (iter = lists.begin(); iter != lists.end(); iter++) {
            if ((*iter) == NULL) {
                iter = lists.erase(iter);
                iter--;
            }
        }
        if (lists.size() == 0)
            return NULL;

        ListNode *head = NULL;
        ListNode *tmp = NULL;
        do {
            int min = INT_MAX;
            ListNode *minptr = NULL;
            int i = 0, minidx = 0;
            for (i = 0; i < lists.size(); i++) {
                if (lists[i] != NULL) {
                    if (min > lists[i]->val) {
                        min = lists[i]->val;
                        minptr = lists[i];
                        minidx = i;
                    }
                }
            }

            if (tmp == NULL) {
                head = tmp = minptr;
            } else {
                tmp->next = minptr;
                tmp = tmp->next;
            }

            minptr = minptr->next;
            if (minptr == NULL) {
                vector<ListNode *>::iterator del = lists.begin() + minidx;
                lists.erase(del);
            } else {
                lists[minidx] = minptr;
            }

            if (lists.size() == 1) {
                tmp->next = lists[0];
                break;
            }
        } while (lists.size() != 0);

        return head;
    }


    struct NodeCompare {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        vector<ListNode *> heap;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                heap.push_back(lists[i]);
            }
        }  // for

        // make heap;
        make_heap(heap.begin(), heap.end(), NodeCompare());

        ListNode *head = NULL;
        ListNode *current = NULL;
        while (!heap.empty()) {
            ListNode *min = heap.front();
            pop_heap(heap.begin(), heap.end(), NodeCompare());
            heap.pop_back();

            if (!head) {
                head = min;
            }

            if (current) {
                current->next = min;
            }
            current = min;

            if (min->next) {
                min = min->next;
                heap.push_back(min);
                push_heap(heap.begin(), heap.end(), NodeCompare());
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
    Solution_Merge_k_Sorted_Lists solution;
    ListNode *list1;
    ListNode *list2;
    ListNode *list3;
    vector<int> elements;
    ListNode *list = NULL;
    vector<ListNode *> lists;

    elements.push_back(1);
    list1 = createList(elements);
    printf("list1:");
    dump_ListNode(list1);

    lists.clear();
    lists.push_back(list1);
    list = solution.mergeKLists(lists);
    printf("after merge list:");
    dump_ListNode(list);
    release_ListNode(list);



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

    lists.clear();
    lists.push_back(list1);
    lists.push_back(list2);

    list = solution.mergeKLists(lists);
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
    list3 = createList(elements);
    printf("list3:");
    dump_ListNode(list3);

    lists.clear();
    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);
    list = solution.mergeKLists(lists);
    printf("after merge:");
    dump_ListNode(list);
    release_ListNode(list);

    list1 = NULL;
    printf("list1:");
    dump_ListNode(list1);
    list2 = NULL;
    printf("list2:");
    dump_ListNode(list2);
    lists.clear();
    lists.push_back(list1);
    lists.push_back(list2);
    list = solution.mergeKLists(lists);
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
    lists.clear();
    lists.push_back(list1);
    lists.push_back(list2);
    list = solution.mergeKLists(lists);
    printf("after merge:");
    dump_ListNode(list);
    release_ListNode(list);
}

int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

