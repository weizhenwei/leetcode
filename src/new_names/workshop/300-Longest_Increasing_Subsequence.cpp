/*
 *
 * Copyright (c) 2015, weizhenwei
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
 * File: 300-Longest_Increasing_Subsequence.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/longest-increasing-subsequence/
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.

 * For example,
 * Given [10, 9, 2, 5, 3, 7, 101, 18],
 * The longest increasing subsequence is [2, 3, 7, 101], therefore the length is
 * 4. Note that there may be more than one LIS combination, it is only necessary
 * for you to return the length.

 * Your algorithm should run in O(n2) complexity.

 * Follow up: Could you improve it to O(n log n) time complexity?
 *
 *
 * Date: 2015.11.07
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <algorithm>
#include <vector>

using std::max;
using std::min;
using std::vector;

class Solution_Longest_Increasing_Subsequence {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 0)
            return 0;

        int maxLength = 1;
        vector<int> vLength = vector<int>(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    vLength[i] = max(vLength[i], vLength[j] + 1);
                }
            }  // for j
            maxLength = max(maxLength, vLength[i]);
        }  // for i

        return maxLength;
    }
};

static void printVector(const vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

static void testcase() {
    Solution_Longest_Increasing_Subsequence solution;

    // [10, 9, 2, 5, 3, 7, 101, 18],
    vector<int> nums;
    nums.push_back(10);
    nums.push_back(9);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(7);
    nums.push_back(101);
    nums.push_back(18);
    printVector(nums);
    int length = solution.lengthOfLIS(nums);
    printf("lengthOfLIS = %d\n", length);

    nums.clear();
    nums.push_back(10);
    nums.push_back(9);
    nums.push_back(8);
    nums.push_back(7);
    nums.push_back(6);
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    printVector(nums);
    length = solution.lengthOfLIS(nums);
    printf("lengthOfLIS = %d\n", length);

    nums.clear();
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(9);
    nums.push_back(10);
    printVector(nums);
    length = solution.lengthOfLIS(nums);
    printf("lengthOfLIS = %d\n", length);

    nums.clear();
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(9);
    nums.push_back(4);
    nums.push_back(10);
    nums.push_back(5);
    nums.push_back(6);
    printVector(nums);
    length = solution.lengthOfLIS(nums);
    printf("lengthOfLIS = %d\n", length);
}

int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

