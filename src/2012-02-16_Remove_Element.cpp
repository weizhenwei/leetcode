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
 * File: 2011-02-16_Remove_Element.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/remove-element/
 * Given an array and a value, remove all instances of that value in place and
 * return the new length.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond
 * the new length.
 *
 *
 * Date: 2014.10.24
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>

class Solution_Remove_Element {
public:
    int removeElement(int A[], int n, int elem) {
        if (n == 1 && A[0] == elem)
            return 0;

        int i = 0;
        int newn = n;
        int same = 0;
        int start = 0;
        for (i = 0; i < n; i++) {
            if (A[i] == elem) {
                same++;
            } else {
                A[start] = A[i];
                newn -= same;
                same = 0;
                start++;
            }
        }
        if( same != 0) {
            A[start] = A[i];
            newn -= same;
            start++;
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
    Solution_Remove_Element solution;

    int n = 0;
    int a[13] = {1, 1, 2, 2, 2, 3, 2, 2, 4, 5, 2, 2, 2};
    print_array(a, 13);
    n = solution.removeElement(a, 13, 2);
    print_array(a, n);

    int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_array(b, 10);
    n = solution.removeElement(b, 10, 3);
    print_array(b, n);

    int c[3] = {1, 1, 1};
    print_array(c, 3);
    n = solution.removeElement(c, 3, 1);
    print_array(c, n);

    int d[4] = {3, 1, 1, 1};
    print_array(d, 4);
    n = solution.removeElement(d, 4, 1);
    print_array(d, n);

    int e[4] = {1, 1, 1, 3};
    print_array(e, 4);
    n = solution.removeElement(e, 4, 1);
    print_array(e, n);

    return 0;
}
