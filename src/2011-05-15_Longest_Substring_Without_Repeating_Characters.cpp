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
 * File: 2011-05-15_Longest_Substring_Without_Repeating_Characters.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/
 *        longest-substring-without-repeating-characters/
 * Given a string, find the length of the longest substring without repeating
 * characters. For example, the longest substring without repeating letters for
 * "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest
 * substring is "b", with the length of 1.
 *
 *
 * Date: 2014.10.22
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

class Solution_Longest_Substring_Without_Repeating_Characters {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1)
            return s.length();

        int len = s.length();
        int result = 0;
        map<char, int> longest;
        int cur_begin = 0, cur_end = 0;

        while (cur_end < len) {
            if (longest.find(s[cur_end]) == longest.end()) {
                longest[s[cur_end]] = cur_end;
                cur_end++;
            } else {
                if (result < longest.size()) {
                    result = longest.size();
                }

                int conflict_position = longest[s[cur_end]];
                while (cur_begin <= conflict_position) {
                    longest.erase(s[cur_begin]);
                    cur_begin++;
                }
            }
        } // while
        if (result < longest.size()) {
            result = longest.size();
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution_Longest_Substring_Without_Repeating_Characters solution;

    string s;
    int longest;

    s = string("abcabcbb");
    longest = solution.lengthOfLongestSubstring(s);
    printf("string:%s, longest length:%d\n", s.c_str(), longest);

    s = string("bbbb");
    longest = solution.lengthOfLongestSubstring(s);
    printf("string:%s, longest length:%d\n", s.c_str(), longest);

    s = string("b");
    longest = solution.lengthOfLongestSubstring(s);
    printf("string:%s, longest length:%d\n", s.c_str(), longest);

    s = string("abcdefcdabghia");
    longest = solution.lengthOfLongestSubstring(s);
    printf("string:%s, longest length:%d\n", s.c_str(), longest);

    s = string("qopubjguxhxdipfzwswybgfylqvjzhar");
    longest = solution.lengthOfLongestSubstring(s);
    printf("string:%s, longest length:%d\n", s.c_str(), longest);

    return 0;
}
