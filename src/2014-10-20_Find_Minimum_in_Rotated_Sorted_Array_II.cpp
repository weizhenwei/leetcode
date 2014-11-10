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
 * File: 2014-10-12_Find_Minimum_in_Rotated_Sorted_Array_II.cpp
 *
 *
 * Brief: * https://oj.leetcode.com/problems/fine-minimum-in-rotated-sorted-array_ii/
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Find the minimum element.
 *
 * You may assume no duplicate exists in the array.
 *
 * Follow up for "Find Minimum in Rotated Sorted Array":
 * What if duplicates are allowed?
 *
 * Would this affect the run-time complexity? How and why?
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Find the minimum element.
 *
 * The array may contain duplicates.
 *
 *
 * Date: 2014.11.10
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <vector>

using std::vector;

class Solution_Find_Minimum_in_Rotated_Sorted_Array {
public:
    int findMin(vector<int> &num) {
        if (num.size() == 1) {
            return num[0];
        }


        int left = 0;
        int right = num.size() - 1;
        int middle = (left + right) / 2;
        int candidate = INT_MAX;
        while (left < right) {
            while (left < num.size() - 1 && num[left] == num[left+1]) {
                left++;
            }
            while (right > 0 && num[right] == num[right-1]) {
                right--;
            }
            middle = (left + right) / 2;

            if (num[left] < candidate) {
                candidate = num[left];
            }
            if (num[middle] < candidate) {
                candidate = num[middle];
            }
            if (num[right] < candidate) {
                candidate = num[right];
            }


            if (num[left] <= num[middle]) {  // left is sorted bigger;
                if (num[middle] <= num[right]) {  // right is sorted bigger;
                    return candidate;
                } else {
                    left = middle + 1;
                }
            } else {  // A[left] > A[middle];
                if (num[middle] < num[right]) {  // right is sorted bigger;
                    right = middle - 1;
                } else {  // left > middle > right;
                    return candidate;
                }
            }
        }  // while

        return candidate;
    }
};


static void print_vector(vector<int> num) {
    printf("Array is:\n");
    for (int i = 0; i < num.size(); i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Find_Minimum_in_Rotated_Sorted_Array solution;

    vector<int> num;
    num.push_back(5);
    num.push_back(5);
    num.push_back(5);
    num.push_back(6);
    num.push_back(8);
    num.push_back(8);
    num.push_back(9);
    num.push_back(9);
    num.push_back(1);
    num.push_back(1);
    num.push_back(3);
    num.push_back(3);
    num.push_back(4);
    int min = solution.findMin(num);
    print_vector(num);
    printf("minimum = %d\n", min);

    num.clear();
    num.push_back(3);
    num.push_back(3);
    num.push_back(1);
    num.push_back(3);
    min = solution.findMin(num);
    print_vector(num);
    printf("minimum = %d\n", min);

    num.clear();
    num.push_back(5);
    num.push_back(6);
    num.push_back(8);
    num.push_back(9);
    num.push_back(1);
    num.push_back(1);
    num.push_back(1);
    num.push_back(1);
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
    min = solution.findMin(num);
    print_vector(num);
    printf("minimum = %d\n", min);

    num.clear();
    num.push_back(9);
    num.push_back(8);
    num.push_back(8);
    num.push_back(8);
    num.push_back(8);
    num.push_back(8);
    num.push_back(6);
    num.push_back(5);
    num.push_back(5);
    num.push_back(5);
    num.push_back(5);
    num.push_back(5);
    num.push_back(4);
    min = solution.findMin(num);
    print_vector(num);
    printf("minimum = %d\n", min);

    num.clear();
    num.push_back(4);
    num.push_back(5);
    num.push_back(6);
    num.push_back(8);
    num.push_back(4);
    num.push_back(4);
    num.push_back(4);
    num.push_back(4);
    min = solution.findMin(num);
    print_vector(num);
    printf("minimum = %d\n", min);

    num.clear();
    num.push_back(4);
    num.push_back(5);
    min = solution.findMin(num);
    print_vector(num);
    printf("minimum = %d\n", min);

    num.clear();
    num.push_back(5);
    num.push_back(4);
    min = solution.findMin(num);
    print_vector(num);
    printf("minimum = %d\n", min);

    num.clear();
    num.push_back(5);
    min = solution.findMin(num);
    print_vector(num);
    printf("minimum = %d\n", min);

    return 0;
}
