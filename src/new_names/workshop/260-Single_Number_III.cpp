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
 * File: 260-Single_Number_III.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/single-number-iii/
 * Given an array of numbers nums, in which exactly two elements appear only once
 * and all the other elements appear exactly twice. Find the two elements that
 * appear only once.

 * For example:

 * Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

 * Note:
 * The order of the result is not important. So in the above example, [5, 3] is
 * also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement it
 * using only constant space complexity?
 *
 *
 * Date: 2015.09.21
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <map>
#include <vector>

using std::map;
using std::vector;

class Solution_Single_Number_III {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> results;
        map<int, int> sets;
        vector<int>::iterator iter;
        for (iter = nums.begin(); iter != nums.end(); iter++) {
            if (sets.find(*iter) == sets.end()) {
                sets[*iter] = 1;
            } else {
                sets[*iter] += 1;
            }
        }  // for

        map<int, int>::iterator iterr;
        for (iterr = sets.begin(); iterr != sets.end(); iterr++) {
            if (iterr->second == 1) {
                results.push_back(iterr->first);
            }
        }

        return results;
    }
};

static void printVector(vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Single_Number_III solution;
    int A[6] = {1, 2, 1, 3, 2, 5};
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(5);
    vector<int> results = solution.singleNumber(nums);;
    printVector(nums);
    printVector(results);

    nums.clear();
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(7);
    nums.push_back(1);
    nums.push_back(7);
    nums.push_back(5);
    results = solution.singleNumber(nums);;
    printVector(nums);
    printVector(results);

    return 0;
}

