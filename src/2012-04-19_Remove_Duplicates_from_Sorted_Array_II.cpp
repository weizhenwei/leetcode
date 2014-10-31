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
 * File: 2012-04-19_Remove_Duplicates_from_Sorted_Array_II.cpp
 *
 *
 * Brief:
 * https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 * For example,
 * Given sorted array A = [1,1,1,2,2,3],
 *
 * Your function should return length = 5, and A is now [1,1,2,2,3].
 *
 *
 * Date: 2014.10.30
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>

class Solution_Remove_Duplicates_from_Sorted_Array {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2)
            return n;

        int i = 0;
        int newn = n;
        int same = 0;
        int start = 0;
        int begin = 0;
        for (i = 0; i < n - 1; i++) {
            if (A[i] == A[i + 1]) {
                if (begin == 0) {
                    begin = 1;
                    start++;
                    A[start] = A[i+1];
                } else {
                    same++;
                }
            } else {
                if (begin == 1) {
                    begin = 0;
                    start++;
                    A[start] = A[i + 1];
                    newn -= same;
                    same = 0;
                } else {
                    start++;
                    A[start] = A[i+1];
                }
            }
        }
        if( same != 0) {
            start++;
            A[start] = A[i + 1];
            newn -= same;
        } else {
            if (begin == 1) {
                A[start] = A[i-1];
            }
        }

        return newn;
    }
};

void print_array(int A[], int n) {
    int i = 0;
    printf("n = %d\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Remove_Duplicates_from_Sorted_Array solution;

    int n = 0;
    int a[13] = {1, 1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 5, 6};
    printf("Before:\n");
    print_array(a, 13);
    n = solution.removeDuplicates(a, 13);
    printf("After:\n");
    print_array(a, n);

    int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Before:\n");
    print_array(b, 10);
    n = solution.removeDuplicates(b, 10);
    printf("After:\n");
    print_array(b, n);

    int c[3] = {1, 1, 1};
    printf("Before:\n");
    print_array(c, 3);
    n = solution.removeDuplicates(c, 3);
    printf("After:\n");
    print_array(c, n);

    int d[9] = {1, 2, 2, 2, 2, 2, 2, 2, 2};
    printf("Before:\n");
    print_array(d, 9);
    n = solution.removeDuplicates(d, 9);
    printf("After:\n");
    print_array(d, n);

    int e[11] = {1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2};
    printf("Before:\n");
    print_array(e, 11);
    n = solution.removeDuplicates(e, 11);
    printf("After:\n");
    print_array(e, n);

    int f[10] = {1, 1, 2, 2, 2, 2, 2, 2, 2, 2};
    printf("Before:\n");
    print_array(f, 10);
    n = solution.removeDuplicates(f, 10);
    printf("After:\n");
    print_array(f, n);

    int g[4] = {1, 1, 1, 2};
    printf("Before:\n");
    print_array(g, 4);
    n = solution.removeDuplicates(g, 4);
    printf("After:\n");
    print_array(g, n);

    int h[5] = {1, 1, 1, 2, 2};
    printf("Before:\n");
    print_array(h, 5);
    n = solution.removeDuplicates(h, 5);
    printf("After:\n");
    print_array(h, n);

    int i[6] = {1, 1, 1, 1, 3, 3};
    printf("Before:\n");
    print_array(i, 6);
    n = solution.removeDuplicates(i, 6);
    printf("After:\n");
    print_array(i, n);

    int j[7] = {1, 1, 1, 1, 2, 2, 3};
    printf("Before:\n");
    print_array(j, 7);
    n = solution.removeDuplicates(j, 7);
    printf("After:\n");
    print_array(j, n);

    int k[5] = {1, 1, 1, 2, 3};
    printf("Before:\n");
    print_array(k, 5);
    n = solution.removeDuplicates(k, 5);
    printf("After:\n");
    print_array(k, n);

    return 0;
}
