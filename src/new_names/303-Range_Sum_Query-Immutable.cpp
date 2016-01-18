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
 * File: 303-Range_Sum_Query-Immutable.cpp
 *
 * Brief: https://oj.leetcode.com/problems/range-sum-query-immutable/
 * Given an integer array nums, find the sum of the elements between indices i and
 * j (i ≤ j), inclusive.

 * Example:
 * Given nums = [-2, 0, 3, -5, 2, -1]

 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * Note:
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 *
 *
 * Date: 2015.11.12
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <vector>

using std::vector;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        if (nums.size() <= 0) {
            m_iSums = vector<long int>(0, 0);
        } else {
            m_iSums = vector<long int>(nums.size(), 0);
            m_iSums[0] = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                m_iSums[i] = m_iSums[i-1] + nums[i];
            }
        }
    }

    int sumRange(int i, int j) {
        if ((i < 0) || (j >= m_iSums.size()) || (i > j)) {
            return 0;
        }

        if (i == 0) {
            return m_iSums[j];
        } else {
            return m_iSums[j] - m_iSums[i-1];
        }
    }

private:
    vector<long int> m_iSums;
};

void testcase() {
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(-5);
    nums.push_back(2);
    nums.push_back(-1);
    NumArray array = NumArray(nums);

    int i = 0, j = 2;
    printf("sumRange(%d, %d) = %d\n", i, j , array.sumRange(i, j)); 
    i = 2, j = 5;
    printf("sumRange(%d, %d) = %d\n", i, j , array.sumRange(i, j)); 
    i = 0, j = 5;
    printf("sumRange(%d, %d) = %d\n", i, j , array.sumRange(i, j)); 
}

int main(int argc, char *argv[]) {
    testcase();

    return 0;
}
