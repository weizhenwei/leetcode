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
 * File: 2011-03-27_Median_of_Two_Sorted_Arrays.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/media-of-two-sorted-arrays/
 * There are two sorted arrays A and B of size m and n respectively. Find the
 * median of the two sorted arrays. The overall run time complexity should be
 * O(log (m+n)).
 *
 *
 * Date: 2014.12.19
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <algorithm>

using std::max;
using std::min;

// originates from:https://oj.leetcode.com/discuss/14689/share-my-c-solution
class Solution_Median_of_Two_Sorted_Arrays {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (m > n) {
            return findMedianSortedArrays(B, n, A, m);
        }

        int i = m / 2;
        int j = n / 2;
        int k = 0;
        if (A[i] <= B[j]) {
            if (m % 2 == 0) {
                k = min(i - 1, n - j - 1);
            } else {
                k = min(i, n - j - 1);
            }
        } else {
            if (m % 2 == 0) {
                k = min(m - i - 1, j - 1);
            } else {
                k = min(m - i - 1, j);
            }
        }

        if (m == 0) {
            return (n % 2 == 0) ? (B[j-1] + B[j]) / 2.0 : B[j];
        }

        if (m == 1) {
            if (n == 1) {
                return (A[0] + B[0]) / 2.0;
            } else if (n % 2 == 0) {
                return medianOfThree(A[0], B[j-1], B[j]);
            } else {
                return medianOfFour(A[0], B[j-1], B[j], B[j+1]);
            }
        }

        if (m == 2) {
            if (n == 2) {
                return medianOfFour(A[0], A[1], B[0], B[1]);
            } else if (n % 2 == 0) {
                return medianOfFour(max(A[1],B[j-2]), B[j-1], B[j], min(A[0], B[j+1]));
            } else {
                return medianOfThree(max(A[1],B[j-1]), B[j], min(A[0], B[j+1]));
            }  
        }

        if (A[i] <= B[j]) {
            return findMedianSortedArrays(A+k, m-k, B, n-k);
        } else {
            return findMedianSortedArrays(A, m-k, B+k, n-k);
        }
    }

private:
    double medianOfThree(int a, int b, int c) {
        int maxI = max(max(a, b), c);
        int minI = min(min(a, b), c);
        return ( a + b + c - maxI - minI);
    }     
    double medianOfFour(int a, int b, int c, int d) {
        int maxI = max(max(max(a, b), c), d);
        int minI = min(min(min(a, b), c), d);
        return (a + b + c + d - maxI - minI) / 2.0;
    }
};

static void print_array(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Median_of_Two_Sorted_Arrays solution;
    int A[3] = {1, 3, 4};
    int B[5] = {1, 2, 3, 4, 5};
    int m = 3;
    int n = 5;

    print_array(A, m);
    print_array(B, n);
    double median = solution.findMedianSortedArrays(A, m, B, n);
    printf("median = %f\n", median);

    return 0;
}
