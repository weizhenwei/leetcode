/*
 *
 * Copyright (c) 2015, weizhenwei
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
 * File: 234-Palindrome_Linked_List.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/palindrome-linked-list/
 * Given a singly linked list, determine if it is a palindrome.
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 *
 *
 * Date: 2015.09.28
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <vector>

using std::vector;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution_Palindrome_Linked_List {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        if (head->next->next == NULL) {
            return head->val == head->next->val;
        }

        bool result = true;
        int len = 0;
        ListNode *tail = head;
        while (tail->next != NULL) {
            len++;
            tail = tail->next;
        }
        len++;  // add the tail node;


        // got the head of second half;
        ListNode *firstHalf = head;
        ListNode *secondHalf = firstHalf;
        ListNode *firstHalfTail = secondHalf;
        int halfLen = len / 2;
        while (halfLen > 0) {
            firstHalfTail = secondHalf;
            secondHalf = secondHalf->next;
            halfLen--;
        }
        if (len % 2 == 1) {  // odd nodes;
            firstHalfTail = secondHalf;
            secondHalf = secondHalf->next;
        }
        firstHalfTail->next = NULL;

        // in case there are only 3 nodes;
        if (secondHalf == tail) {
            firstHalfTail->next = secondHalf;
            tail->next = NULL;
            return head->val == secondHalf->val;
        }

        // reverse second half;
        tail->next = secondHalf;
        secondHalf = secondHalf->next;
        tail->next->next = NULL;
        while (secondHalf != NULL && secondHalf != tail) {
            ListNode *next = secondHalf->next;
            secondHalf->next = tail->next;
            tail->next = secondHalf;
            secondHalf = next;
        }

        // second half's head is always hold by tail;
        firstHalf = head;
        secondHalf = tail;
        while (secondHalf != NULL) {
            if (firstHalf->val != secondHalf->val) {
                result = false;
                break;
            } else {
                firstHalf = firstHalf->next;
                secondHalf = secondHalf->next;
            }
        }  // while;

        // recovery second half;
        firstHalfTail->next = tail;
        tail = tail->next;
        firstHalfTail->next->next = NULL;
        while (tail->next != NULL) {
            ListNode *next = tail->next;
            tail->next = firstHalfTail->next;
            firstHalfTail->next = tail;
            tail = next;
        }
        tail->next = firstHalfTail->next;
        firstHalfTail->next = tail;

        return result;
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
    Solution_Palindrome_Linked_List solution;
    ListNode *head;
    vector<int> elements;
    bool bPalindrome = false;

    elements.clear();
    head = createList(elements);
    dump_ListNode(head);
    bPalindrome = solution.isPalindrome(head);
    dump_ListNode(head);
    printf("is Palindrome_Linked_List = %d\n", bPalindrome);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    head = createList(elements);
    dump_ListNode(head);
    bPalindrome = solution.isPalindrome(head);
    dump_ListNode(head);
    printf("is Palindrome_Linked_List = %d\n", bPalindrome);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    elements.push_back(3);
    head = createList(elements);
    dump_ListNode(head);
    bPalindrome = solution.isPalindrome(head);
    dump_ListNode(head);
    printf("is Palindrome_Linked_List = %d\n", bPalindrome);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    elements.push_back(3);
    elements.push_back(4);
    head = createList(elements);
    dump_ListNode(head);
    bPalindrome = solution.isPalindrome(head);
    dump_ListNode(head);
    printf("is Palindrome_Linked_List = %d\n", bPalindrome);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    elements.push_back(2);
    elements.push_back(1);
    head = createList(elements);
    dump_ListNode(head);
    bPalindrome = solution.isPalindrome(head);
    dump_ListNode(head);
    printf("is Palindrome_Linked_List = %d\n", bPalindrome);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    elements.push_back(2);
    elements.push_back(2);
    elements.push_back(1);
    head = createList(elements);
    dump_ListNode(head);
    bPalindrome = solution.isPalindrome(head);
    dump_ListNode(head);
    printf("is Palindrome_Linked_List = %d\n", bPalindrome);
    release_ListNode(head);
    printf("\n");

    elements.clear();
    elements.push_back(1);
    elements.push_back(2);
    elements.push_back(2);
    elements.push_back(2);
    elements.push_back(1);
    elements.push_back(1);
    head = createList(elements);
    dump_ListNode(head);
    bPalindrome = solution.isPalindrome(head);
    dump_ListNode(head);
    printf("is Palindrome_Linked_List = %d\n", bPalindrome);
    release_ListNode(head);
    printf("\n");
}

int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

