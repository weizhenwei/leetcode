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
 * File: 2013-10-30_Linked_List_Cycle_II.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/linked-list-cycle-ii/
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
 *
 * Follow up:
 * Can you solve it without using extra space?
 *
 *
 * Here is a hit from: https://oj.leetcode.com/discuss/9908/
 *                     o-n-solution-by-using-two-pointers-without-change-anything
 * using two pointers, one of them one step at a time. 
 * another pointer each take two steps. Suppose the first meet at step k,
 * the length of the Cycle is r. so..2k-k=nr,k=nr
 * Now, the distance between the start node of list and the start node of
 * cycle is s. the distance between the start of list and the first meeting node
 * is k(the pointer which wake one step at a time waked k steps).
 * the distance between the start node of cycle and the first meeting node is m,
 * so...s=k-m, s=nr-m=(n-1)r+(r-m),here we takes n = 1..
 * so, using one pointer start from the start node of list, another pointer
 * start from the first meeting node, all of them wake one step at a time,
 * the first time they meeting each other is the start of the cycle.
 *
 * Date: 2014.11.04
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

class Solution_Linked_List_Cycle_II {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        if (fast == NULL || fast->next == NULL)
            return NULL;

        // else we got an cycle;
        ListNode *start = head;
        while (start != slow) {
            start = start->next;
            slow = slow->next;
        }

        return start;
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
    Solution_Linked_List_Cycle_II solution;
    ListNode *head;
    vector<int> elements;
    ListNode *result;

    elements.push_back(1);
    head = createList(elements);
    dump_ListNode(head);
    result = solution.detectCycle(head);
    if (result != NULL) {
        printf("cycle start val = %d\n", result->val);
    } else {
        printf("no cycle\n");
    }
    release_ListNode(head);

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    head = createList(elements);
    dump_ListNode(head);
    result = solution.detectCycle(head);
    if (result != NULL) {
        printf("cycle start val = %d\n", result->val);
    } else {
        printf("no cycle\n");
    }
    release_ListNode(head);

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    head = createList(elements);
    dump_ListNode(head);
    head->next->next = head;
    result = solution.detectCycle(head);
    if (result != NULL) {
        printf("cycle start val = %d\n", result->val);
    } else {
        printf("no cycle\n");
    }
    head->next->next = NULL;
    release_ListNode(head);
}

void testcase2() {
    Solution_Linked_List_Cycle_II solution;
    ListNode *head;
    vector<int> elements;
    ListNode *result;

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    elements.push_back(3);
    elements.push_back(4);
    elements.push_back(5);
    elements.push_back(6);
    head = createList(elements);
    dump_ListNode(head);

    ListNode *end = head;;
    while (end->next != NULL) {
        end = end->next;
    }

    // start point = 3
    end->next = head->next->next;
    result = solution.detectCycle(head);
    if (result != NULL) {
        printf("cycle start val = %d\n", result->val);
    } else {
        printf("no cycle\n");
    }
    end->next = NULL;
    release_ListNode(head);
}



int main(int argc, char *argv[]) {
    testcase();
    testcase2();

    return 0;
}

