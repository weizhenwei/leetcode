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
 * File: 2014-11-27_Intersecion_of_Two_Linked_Lists.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/intersection-of-two-linked-lists/
 * For example, the following two linked lists:
 *
 * A:          a1 → a2
 *                    ↘
 *                      c1 → c2 → c3
 *                    ↗            
 * B:     b1 → b2 → b3
 * begin to intersect at node c1.
 * 
 * Notes:
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 *
 * Date: 2014.11.27
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <vector>

using std::vector;

// Definition for singly-linked list.
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}ListNode;

class Solution_Intersection_of_Two_Linked_Lists {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }

        int lenA = 1;
        ListNode *tailA = headA;
        while (tailA->next != NULL) {
            lenA++;
            tailA = tailA->next;
        }

        int lenB = 1;
        ListNode *tailB = headB;
        while (tailB->next != NULL) {
            lenB++;
            tailB = tailB->next;
        }

        if (tailA != tailB) {
            return NULL;
        }

        int sub = abs(lenA - lenB);
        ListNode *fastPtr = NULL;
        ListNode *slowPtr = NULL;
        if (lenA >= lenB) {
            fastPtr = headA;
            slowPtr = headB;
        } else {
            fastPtr = headB;
            slowPtr = headA;
        }

        while (sub > 0) {
            fastPtr = fastPtr->next;
            sub--;
        }

        while (fastPtr != slowPtr) {
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
        }

        return fastPtr;
    }
};

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
    Solution_Intersection_of_Two_Linked_Lists solution;
    ListNode *headA = NULL;
    ListNode *headB = NULL;

    headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    headB = new ListNode(10);
    headB->next = new ListNode(9);
    headB->next->next = headA->next;

    dump_ListNode(headA);
    dump_ListNode(headB);
    ListNode *intersectionNode = solution.getIntersectionNode(headA, headB);
    printf("Intersection Node:%d\n", intersectionNode->val);
    headB->next->next = NULL;
    release_ListNode(headA);
    release_ListNode(headB);



    headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    headB = headA;
    dump_ListNode(headA);
    dump_ListNode(headB);
    intersectionNode = solution.getIntersectionNode(headA, headB);
    printf("Intersection Node:%d\n", intersectionNode->val);
    release_ListNode(headA);


    headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    headB = headA->next;
    dump_ListNode(headA);
    dump_ListNode(headB);
    intersectionNode = solution.getIntersectionNode(headA, headB);
    printf("Intersection Node:%d\n", intersectionNode->val);
    release_ListNode(headA);
}

int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

