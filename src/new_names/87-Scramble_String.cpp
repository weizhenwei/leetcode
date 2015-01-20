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
 * File: 87-Scramble_String.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/scramble-string/
 * Given a string s1, we may represent it as a binary tree by partitioning it to
 * two non-empty substrings recursively.
 * Given two strings s1 and s2 of the same length, determine if s2 is a
 * scrambled string of s1.
 *
 *
 * Date: 2015.01.20
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution_Scramble_String {
private:
    unordered_map<string, bool> map;

public:
    bool isScramble(string s1, string s2) {
        const int n = s1.size();
        if (n != s2.size()) {
            return false;
        }
        if (n == 1) {
            return s1[0] == s2[0];
        }

        bool comp = false;
        if (map.count(s1 + s2) > 0) {
            comp = map[s1+s2];
        } else {
            int hist1[128] = {0};
            int hist2[128] = {0};
            for (int i = 0; i < n; i++) {
                hist1[s1[i]]++;
                hist2[s2[i]]++;
            }
            comp = true;
            for (int i = 0; i < 128; i++) {
                if (hist1[i] != hist2[i]) {
                    comp = false;
                    break;
                }
            }  // for
            if (comp) {
                for (int i = 1; i < n; i++) {
                    comp = isScramble(s1.substr(0, i), s2.substr(n - i, i));
                    comp = comp && isScramble(s1.substr(i), s2.substr(0, n - i));
                    bool comp1 = isScramble(s1.substr(0, i), s2.substr(0, i));
                    comp1 =  comp1 && isScramble(s1.substr(i), s2.substr(i));
                    comp = comp || comp1;
                    if (comp) {
                        break;
                    }
                }  // for
            }  // if

            map[s1+s2] = comp;
            map[s2+s1] = comp;
        }

        return comp;
    }
};

int main(int argc, char *argv[]) {
    Solution_Scramble_String solution;
    string s1 = "great";
    string s2 = "rgeat";
    bool is = solution.isScramble(s1, s2);
    printf("s1 = %s, s2 = %s, isScramble = %d\n", s1.c_str(), s2.c_str(), is);

    return 0;
}

