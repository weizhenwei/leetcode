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
 * File: 2012-04-08_Sort_Colors.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/sort-colors/
 * Given an array with n objects colored red, white or blue, sort them so that
 * objects of the same color are adjacent, with the colors in the order red,
 * white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white,
 * and blue respectively.
 *
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 *
 * Follow up:
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then overwrite
 * array with total number of 0's, then 1's and followed by 2's.
 *
 * Could you come up with an one-pass algorithm using only constant space?
 *
 *
 * Date: 2014.11.20
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <algorithm>

using std::swap;

class Solution_Sort_Colors {
public:
    void sortColors(int A[], int n) {
        if (n <= 1)
            return;

        int zero = 0;
        int nonzero = 0;
        while (zero < n && nonzero < n) {
            while (A[zero] != 0 && zero < n) {
                zero++;
            }
            if (zero == n) {
                break;
            }
            while (A[nonzero] == 0 && nonzero < n) {
                nonzero++;
            }
            if (nonzero == n) {
                break;
            }

            if (zero > nonzero) {
                swap(A[zero], A[nonzero]);
                zero++;
                nonzero++;
            } else {
                zero++;
            }
        }

        if (zero == n) {  // scan 0 complete;
            int one = nonzero;
            int two = nonzero;
            while (one < n && two < n) {
                while (A[one] != 1 && one < n) {
                    one++;
                }
                if (one == n) {
                    break;
                }
                while (A[two] == 1 && two < n) {
                    two++;
                }
                if (nonzero == n) {
                    break;
                }

                if (one > two) {
                    swap(A[one], A[two]);
                    one++;
                    two++;
                } else {
                    one++;
                }
            }
        } else if (nonzero == n) {  // no 1 and 2, just return;
            return;
        }
    }
};

static void print_array(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Sort_Colors solution;
    int A[7] = {0, 1, 2, 0, 2, 2, 1};
    int n = 7;
    print_array(A, n);
    solution.sortColors(A, n);
    print_array(A, n);

    int B[7] = {0, 1, 1, 0, 0, 0, 1};
    n = 7;
    print_array(B, n);
    solution.sortColors(B, n);
    print_array(B, n);

    int C[7] = {0, 2, 2, 2, 0, 0, 0};
    n = 7;
    print_array(C, n);
    solution.sortColors(C, n);
    print_array(C, n);

    int D[7] = {1, 2, 1, 2, 1, 1, 2};
    n = 7;
    print_array(D, n);
    solution.sortColors(D, n);
    print_array(D, n);

    return 0;
}

