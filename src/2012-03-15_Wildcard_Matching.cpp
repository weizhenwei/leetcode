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
 * File: 2012-03-15_Wildcard_Matching.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/wildcard-matching/
 * Implement wildcard pattern matching with support for '?' and '*'.
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 *
 * The matching should cover the entire input string (not partial).
 *
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 *
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "*") → true
 * isMatch("aa", "a*") → true
 * isMatch("ab", "?*") → true
 * isMatch("aab", "c*a*b") → false
 *
 *
 * Date: 2014.12.03
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>

class Solution_Wildcard_Matching {
public:
    bool isMatch(const char *s, const char *p) {
        const char *star = NULL;
        const char *ss = s;
        while (*s) {
            if ((*p == '?') || (*p == *s)) {
                p++;
                s++;
                continue;
            }

            if (*p == '*') {
                star = p;
                p++;
                ss = s;
                continue;
            }

            if (star) {
                p = star + 1;
                ss++;
                s = ss;
                continue;
            }

            return false;
        }  // while

        while (*p == '*') {
            p++;
        }

        return !*p;
    }
};

int main(int argc, char *argv[]) {
    Solution_Wildcard_Matching solution;
    const char *s = "aa";
    const char *p = "a";
    bool match = solution.isMatch(s, p);
    printf("s = %s, p = %s, match = %d\n", s, p, match);

    s = "aa";
    p = "aa";
    match = solution.isMatch(s, p);
    printf("s = %s, p = %s, match = %d\n", s, p, match);

    s = "aaa";
    p = "aa";
    match = solution.isMatch(s, p);
    printf("s = %s, p = %s, match = %d\n", s, p, match);

    s = "aaa";
    p = "*";
    match = solution.isMatch(s, p);
    printf("s = %s, p = %s, match = %d\n", s, p, match);

    s = "aaa";
    p = "a*";
    match = solution.isMatch(s, p);
    printf("s = %s, p = %s, match = %d\n", s, p, match);

    s = "ab";
    p = "?*";
    match = solution.isMatch(s, p);
    printf("s = %s, p = %s, match = %d\n", s, p, match);

    s = "aab";
    p = "c*a*b";
    match = solution.isMatch(s, p);
    printf("s = %s, p = %s, match = %d\n", s, p, match);

    return 0;
}

