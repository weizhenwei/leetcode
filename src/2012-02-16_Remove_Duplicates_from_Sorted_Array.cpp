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
 * File: 2011-02-16_Remove_Duplicates_from_Sorted_Array.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
 * Given a sorted array, remove the duplicates in place such that each element
 * appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with
 * constant memory.
 *
 * For example,
 * Given input array A = [1,1,2],
 *
 * Your function should return length = 2, and A is now [1,2].
 *
 *
 * Date: 2014.10.21
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>

class Solution_Remove_Duplicates_from_Sorted_Array {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 1)
            return n;
        if (n == 2) {
            if (A[0] == A[1])
                return 1;
            else
                return 2;
        }

        int i = 0;
        int newn = n;
        int same = 0;
        int start = 0;
        for (i = 0; i < n - 1; i++) {
            if (A[i] == A[i + 1]) {
                same++;
            } else {
                start++;
                A[start] = A[i + 1];
                newn -= same;
                same = 0;
            }
        }
        if( same != 0) {
            start++;
            A[start] = A[i + 1];
            newn -= same;
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
    print_array(a, 13);
    n = solution.removeDuplicates(a, 13);
    print_array(a, n);

    int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_array(b, 10);
    n = solution.removeDuplicates(b, 10);
    print_array(b, n);

    int c[3] = {1, 1, 1};
    print_array(c, 3);
    n = solution.removeDuplicates(c, 3);
    print_array(c, n);

    return 0;
}
