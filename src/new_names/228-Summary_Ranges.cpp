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
 * File: 228-Summary_Ranges.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/summary-ranges/
 * Given a sorted integer array without duplicates, return the summary of its
 * ranges.

 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 *
 *
 * Date: 2015.09.23
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::ostringstream;
using std::vector;

class Solution_Summary_Ranges {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.size() == 0) {
            return result;
        }

        int i = 0;
        int start = nums[i];
        int end = nums[i];
        while (i < nums.size() - 1) {
            if (nums[i+1] == end + 1) {
                end++;
                i++;
            } else {
                if (start == end) {
                    ostringstream ostr;
                    ostr << start;
                    result.push_back(ostr.str());

                    i++;
                    start = end = nums[i];
                } else {
                    ostringstream ostr;
                    ostr << start << "->" << end;
                    result.push_back(ostr.str());

                    i++;
                    start = end = nums[i];
                }
            }
        }  // while

        if (start == end) {
            ostringstream ostr;
            ostr << start;
            result.push_back(ostr.str());
        } else {
            ostringstream ostr;
            ostr << start << "->" << end;
            result.push_back(ostr.str());
        }

        return result;
    }
};

static void printInterger(const vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++) {
        printf("%d, ", nums[i]);
    }
    printf("\n");
}

static void printString(const vector<string> &nums)
{
    for (int i = 0; i < nums.size(); i++) {
        printf("%s, ", nums[i].c_str());
    }
    printf("\n");
}

static void testcase() {
    Solution_Summary_Ranges solution;
    vector<int> nums;
    vector<string> ranges;

    nums.clear();
    ranges = solution.summaryRanges(nums);
    printInterger(nums);
    printString(ranges);

    nums.clear();
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    ranges = solution.summaryRanges(nums);
    printInterger(nums);
    printString(ranges);

    nums.clear();
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    ranges = solution.summaryRanges(nums);
    printInterger(nums);
    printString(ranges);

    nums.clear();
    nums.push_back(1);
    ranges = solution.summaryRanges(nums);
    printInterger(nums);
    printString(ranges);

    nums.clear();
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    ranges = solution.summaryRanges(nums);
    printInterger(nums);
    printString(ranges);
}

int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

