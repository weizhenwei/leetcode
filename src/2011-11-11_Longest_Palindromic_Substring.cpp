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
 * File: 2011-11-11_Longest_Palindromic_Substring.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/longest-palindromic-substring/
 * Given a string S, find the longest palindromic substring in S. You may
 * assume that the maximum length of S is 1000, and there exists one unique
 * longest palindromic substring.
 *
 *
 * Date: 2014.10.21
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <string>

using std::string;

class Solution_Longest_Palindromic_Substring {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1)
            return s;

        string result, tmp;
        int pivot = 0, increment = 0;

        while (pivot < s.length()) {
            // odd situation;
            increment = 0;
            while ((pivot - increment >= 0) && (pivot + increment < s.length())
                    && (s[pivot - increment] == s[pivot + increment])) {
                increment++;
            }
            tmp = string(s, pivot - increment + 1, 2 * increment - 1);
            if (result.length() < tmp.length())
                result = tmp;

            // even situation;
            increment = 0;
            while ((pivot - increment >= 0)
                    && (pivot + increment + 1 < s.length())
                    && (s[pivot - increment] == s[pivot + increment + 1])) {
                increment++;
            }
            tmp = string(s, pivot - increment + 1, 2 * increment);
            if (result.length() < tmp.length())
                result = tmp;

            pivot++;
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution_Longest_Palindromic_Substring solution;
    string s, lps;

    s = string("a");
    lps = solution.longestPalindrome(s);
    printf("s = %s, lps = %s\n", s.c_str(), lps.c_str());

    s = string("ab");
    lps = solution.longestPalindrome(s);
    printf("s = %s, lps = %s\n", s.c_str(), lps.c_str());

    s = string("aba");
    lps = solution.longestPalindrome(s);
    printf("s = %s, lps = %s\n", s.c_str(), lps.c_str());

    s = string("abba");
    lps = solution.longestPalindrome(s);
    printf("s = %s, lps = %s\n", s.c_str(), lps.c_str());

    s = string("abbbbbab");
    lps = solution.longestPalindrome(s);
    printf("s = %s, lps = %s\n", s.c_str(), lps.c_str());

    s = string("abbbbbabbbbaaaaa");
    lps = solution.longestPalindrome(s);
    printf("s = %s, lps = %s\n", s.c_str(), lps.c_str());

    s = string("aaaaabcdeffedcba");
    lps = solution.longestPalindrome(s);
    printf("s = %s, lps = %s\n", s.c_str(), lps.c_str());

    return 0;
}
