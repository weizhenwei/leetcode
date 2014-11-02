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
 * File: 2012-03-02_Search_for_a_Range.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/search-for-a-range/
 * Given a sorted array of integers, find the starting and ending position of a
 * given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 *
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
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

class Solution_Search_for_a_Range {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result;
        if (n == 0) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        if (n == 1) {
            if (A[0] == target) {
                result.push_back(0);
                result.push_back(0);
                return result;
            } else {
                result.push_back(-1);
                result.push_back(-1);
                return result;
            }
        }

        int left, right, middle;
        left = 0;
        right = n - 1;
        middle = (left + right) / 2;
        while (left <= right) {  // binary search!
            if (A[middle] == target) {
                int start = middle - 1;
                int end = middle + 1;
                while (start >= 0  && A[start] == target) {
                    start--;
                }
                start++;
                while (end < n  && A[end] == target) {
                    end++;
                }
                end--;

                result.push_back(start);
                result.push_back(end);
                return result;
            }

            if (A[middle] < target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
            middle = (left + right) / 2;
        }  // while

        assert(left >= right);
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
};

static void print_array(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

static void print_vector(vector<int> v) {
    printf("[");
    vector<int>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
        printf("%d ", *iter);
    }
    printf("]\n");

}

int main(int argc, char *argv[]) {
    Solution_Search_for_a_Range solution;
    int A[6] = {5, 7, 7, 8, 8, 10};
    int target = 7;
    int n = 6;
    vector<int> result = solution.searchRange(A, n, target); 
    print_array(A, n);
    printf("target = %d, result = ", target);
    print_vector(result);

    target = 5;
    result = solution.searchRange(A, n, target);
    printf("target = %d, result = ", target);
    print_vector(result);

    target = 7;
    result = solution.searchRange(A, n, target);
    printf("target = %d, result = ", target);
    print_vector(result);

    target = 8;
    result = solution.searchRange(A, n, target);
    printf("target = %d, result = ", target);
    print_vector(result);

    target = 10;
    result = solution.searchRange(A, n, target);
    printf("target = %d, result = ", target);
    print_vector(result);

    target = 100;
    result = solution.searchRange(A, n, target);
    printf("target = %d, result = ", target);
    print_vector(result);

    target = -100;
    result = solution.searchRange(A, n, target);
    printf("target = %d, result = ", target);
    print_vector(result);

    return 0;
}

