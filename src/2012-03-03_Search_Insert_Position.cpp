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
 * File: 2012-03-03_Search_Insert_Position.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/search-insert-position/
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 *
 *
 * Date: 2014.11.02
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <assert.h>
#include <stdio.h>
#include <vector>

using std::vector;

class Solution_Insert_Position {
public:
    int searchInsert(int A[], int n, int target) {
        int result;
        if (n == 0)
            return 0;
        if (n == 1) {
            if (A[0] == target) {
                return 0;
            } else if (A[0] > target) {
                return 0;
            } else {
                return 1;
            }
        }

        int left, right, middle;
        left = 0;
        right = n - 1;
        middle = (left + right) / 2;
        while (left <= right) {  // binary search!
            if (A[middle] == target) {
                return middle;
            }

            if (A[middle] < target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
            middle = (left + right) / 2;
        }  // while
        if (A[middle] > target) {
            while (middle >= 0 && A[middle] > target) {
                middle--;
            }
            return middle + 1;
        } else if (A[middle] < target) {
            while (middle < n && A[middle] < target) {
                middle++;
            }
            return middle;
        }

        return 0;
    }
};

static void print_array(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Insert_Position solution;
    int A[4] = {1, 3, 5, 6};
    int target = -1;
    int n = 4;
    int result = solution.searchInsert(A, n, target); 
    print_array(A, n);
    printf("target = %d, insert position = %d\n", target, result);

    target = 1;
    result = solution.searchInsert(A, n, target);
    printf("target = %d, insert position = %d\n", target, result);

    target = 2;
    result = solution.searchInsert(A, n, target);
    printf("target = %d, insert position = %d\n", target, result);

    target = 3;
    result = solution.searchInsert(A, n, target);
    printf("target = %d, insert position = %d\n", target, result);

    target = 4;
    result = solution.searchInsert(A, n, target);
    printf("target = %d, insert position = %d\n", target, result);

    target = 5;
    result = solution.searchInsert(A, n, target);
    printf("target = %d, insert position = %d\n", target, result);

    target = 6;
    result = solution.searchInsert(A, n, target);
    printf("target = %d, insert position = %d\n", target, result);

    target = 7;
    result = solution.searchInsert(A, n, target);
    printf("target = %d, insert position = %d\n", target, result);

    return 0;
}

