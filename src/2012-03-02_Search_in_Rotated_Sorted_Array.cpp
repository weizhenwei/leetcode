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
 * File: 2012-03-02_Search_in_Rotated_Sorted_Array.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/search-in-rotated-sorted-array/
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 *
 * Date: 2014.10.28
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>

class Solution_Search_in_Rotated_Sorted_Array {
public:
    int search(int A[], int n, int target) {
        if (n == 0)
            return -1;
        if (n == 1) {
            if (A[0] == target)
                return 0;
            else
                return -1;
        }

        int left = 0;
        int right = n - 1;
        int middle = (left + right) / 2;
        while (left < right) {
            if (A[left] == target)
                return left;
            if (A[right] == target)
                return right;
            if (A[middle] == target)
                return middle;

            if (A[left] < A[middle]) {  // left is sorted bigger;
                if (target > A[middle]) {  // candidate in right;
                    left = middle + 1;
                } else {
                    if (target > A[left]) {
                        right = middle - 1;
                    } else {
                        left = middle + 1;
                    }
                }
            } else {  // right is sorted smaller;
                if (target < A[middle]) {  // candidate in left;
                    right = middle - 1;
                } else {
                    if (target > A[left])
                        right = middle - 1;
                    else
                        left = middle + 1;
                }
            }

            middle = (left + right) / 2;
        }  // while

        return -1;
    }
};


static void print_array(int A[], int n) {
    printf("Array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

static void test_case(int A[], int n) {
    Solution_Search_in_Rotated_Sorted_Array solution;
    int elem, idx;
    print_array(A, n);

    elem = 0;
    idx = solution.search(A, n, elem);
    printf("index of element %d is %d\n", elem, idx);

    elem = 1;
    idx = solution.search(A, n, elem);
    printf("index of element %d is %d\n", elem, idx);

    elem = 2;
    idx = solution.search(A, n, elem);
    printf("index of element %d is %d\n", elem, idx);

    elem = 3;
    idx = solution.search(A, n, elem);
    printf("index of element %d is %d\n", elem, idx);

    elem = 4;
    idx = solution.search(A, n, elem);
    printf("index of element %d is %d\n", elem, idx);

    elem = 5;
    idx = solution.search(A, n, elem);
    printf("index of element %d is %d\n", elem, idx);

    elem = 6;
    idx = solution.search(A, n, elem);
    printf("index of element %d is %d\n", elem, idx);

    elem = 7;
    idx = solution.search(A, n, elem);
    printf("index of element %d is %d\n", elem, idx);

    elem = 8;
    idx = solution.search(A, n, elem);
    printf("index of element %d is %d\n", elem, idx);

    elem = 9;
    idx = solution.search(A, n, elem);
    printf("index of element %d is %d\n", elem, idx);

    elem = 10;
    idx = solution.search(A, n, elem);
    printf("index of element %d is %d\n", elem, idx);
}

static void test_case2(int A[], int n) {
    Solution_Search_in_Rotated_Sorted_Array solution;
    int elem, idx;
    print_array(A, n);

    elem = 0;
    idx = solution.search(A, n, elem);
    printf("index of element %d is %d\n", elem, idx);

    elem = 1;
    idx = solution.search(A, n, elem);
    printf("index of element %d is %d\n", elem, idx);

    elem = 2;
    idx = solution.search(A, n, elem);
    printf("index of element %d is %d\n", elem, idx);

    elem = 3;
    idx = solution.search(A, n, elem);
    printf("index of element %d is %d\n", elem, idx);
}

static void test_case3() {
    Solution_Search_in_Rotated_Sorted_Array solution;
    int A[5] = {8, 9, 2, 3, 4};
    int n = 5;
    int elem, idx;
    print_array(A, n);


    elem = 9;
    idx = solution.search(A, n, elem);
    printf("index of element %d is %d\n", elem, idx);
}

int main(int argc, char *argv[]) {
    int A[9] = {5, 6, 7, 8, 9, 1, 2, 3, 4};
    test_case(A, 9);

    int B[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    test_case(B, 9);

    int C[9] = {9, 1, 2, 3, 4, 5, 6, 7, 8};
    test_case(C, 9);

    int D[9] = {2, 3, 4, 5, 6, 7, 8, 9, 1};
    test_case(D, 9);

    int AA[2] = {1, 2};
    test_case2(AA, 2);

    int BB[2] = {2, 1};
    test_case2(BB, 2);

    test_case3();
    return 0;
}
