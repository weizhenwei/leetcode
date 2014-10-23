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
 * File: 2012-01-27_Remove_Nth_Node_From_End_of_List.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/
 * Given a linked list, remove the nth node from the end of list
 * and return its head.
 *
 * For example,
 *
 *    Given linked list: 1->2->3->4->5, and n = 2.
 *
 *       After removing the second node from the end, the linked list becomes
 *       1->2->3->5.
 *       Note:
 *       Given n will always be valid.
 *       Try to do this in one pass.
 *
 *
 * Date: 2014.10.23
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

class Solution_Remove_Nth_Node_From_End_of_List {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        vector<ListNode *> pointers;
        ListNode *p = head;

        while (p != NULL) {
            pointers.push_back(p);
            p = p->next;
        }

        int position = pointers.size() - n;
        ListNode *prev, *current, *tmp;
        if (position == 0) {
            tmp = head;
            head = head->next;
            delete tmp;

            return head;
        } else {
            prev = pointers[position - 1];
            current = pointers[position];
            prev->next = current->next;

            tmp = current;
            delete tmp;
        }

        return head;
    }

    ListNode *removeNthFromEnd_clever(ListNode *head, int n) {
        ListNode *prev = head;
        ListNode *fast = head;
        ListNode *slow = head;

        int m = n;
        while ((m > 0) && (fast != NULL)) {
            fast = fast->next;
            m--;
        }
        if (m > 0) {  // input error;
            return NULL;
        }

        while (fast != NULL) {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }

        if (slow == head) {
            head = head->next;
            delete prev;
        } else {
            prev->next = slow->next;
            delete slow;
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
    Solution_Remove_Nth_Node_From_End_of_List solution;
    ListNode *head;
    vector<int> elements;

    elements.push_back(1);
    head = createList(elements);
    dump_ListNode(head);
    head = solution.removeNthFromEnd(head, 1);
    dump_ListNode(head);
    release_ListNode(head);

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    head = createList(elements);
    dump_ListNode(head);
    head = solution.removeNthFromEnd(head, 1);
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
    head = solution.removeNthFromEnd(head, 2);
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
    head = solution.removeNthFromEnd(head, 1);
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
    head = solution.removeNthFromEnd(head, 5);
    dump_ListNode(head);
    release_ListNode(head);
}

void testcase_clever() {
    Solution_Remove_Nth_Node_From_End_of_List solution;
    ListNode *head;
    vector<int> elements;

    elements.push_back(1);
    head = createList(elements);
    dump_ListNode(head);
    head = solution.removeNthFromEnd_clever(head, 1);
    dump_ListNode(head);
    release_ListNode(head);

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    head = createList(elements);
    dump_ListNode(head);
    head = solution.removeNthFromEnd_clever(head, 1);
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
    head = solution.removeNthFromEnd_clever(head, 2);
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
    head = solution.removeNthFromEnd_clever(head, 1);
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
    head = solution.removeNthFromEnd_clever(head, 5);
    dump_ListNode(head);
    release_ListNode(head);
}

int main(int argc, char *argv[]) {
    testcase();
    testcase_clever();

    return 0;
}

