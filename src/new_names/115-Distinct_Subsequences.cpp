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
 * File: 115-Distinct_Subsequences.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/distinct-subsequences/
 * Given a string S and a string T, count the number of distinct subsequences of
 * T in S.
 *
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ACE" is a
 * subsequence of "ABCDE" while "AEC" is not).
 *
 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 *
 * Return 3.
 *
 *
 * Date: 2015.01.27
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

// originates from: https://oj.leetcode.com/discuss/22858/c-accepted-solution
class Solution_Distinct_Subsequences {
public:
    int numDistinct(string S, string T) {
        int m = S.size();
        int n = T.size();
        if (m < n) {
            return 0;
        }

        vector<int> sub(n + 1, 0);
        sub[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = n; j > 0; j--) {
                if (S[i] == T[j-1]) {
                    sub[j] += sub[j-1];
                }
            }  // j
        }  // i

        return sub[n];
    }
};

int main(int argc, char *argv[]) {
    Solution_Distinct_Subsequences solution;

    string S = "rabbbit";
    string T = "rabbit";
    int n = solution.numDistinct(S, T);
    printf("S = %s, T = %s, n = %d\n", S.c_str(), T.c_str(), n);

    S = "rabbabit";
    T = "rababit";
    n = solution.numDistinct(S, T);
    printf("S = %s, T = %s, n = %d\n", S.c_str(), T.c_str(), n);

    S = "rabbabit";
    T = "raababit";
    n = solution.numDistinct(S, T);
    printf("S = %s, T = %s, n = %d\n", S.c_str(), T.c_str(), n);

    S = "rabbabit";
    T = "raababittttt";
    n = solution.numDistinct(S, T);
    printf("S = %s, T = %s, n = %d\n", S.c_str(), T.c_str(), n);

    return 0;
}

