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
 * File: 2013-10-28_Copy_List_with_Random_Pointer.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/copy-list-with-random-pointer/
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
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


// Definition for singly-linked list with a random pointer.
typedef struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
} RandomListNode;

class Solution_Copy_List_with_Random_Pointer {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        RandomListNode *current = head;
        RandomListNode *currentCopy;
        while (current != NULL) {
            currentCopy = new RandomListNode(current->label);
            currentCopy->next = current->next;
            current->next = currentCopy;
            current = currentCopy->next;
        }  // while 1

        current = head;
        while (current != NULL) {
            if (current->random != NULL) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }  // while 2

        RandomListNode *copyHead = head->next;
        current = head;
        currentCopy = copyHead;
        while (current != NULL) {
            current->next = currentCopy->next;
            current = current->next;
            if (current != NULL) {
                currentCopy->next = current->next;
                currentCopy = currentCopy->next;
            }
        }  // while 3

        return copyHead;
    }
};

static void dump_ListNode(RandomListNode *head) {
    RandomListNode *p = head;

    while (p != NULL) {
        printf("p->label = %d, ", p->label);
        if (p->random != NULL) {
            printf("p->random = %d\n", p->random->label);
        } else {
            printf("\n");
        }
        p = p->next;
    }
}

static void release_ListNode(RandomListNode *head) {
    RandomListNode *p = head;
    RandomListNode *tmp = NULL;

    while (p != NULL) {
        tmp = p;
        p = p->next;
        delete tmp;
    }
}

void testcase() {
    Solution_Copy_List_with_Random_Pointer solution;
    RandomListNode *head = new RandomListNode(1);
    head->next = new RandomListNode(2);
    head->next->next = new RandomListNode(3);
    head->next->next->next = new RandomListNode(4);
    head->next->next->next->next = new RandomListNode(5);

    head->random = head->next;
    head->next->random = head->next->next->next;
    head->next->next->random = head->next->next->next->next;

    printf("before copyList:\n");
    dump_ListNode(head);
    RandomListNode *copyHead = solution.copyRandomList(head);
    printf("after copyList:\n");
    printf("original List:\n");
    dump_ListNode(head);
    printf("copyed List:\n");
    dump_ListNode(copyHead);

    release_ListNode(head);
    release_ListNode(copyHead);
}


int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

