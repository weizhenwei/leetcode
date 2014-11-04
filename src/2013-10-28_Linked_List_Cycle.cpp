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
 * File: 2013-10-28_Linked_List_Cycle.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/linked-list-cycle/
 * Given a linked list, determine if it has a cycle in it.
 *
 * Follow up:
 * Can you solve it without using extra space?
 *
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

class Solution_Linked_List_Cycle {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;

        ListNode *fast = head;
        ListNode *slow = head;
        int fast_step = 1;
        while (fast != NULL) {
            int tmp = fast_step;
            while (tmp != 0 && fast->next != NULL) {
                fast = fast->next;
                if (fast == slow)
                    return true;
                tmp--;
            }
            if (fast->next == NULL)
                return false;

            fast_step++;

            slow = slow->next;
        }

        return false;
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
    Solution_Linked_List_Cycle solution;
    ListNode *head;
    vector<int> elements;
    bool result;

    elements.push_back(1);
    head = createList(elements);
    dump_ListNode(head);
    result = solution.hasCycle(head);
    printf("has cycle = %d\n", result);
    release_ListNode(head);

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    head = createList(elements);
    dump_ListNode(head);
    result = solution.hasCycle(head);
    printf("has cycle = %d\n", result);
    release_ListNode(head);

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    head = createList(elements);
    dump_ListNode(head);
    head->next->next = head;
    result = solution.hasCycle(head);
    printf("has cycle = %d\n", result);
    head->next->next = NULL;
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
    result = solution.hasCycle(head);
    printf("has cycle = %d\n", result);
    release_ListNode(head);

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    elements.push_back(3);
    elements.push_back(4);
    elements.push_back(5);
    head = createList(elements);
    dump_ListNode(head);
    result = solution.hasCycle(head);
    printf("has cycle = %d\n", result);
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
    result = solution.hasCycle(head);
    printf("has cycle = %d\n", result);
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
    result = solution.hasCycle(head);
    printf("has cycle = %d\n", result);
    release_ListNode(head);
}


int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

