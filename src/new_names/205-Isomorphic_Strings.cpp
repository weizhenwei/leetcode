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
 * File: 205-Isomorphic_Strings.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/isomorphic-strings/
 * Given two strings s and t, determine if they are isomorphic.

 * Two strings are isomorphic if the characters in s can be replaced to get t.

 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.

 * For example,
 * Given "egg", "add", return true.

 * Given "foo", "bar", return false.

 * Given "paper", "title", return true.

 * Note:
 * You may assume both s and t have the same length.
 *
 *
 * Date: 2015.09.27
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <string>
#include <map>

using std::pair;
using std::string;
using std::map;

class Solution_Isomorphic_Strings {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        map<int, int> sMap, tMap;
        for (int i = 0; i < s.size(); i++) {
            if (sMap.find(s[i]) != sMap.end()) {
                int tt = sMap[s[i]];
                if (t[i] != tt) {
                    return false;
                }
            } else {
                sMap.insert(pair<int, int>(s[i], t[i]));
            }
        }
        for (int i = 0; i < t.size(); i++) {
            if (tMap.find(t[i]) != tMap.end()) {
                int ss = tMap[t[i]];
                if (s[i] != ss) {
                    return false;
                }
            } else {
                tMap.insert(pair<int, int>(t[i], s[i]));
            }
        }

        return true;
    }
};

void testcase() {
    Solution_Isomorphic_Strings solution;
    string s = "egg";
    string t = "add";
    bool bIsomorphic = solution.isIsomorphic(s, t);  
    printf("s = %s, t = %s, isIsomorphic = %d\n",
            s.c_str(), t.c_str(), bIsomorphic);

    s = "foo";
    t = "bar";
    bIsomorphic = solution.isIsomorphic(s, t);  
    printf("s = %s, t = %s, isIsomorphic = %d\n",
            s.c_str(), t.c_str(), bIsomorphic);

    s = "paper";
    t = "title";
    bIsomorphic = solution.isIsomorphic(s, t);  
    printf("s = %s, t = %s, isIsomorphic = %d\n",
            s.c_str(), t.c_str(), bIsomorphic);

    s = "good";
    t = "deem";
    bIsomorphic = solution.isIsomorphic(s, t);  
    printf("s = %s, t = %s, isIsomorphic = %d\n",
            s.c_str(), t.c_str(), bIsomorphic);
}

int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

