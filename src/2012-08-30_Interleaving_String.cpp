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
 * File: 2012-08-30_Interleaving_String.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/interleaving-string/
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 *
 * For example,
 * Given:
 * s1 = "aabcc",
 * s2 = "dbbca",
 *
 * When s3 = "aadbbcbcac", return true.
 * When s3 = "aadbbbaccc", return false.
 *
 *
 * Date: 2014.12.11
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <string>

using std::string;

// DP solution originates from:
//https://oj.leetcode.com/discuss/11694/my-dp-solution-in-c
class Solution_Interleaving_String {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) {
            return false;
        }

        bool table[s1.size()+1][s2.size()+1];
        for (int i = 0; i < s1.size() + 1; i++) {
            for (int j = 0; j < s2.size() + 1; j++) {
                if (i == 0 && j == 0) {
                    table[i][j] = true;
                } else if (i == 0) {
                    table[i][j] = (table[i][j-1] && s2[j-1] == s3[i+j-1]);
                } else if (j == 0) {
                    table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1]);
                } else {
                    table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1])
                        || (table[i][j-1] && s2[j-1] == s3[i+j-1]);
                }
            }  // for j
        }  // for i

        return table[s1.size()][s2.size()];
    }
};

int main(int argc, char *argv[]) {
    Solution_Interleaving_String solution;
    string s1 = string("aabcc");
    string s2 = string("dbbca");
    string s3 = string("aadbbcbcac");
    bool yes = solution.isInterleave(s1, s2, s3);
    printf("s1 = %s, s2 = %s, s3 = %s, isInterleave = %d\n",
            s1.c_str(), s2.c_str(), s3.c_str(), yes);

    s3 = string("aadbbbaccc");
    yes = solution.isInterleave(s1, s2, s3);
    printf("s1 = %s, s2 = %s, s3 = %s, isInterleave = %d\n",
            s1.c_str(), s2.c_str(), s3.c_str(), yes);

    return 0;
}

