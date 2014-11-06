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
 * File: 2012-05-20_Merge_Sorted_Array.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/merge-sorted-array/
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 *
 * Note:
 * You may assume that A has enough space (size that is greater or equal to m +
 * n) to hold additional elements from B. The number of elements initialized in
 * A and B are m and n respectively.
 *
 * inspired by: https://oj.leetcode.com/discuss/14788/
 *              what-is-the-time-complexity-and-space-complexity-of-my-c-code
 *
 *
 * Date: 2014.10.21
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>

class Solution_Merge_Sorted_Array {
public:
    void merge(int A[], int m, int B[], int n) {
        int len = m + n - 1;
        for (int i = m - 1, j = n - 1; j >= 0;) {
            if (i >= 0 && A[i] > B[j]) {
                A[len--] = A[i--];
            } else {
                A[len--] = B[j--];
            }
        }  // for
    }
};

static void print_array(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Merge_Sorted_Array solution;
    int A[20] = {1, 3, 7, 10, 16};
    int m = 5;
    int B[4] = {7, 13, 19, 24};
    int n = 4;
    print_array(A, m);
    print_array(B, n);
    solution.merge(A, m, B, n);
    print_array(A, m + n);

    int C[20] = {1, 3, 7, 10, 16};
    m = 5;
    int D[3] = {17, 33, 44};
    n = 3;
    print_array(C, m);
    print_array(D, n);
    solution.merge(C, m, D, n);
    print_array(C, m + n);

    int E[8] = {1, 2, 4, 5, 6};
    m = 5;
    int F[1] = {3};
    n = 1;
    print_array(E, m);
    print_array(F, n);
    solution.merge(E, m, F, n);
    print_array(E, m + n);

    return 0;
}
