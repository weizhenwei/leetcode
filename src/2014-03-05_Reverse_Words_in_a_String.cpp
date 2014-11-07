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
 * File: 2014-03-05_Reverse_Words_in_a_String.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/reverse-words-in-a-string/
 * Given an input string, reverse the string word by word.
 *
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 *
 * Clarification:
 * What constitutes a word?
 * A sequence of non-space characters constitutes a word.
 * Could the input string contain leading or trailing spaces?
 * Yes. However, your reversed string should not contain leading or trailing
 * spaces.
 * How about multiple spaces between two words?
 * Reduce them to a single space in the reversed string.
 *
 *
 * Date: 2014.11.07
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <ctype.h>
#include <stdio.h>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution_Reverse_Words_in_a_String {
public:
    void reverseWords(string &s) {
        if (s.size() == 0)
            return;

        // skip prefix space;
        int i = 0;
        while (i < s.size() && isspace(s[i])) {
            i++;
        }
        if (i == s.size()) {
            s = string("");
            return;
        }

        string result = string("");
        while (i < s.size()) {
            int begin = i;
            while (i < s.size() && !isspace(s[i])) {
                i++;
            }

            string tmp = string(s, begin, i - begin);
            if (result.size() == 0) {
                result = tmp;
            } else {
                result = tmp + " " + result;
            }

            if (i == s.size())
                break;

            while (i < s.size() && isspace(s[i])) {
                i++;
            }
            if (i == s.size())
                break;
        }

        s = result;
    }
};

int main(int argc, char *argv[]) {
    Solution_Reverse_Words_in_a_String solution;

    string s = string("Hello, world!");
    printf("before:%s----------------------------\n", s.c_str());
    solution.reverseWords(s);
    printf("after:%s-----------------------------\n", s.c_str());

    s = string("Helloworld!");
    printf("before:%s----------------------------\n", s.c_str());
    solution.reverseWords(s);
    printf("after:%s-----------------------------\n", s.c_str());

    s = string("            Helloworld!");
    printf("before:%s----------------------------\n", s.c_str());
    solution.reverseWords(s);
    printf("after:%s\n", s.c_str());
    printf("after:%s-----------------------------\n", s.c_str());

    s = string("            Hello      world!               dsfsd  ");
    printf("before:%s----------------------------\n", s.c_str());
    solution.reverseWords(s);
    printf("after:%s-----------------------------\n", s.c_str());

    return 0;
}
