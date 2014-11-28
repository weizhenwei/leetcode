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
 * File: 2012-03-10_Trapping_Rain_Water.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/trapping-rain-water/
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 *
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 *
 *
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In
 * this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 *
 *
 * Date: 2014.11.27
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <algorithm>
#include <stdio.h>

using std::min;

class Solution_Trapping_Rain_Water {
public:
    int trap(int A[], int n) {
        if (n < 3) {
            return 0;
        }

        int total = 0;

        int start = 0;
        int current = start + 1;
        while (start < n) {
            while (start < n - 1 && A[start] < A[start+1]) {
                start++;
            }
            
            current = start + 1;
            int max = 0;
            int maxidx = current;
            while (current < n && A[current] < A[start]) {
                if (max < A[current]) {
                    max = A[current];
                    maxidx = current;
                }
                current++;
            }

            if (current == n) {
                if (max > 0 && maxidx < n) {
                    int small = min(A[start], A[maxidx]);
                    for (int i = start + 1; i < maxidx; i++) {
                        total += (small - A[i]);
                    }
                    start = maxidx;
                } else {
                    start++;
                }
            } else {
                int small = min(A[current], A[start]);
                for (int i = start + 1; i < current; i++) {
                    total += (small - A[i]);
                }
                start = current;
            }
        }  // while

        return total;
    }
};

static void print_array(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Trapping_Rain_Water solution;
    int A[12] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = 12;
    int total = solution.trap(A, n);
    print_array(A, n);
    printf("total = %d\n", total);

    A[0] = 4;
    A[1] = 2;
    A[2] = 3;
    n = 3;
    total = solution.trap(A, n);
    print_array(A, n);
    printf("total = %d\n", total);

    return 0;
}

