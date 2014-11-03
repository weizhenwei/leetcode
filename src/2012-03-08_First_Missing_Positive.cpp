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
 * File: 2012-03-08_First_Missing_Positive.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/first-missing-positive/
 * Given an unsorted integer array, find the first missing positive integer.
 *
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 *
 * Your algorithm should run in O(n) time and uses constant space.
 *
 *
 * Date: 2014.11.03
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>

#include <algorithm>

using std::swap;

class Solution_First_Missing_Positive {
public:
    int firstMissingPositive(int A[], int n) {
        int i;
        for (i = 0; i < n; i++) {
            int current = A[i];
            if (current == i + 1) { // in place
                continue;
            } else if (current > n || current <= 0) {  // out of bound;
                continue;
            } else {
                swap(A[i], A[current-1]);
                if (A[i] != A[current-1])
                    i--;
            }
        }

        for (i = 0; i < n; i++) {
            if (A[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }
};

static void print_array(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    printf("\n");
}
int main(int argc, char *argv[]) {
    Solution_First_Missing_Positive solution;
    int A[3] = {1, 2, 0};
    int n = 3;
    int missing = solution.firstMissingPositive(A, n);
    print_array(A, n);
    printf("first missing is %d\n", missing);

    int B[4] = {3, 4, -1, 1};
    n = 4;
    missing = solution.firstMissingPositive(B, n);
    print_array(B, n);
    printf("first missing is %d\n", missing);

    return 0;
}
