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
 * File: 2011-11-01_Add_Two_Numbers.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/add-two-numbers/
 * You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *
 *
 * Date: 2014.10.22
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

class Solution_Add_Two_Numbers {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode *result = new ListNode(-1);
        ListNode *current = result;
        ListNode *tmp = current;

        ListNode *p = l1;
        ListNode *q = l2;
        int carry = 0;
        int curbit = 0;
        while (p != NULL && q != NULL) {
            curbit = (p->val + q->val + carry) % 10;
            carry = (p->val + q->val + carry) / 10; 

            tmp = new ListNode(curbit);
            current->next = tmp;
            current = current->next;

            p = p->next;
            q = q->next;
        }

        ListNode *more = (p == NULL) ? q : p;
        while (more != NULL) {
            curbit = (more->val + carry) % 10;
            carry = (more->val + carry) / 10;

            tmp = new ListNode(curbit);
            current->next = tmp;
            current = current->next;

            more = more->next;
        }
        if (carry != 0) {
            tmp = new ListNode(carry);
            current->next = tmp;
            current = current->next;
        }

        tmp = result;
        result = result->next;
        delete tmp;

        return result;
    }
};

static ListNode *create_NodeList(vector<int> &numbers) {
    int i = 0; 
    ListNode *list = new ListNode(-1);
    ListNode *node = list;
    ListNode *tmp = node;

    for (i = 0; i < numbers.size(); i++) {
        int value = numbers[i];
        tmp = new ListNode(value);
        node->next = tmp;
        node = node->next;
    }

    tmp = list;
    list = list->next;
    delete tmp;

    return list;
}

static void dump_NodeList(ListNode *list) {
    ListNode *p = list;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}
static void release_NodeList(ListNode *list) {
    ListNode *p = list;
    ListNode *tmp = list;
    while (p != NULL) {
        tmp = p;
        p = p->next;
        delete tmp;
    }
}
static void testcase(vector<int> n1, vector<int> n2) {
    ListNode *l1 = create_NodeList(n1);
    ListNode *l2 = create_NodeList(n2);

    Solution_Add_Two_Numbers atn;
    ListNode *result = atn.addTwoNumbers(l1, l2);

    printf("run a testcase:\n");
    dump_NodeList(l1);
    dump_NodeList(l2);
    dump_NodeList(result);
    release_NodeList(l1);
    release_NodeList(l2);
    if (result != l1 && result != l2)
        release_NodeList(result);
}

int main(int argc, char *argv[]) {
    vector<int> n1;
    vector<int> n2;
    n1.push_back(2);
    n1.push_back(4);
    n1.push_back(3);
    n2.push_back(5);
    n2.push_back(6);
    n2.push_back(4);
    testcase(n1, n2);

    n1.clear();
    n2.clear();
    n1.push_back(2);
    n1.push_back(4);
    n1.push_back(3);
    testcase(n1, n2);

    n1.clear();
    n2.clear();
    n1.push_back(9);
    n1.push_back(9);
    n1.push_back(9);
    n2.push_back(9);
    n2.push_back(9);
    n2.push_back(9);
    n2.push_back(9);
    n2.push_back(9);
    testcase(n1, n2);

    n1.clear();
    n2.clear();
    n1.push_back(3);
    n1.push_back(7);
    n2.push_back(9);
    n2.push_back(2);
    testcase(n1, n2);

    n1.clear();
    n2.clear();
    n1.push_back(0);
    n2.push_back(7);
    n2.push_back(3);
    testcase(n1, n2);

    return 0;
}
