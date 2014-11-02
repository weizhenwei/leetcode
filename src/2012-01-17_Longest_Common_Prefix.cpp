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
 * File: 2012-01-17_Longest_Common_Prefix.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/longest-common-prefix/
 * Write a function to find the longest common prefix string amongst an array of
 * strings.
 *
 *
 * Date: 2014.11.02
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <limits.h>
#include <stdio.h>
#include <string>
#include <set>
#include <vector>

using std::set;
using std::string;
using std::vector;

class Solution_Longest_Common_Prefix {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) {
            return string("");
        }

        if (strs.size() == 1) {
            return strs[0];
        }

        int i = 0;
        int minLength = INT_MAX;
        for (i = 0; i < strs.size(); i++) {
            if (strs[i].size() < minLength)
                minLength = strs[i].size();
        }

        string result;
        set<char> charset;
        result.clear();
        for (i = 0; i < minLength; i++) {
            int j = 0;
            string first = strs[0];
            charset.clear();
            charset.insert(charset.begin(), first[i]);
            for (j = 1; j < strs.size(); j++) {
                string tmp = strs[j];
                if (charset.find(tmp[i]) == charset.end()) {
                    return result;
                }
            }

            result.insert(result.begin() + result.size(), first[i]);
        }

        return result;
    }
};

static void print_strings(vector<string> &strs) {
    vector<string>::iterator iter;
    for (iter = strs.begin(); iter != strs.end(); iter++) {
        printf("%s\n", (*iter).c_str());
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Longest_Common_Prefix solution;
    vector<string> strs;
    string result;

    strs.push_back("hello");
    strs.push_back("helo");
    strs.push_back("hehehe");
    strs.push_back("helol");
    result = solution.longestCommonPrefix(strs);
    print_strings(strs);
    printf("Longest Common Prefix:%s\n", result.c_str());

    strs.clear();
    strs.push_back("hello");
    result = solution.longestCommonPrefix(strs);
    print_strings(strs);
    printf("Longest Common Prefix:%s\n", result.c_str());

    strs.clear();
    strs.push_back("c");
    strs.push_back("c");
    result = solution.longestCommonPrefix(strs);
    print_strings(strs);
    printf("Longest Common Prefix:%s\n", result.c_str());


    return 0;
}
