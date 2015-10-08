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
 * File: 290-Word_Pattern.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/word-pattern/
 * Given a pattern and a string str, find if str follows the same pattern.

 * Examples:
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 * Notes:
 * patterncontains only lowercase alphabetical letters, and str contains words
 * separated by a single space. Each word in str contains only lowercase
 * alphabetical letters.
 * Both pattern and str do not have leading or trailing spaces.
 * Each letter in pattern must map to a word with length that is at least 1.
 *
 *
 * Date: 2015.10.08
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <map>
#include <set>
#include <string>

using std::map;
using std::pair;
using std::set;
using std::string;

class Solution_Word_Pattern {
public:
    bool wordPattern(string pattern, string str) {
        if (pattern.size() == false && str.size() == false) {
            return true;
        }
        if (pattern.size() == false || str.size() == false) {
            return false;
        }

        map<char, string> patternTable;
        set<string> strTaken;
        int j = 0;
        for (int i = 0; i < pattern.size(); i++) {
            if (str.size() == 0) {
                return false;
            }
            char key = pattern[i];
            map<char, string>::iterator iter;
            int spacePosition = str.find(' ');
            string valueStr;
            if (spacePosition == string::npos) {
                valueStr = str;
                str = str.substr(str.size());
            } else {
                valueStr = str.substr(0, spacePosition);
                str = str.substr(spacePosition + 1);
            }

            if ((iter = patternTable.find(key)) == patternTable.end()) {
                if (strTaken.find(valueStr) != strTaken.end()) {
                    return false;
                } else {
                    strTaken.insert(valueStr);
                    patternTable.insert(pair<char, string>(key, valueStr));
                }
            } else {
                string originStr = iter->second;
                if (originStr != valueStr) {
                    return false;
                }
            }
        }  // for

        if (str.size() > 0) {
            return false;
        } else {
            return true;
        }
    }
};

void testcase() {
    Solution_Word_Pattern solution;
    string pattern = "a";
    string str  = "sdfdsf";
    bool result = false;
    result = solution.wordPattern(pattern, str);
    printf("pattern = %s, string = %s, result = %d\n",
            pattern.c_str(), str.c_str(), result);

    pattern = "ab";
    str  = "sdfdsf wer";
    result = false;
    result = solution.wordPattern(pattern, str);

    pattern = "aba";
    str  = "sdfdsf wer sdfdsf";
    result = false;
    result = solution.wordPattern(pattern, str);
    printf("pattern = %s, string = %s, result = %d\n",
            pattern.c_str(), str.c_str(), result);

    pattern = "aba";
    str  = "sdfdsf wer sdfdsf sdfddff";
    result = false;
    result = solution.wordPattern(pattern, str);
    printf("pattern = %s, string = %s, result = %d\n",
            pattern.c_str(), str.c_str(), result);

    pattern = "abba";
    str  = "dog dog dog dog";
    result = false;
    result = solution.wordPattern(pattern, str);
    printf("pattern = %s, string = %s, result = %d\n",
            pattern.c_str(), str.c_str(), result);
}

int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

