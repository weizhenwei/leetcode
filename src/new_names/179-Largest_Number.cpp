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
 * File: 179-Largest_Number.cpp
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 *
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 *
 * Note: The result may be very large, so you need to return a string instead of
 * an integer.
 *
 *
 * Date: 2015.01.14
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

using std::to_string;
using std::string;
using std::vector;
using std::sort;

// originates from:
// https://oj.leetcode.com/discuss/21681/its-my-c-solution-please-feel-free-to-comment
class Solution_Largest_Number {
public:
    string largestNumber(vector<int> &num) {
        vector<string> strings;
        for (int i = 0; i < num.size(); i++) {
            strings.push_back(to_string(num[i]));
        }

        sort(strings.begin(), strings.end(), [](string a, string b) {
                return (b + a) < (a + b);
                });

        string maxString;
        int i = 0;
        while (i < strings.size() && strings[i] == "0") {
            i++;
        }

        while (i < strings.size()) {
            maxString += strings[i++];
        }

        if (maxString.size() > 0) {
            return maxString;
        } else {
            return "0";
        }
    }
};

int main(int argc, char *argv[]) {
    Solution_Largest_Number solution;
    vector<int> num;
    num.push_back(3);
    num.push_back(30);
    num.push_back(34);
    num.push_back(5);
    num.push_back(9);

    string str = solution.largestNumber(num);
    printf("largest number = %s\n", str.c_str());

    return 0;
}

