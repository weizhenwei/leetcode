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
 * File: 128-Longest_Consecutive_Sequence.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/longest-consecutive-sequence/
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 *
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length:
 * 4.
 *
 * Your algorithm should run in O(n) complexity.
 *
 *
 * Date: 2015.01.27
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <algorithm>
#include <unordered_map>

using std::max;
using std::vector;
using std::unordered_map;

class Solution_Longest_Consecutive_Sequence {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> workset;

        for (int i = 0; i < num.size(); i++) {
            workset[num[i]] = false;
        }

        int longest = 0;
        for (int i = 0; i < num.size(); i++) {
            if (workset[num[i]] == true) {  // this avoid the worst O(n^2) case;
                continue;
            }

            workset[num[i]] = true;

            int prev = num[i] - 1;
            int next = num[i] + 1;
            bool p = false, n = false;
            while (workset.find(prev) != workset.end()) {
                workset[prev] = true;  // this avoid the worst O(n^2) case;
                prev--;
                p = true;
            }
            while (workset.find(next) != workset.end()) {
                workset[next] = true;  // this avoid the worst O(n^2) case;
                next++;
                n = true;
            }

            if (!p) {
                prev = num[i];
            } else {
                prev++;
            }
            if (!n) {
                next = num[i];
            } else {
                next--;
            }

            longest = max(longest, next - prev + 1);
        } // for

        return longest;
    }
};

int main(int argc, char *argv[]) {
    Solution_Longest_Consecutive_Sequence solution;
    vector<int> num;
    num.clear();
    num.push_back(100);
    num.push_back(1);
    num.push_back(100);
    num.push_back(2);
    num.push_back(4);
    num.push_back(3);
    int n = solution.longestConsecutive(num);
    printf("longest = %d\n", n);


    num.clear();
    num.push_back(1);
    num.push_back(6);
    num.push_back(2);
    num.push_back(7);
    num.push_back(8);
    num.push_back(9);
    num.push_back(3);
    num.push_back(4);
    num.push_back(10);
    n = solution.longestConsecutive(num);
    printf("longest = %d\n", n);
    return 0;
}

