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
 * File: 219-Contains_Duplicate_II.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/contains-duplicate-ii/
 * Given an array of integers and an integer k, find out whether there are two
 * distinct indices i and j in the array such that nums[i] = nums[j] and the
 * difference between i and j is at most k.
 *
 *
 * Date: 2015.09.23
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <map>
#include <vector>

using std::map;
using std::pair;
using std::vector;

class Solution_Contains_Duplicate_II {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() < 2) {
            return false;
        }
        
        map<int, int> uniqueMap;
        for (int i = 0; i < nums.size(); i++) {
            map<int, int>::iterator miter;
            if ((miter = uniqueMap.find(nums[i])) != uniqueMap.end()) {
                if (i - miter->second <= k) {
                    return true;
                } else {
                    miter->second = i;
                }
            } else {
                uniqueMap.insert(pair<int, int>(nums[i], i));
            }
        }

        return false;
    }
};

void printVector(const vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void testcase() {
    Solution_Contains_Duplicate_II solution;
    vector<int> nums;
    bool is;

    nums.clear();
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    is = solution.containsNearbyDuplicate(nums, 1);
    printVector(nums);
    printf("contains duplicate:%d\n", is);

    nums.clear();
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(5);
    is = solution.containsNearbyDuplicate(nums, 1);
    printVector(nums);
    printf("contains duplicate:%d\n", is);

    nums.clear();
    nums.push_back(-1);
    nums.push_back(-1);
    is = solution.containsNearbyDuplicate(nums, 1);
    printVector(nums);
    printf("contains duplicate:%d\n", is);

    nums.clear();
    nums.push_back(-1);
    nums.push_back(-2);
    nums.push_back(-3);
    nums.push_back(-1);
    nums.push_back(-1);
    is = solution.containsNearbyDuplicate(nums, 1);
    printVector(nums);
    printf("contains duplicate:%d\n", is);
}

int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

