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
 * File: 2012-02-14_Rotate_List.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/rotate-list/
 * Given a list, rotate the list to the right by k places, where k is
 * non-negative.
 *
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 *
 * Date: 2014.10.29
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <assert.h>
#include <stdio.h>
#include <vector>

using std::vector;

// Definition for singly-linked list.
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}ListNode;

class Solution_Rotate_List {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (k == 0)
            return head;
        if (head == NULL)
            return NULL;

        ListNode *slow = head;
        ListNode *slow_prev = head;
        ListNode *fast = head;
        ListNode *fast_prev = head;
        int i = k;
        int len = 0;
        while (i > 0 && fast != NULL) {
            fast_prev = fast;
            fast = fast->next;
            len++;
            i--;
        }
        if (fast == NULL) {
            if (i == 0) {  // k == length(head);
                return head;
            } else {
                i = k % len;
                if (i == 0)
                    return head;

                fast = head;
                fast_prev = head;
                while (i > 0 && fast != NULL) {
                    fast_prev = fast;
                    fast = fast->next;
                    i--;
                }
                if (fast == NULL)
                    return head;
            }
        }

        while (fast != NULL) {
            fast_prev = fast;
            fast = fast->next;
            slow_prev = slow;
            slow = slow->next;
        }

        // now slow is the rotate point;
        fast_prev->next = head;
        head = slow_prev->next;
        slow_prev->next = NULL;

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
    Solution_Rotate_List solution;
    ListNode *head;
    vector<int> elements;
    int k = 0;

    elements.push_back(1);
    head = createList(elements);
    printf("before rotate:\n");
    dump_ListNode(head);
    k = 0;
    head = solution.rotateRight(head, k);
    printf("after rotate k = %d:\n", k);
    dump_ListNode(head);
    k = 1;
    head = solution.rotateRight(head, k);
    printf("after rotate k = %d:\n", k);
    dump_ListNode(head);
    k = 99;
    head = solution.rotateRight(head, k);
    printf("after rotate k = %d:\n", k);
    dump_ListNode(head);
    release_ListNode(head);

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    head = createList(elements);
    printf("before rotate:\n");
    dump_ListNode(head);
    k = 0;
    head = solution.rotateRight(head, k);
    printf("after rotate k = %d:\n", k);
    dump_ListNode(head);
    k = 1;
    head = solution.rotateRight(head, k);
    printf("after rotate k = %d:\n", k);
    dump_ListNode(head);
    k = 2;
    head = solution.rotateRight(head, k);
    printf("after rotate k = %d:\n", k);
    dump_ListNode(head);
    k = 3;
    head = solution.rotateRight(head, k);
    printf("after rotate k = %d:\n", k);
    dump_ListNode(head);
    release_ListNode(head);

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    elements.push_back(3);
    elements.push_back(4);
    elements.push_back(5);
    head = createList(elements);
    printf("before rotate:\n");
    dump_ListNode(head);
    k = 0;
    head = solution.rotateRight(head, k);
    printf("after rotate k = %d:\n", k);
    dump_ListNode(head);
    k = 1;
    head = solution.rotateRight(head, k);
    printf("after rotate k = %d:\n", k);
    dump_ListNode(head);
    k = 2;
    head = solution.rotateRight(head, k);
    printf("after rotate k = %d:\n", k);
    dump_ListNode(head);
    k = 3;
    head = solution.rotateRight(head, k);
    printf("after rotate k = %d:\n", k);
    dump_ListNode(head);
    k = 4;
    head = solution.rotateRight(head, k);
    printf("after rotate k = %d:\n", k);
    dump_ListNode(head);
    k = 5;
    head = solution.rotateRight(head, k);
    printf("after rotate k = %d:\n", k);
    dump_ListNode(head);
    k = 6;
    head = solution.rotateRight(head, k);
    printf("after rotate k = %d:\n", k);
    dump_ListNode(head);
    k = 10;
    head = solution.rotateRight(head, k);
    printf("after rotate k = %d:\n", k);
    dump_ListNode(head);
    release_ListNode(head);

}

int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

