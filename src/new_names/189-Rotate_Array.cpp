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
 * File: 189-Rotate_Array.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/rotate-array/
 * Rotate an array of n elements to the right by k steps.
 *
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to
 * [5,6,7,1,2,3,4].
 *
 *
 * Date: 2015.01.21
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <algorithm>
#include <stdio.h>

using std::swap;

class Solution_Rotate_Array {
public:
    void rotate(int nums[], int n, int k) {
        k = k % n;
        int left = 0;
        int right = n - k - 1;
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }

        left = n - k;
        right = n - 1;
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }


        left = 0;
        right = n - 1;
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution_Rotate_Array solution;
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    solution.rotate(nums, 7, 3);
    for (int i = 0; i < 7; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    int nums2[] = {1, 2, 3, 4, 5, 6, 7};
    solution.rotate(nums2, 7, 0);
    for (int i = 0; i < 7; i++) {
        printf("%d ", nums2[i]);
    }
    printf("\n");

    int nums3[] = {1, 2, 3, 4, 5, 6, 7};
    solution.rotate(nums3, 7, 1);
    for (int i = 0; i < 7; i++) {
        printf("%d ", nums3[i]);
    }
    printf("\n");

    int nums4[] = {1, 2, 3, 4, 5, 6, 7};
    solution.rotate(nums4, 7, 6);
    for (int i = 0; i < 7; i++) {
        printf("%d ", nums4[i]);
    }
    printf("\n");

    int nums5[] = {1, 2, 3, 4, 5, 6, 7};
    solution.rotate(nums5, 7, 7);
    for (int i = 0; i < 7; i++) {
        printf("%d ", nums5[i]);
    }
    printf("\n");

    return 0;
}

