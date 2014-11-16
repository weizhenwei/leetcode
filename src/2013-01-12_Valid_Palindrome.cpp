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
 * File: 2013-01-12_Valid_Palindrome.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/valid-palindrome/
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 *
 * Note:
 * Have you consider that the string might be empty? This is a good question to
 * ask during an interview.
 *
 * For the purpose of this problem, we define empty string as valid palindrome.
 *
 *
 * Date: 2014.11.16
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <ctype.h>
#include <stdio.h>
#include <string>

using std::string;

class Solution_Valid_Palindrome {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        int start = 0;
        int end = len - 1;
        while (start < end) {
            while (!isalnum(s[start]) && start < len) {
                    start++;
            }
            if (start == len)
                break;
            while (!isalnum(s[end]) && end >= 0) {
                    end--;
            }
            if (end < 0)
                break;
            if (start >= end)
                break;

            if (isdigit(s[start])) {
                if (isdigit(s[end])) {
                    if (s[start] != s[end]) {
                        return false;
                    }
                } else {
                    return false;
                }
            } else {
                if (isdigit(s[end])) {
                    return false;
                } else {
                    if (tolower(s[start]) != tolower(s[end])) {
                        return false;
                    }
                }
            }

            start++;
            end--;
        }  // while

        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution_Valid_Palindrome solution;

    string s = string("A man, a plan, a canal: Panama");
    bool valid = solution.isPalindrome(s);
    printf("s = %s, is palindrome = %d\n", s.c_str(), valid);

    s = string("race a car");
    valid = solution.isPalindrome(s);
    printf("s = %s, is palindrome = %d\n", s.c_str(), valid);

    s = string(".,");
    valid = solution.isPalindrome(s);
    printf("s = %s, is palindrome = %d\n", s.c_str(), valid);

    return 0;
}

