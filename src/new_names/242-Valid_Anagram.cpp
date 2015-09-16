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
 * File: 242-Valid_Anagram.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/valid-anagram/
 * Given two strings s and t, write a function to determine if t is an anagram
 * of s.
 *
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 *
 * Note:
 * You may assume the string contains only lowercase alphabets.
 *
 *
 * Date: 2015.09.16
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>

#include <string>
#include <map>

using std::string;
using std::map;
using std::pair;

class Solution_Valid_Anagram {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        if (s.size() == 0) {
            return true;
        }

        map<char,int> mapContainer;
        map<char, int>::iterator iter;
        for (int i = 0; i < s.size(); i++) {
            if ((iter = mapContainer.find(s[i])) == mapContainer.end()) {
                mapContainer.insert(pair<char, int>(s[i], 1));
            } else {
                iter->second = iter->second + 1;
            }
        }

        for (int i = 0; i < t.size(); i++) {
            if ((iter = mapContainer.find(t[i])) == mapContainer.end()) {
                return false;
            } else {
                if (iter->second <= 0) {
                    return false;
                } else {
                    iter->second = iter->second - 1;
                }
            }
        }
        return true;
    }


};

void testcase() {
    Solution_Valid_Anagram solution;
    string s = "good";
    string t = "dogo";
    bool is = solution.isAnagram(s, t);
    printf("s = %s, t = %s, isAnagram:%d\n", s.c_str(), t.c_str(), is);

    s = "s";
    t = "t";
    is = solution.isAnagram(s, t);
    printf("s = %s, t = %s, isAnagram:%d\n", s.c_str(), t.c_str(), is);

    s = "is";
    t = "st";
    is = solution.isAnagram(s, t);
    printf("s = %s, t = %s, isAnagram:%d\n", s.c_str(), t.c_str(), is);

    s = "iis";
    t = "ssi";
    is = solution.isAnagram(s, t);
    printf("s = %s, t = %s, isAnagram:%d\n", s.c_str(), t.c_str(), is);
}

int main(int argc, char *argv[]) {
    testcase();

    return 0;
}
