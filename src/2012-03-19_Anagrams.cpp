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
 * File: 2012-03-19_Anagrams.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/anagrams/
 * Given an array of strings, return all groups of strings that are anagrams.
 *
 * Note: All inputs will be in lower-case.
 *
 *
 * Date: 2014.12.04
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using std::sort;
using std::string;
using std::vector;
using std::unordered_map;

class Solution_Anagrams {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        if (strs.size() < 2)
            return result;

        unordered_map<string, int> cache;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            unordered_map<string, int>::iterator it = cache.find(s);
            // auto it = cache.find(s);
            if (it == cache.end()) {
                cache[s] = i;
            } else {
                result.push_back(strs[i]);
                if (it->second >= 0) {
                    result.push_back(strs[it->second]);
                    it->second = -1;
                }
            }
        }

        return result;
    }
};

static void print_strings(vector<string> &strs) {
    for (int i = 0; i < strs.size(); i++) {
        printf("%s\n", strs[i].c_str());
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Anagrams solution;
    vector<string> strs;
    strs.push_back("hello");
    strs.push_back("world");
    strs.push_back("and");
    strs.push_back("cpp");
    strs.push_back("adn");
    strs.push_back("wordl");
    strs.push_back("ppc");
    print_strings(strs);
    vector<string> result = solution.anagrams(strs);
    print_strings(result);

    return 0;
}

