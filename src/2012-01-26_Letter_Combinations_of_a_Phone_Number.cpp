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
 * File: 2012-01-26_Letter_Combinations_of_a_Phone_Number.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/
 * Given a digit string, return all possible letter combinations that the number
 * could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below.
 * 2:abc
 * 3:def
 * 4:ghi
 * 5:jkl
 * 6:mno
 * 7:pqrs
 * 8:tuv
 * 9:wxyz
 *
 *
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 *
 * Date: 2014.11.23
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <assert.h>
#include <stdio.h>
#include <string>
#include <vector>

using std::vector;
using std::string;


class Solution_Combinations_of_Phone_Number {
public:
    string digitToString(char digit) {
        switch (digit) {
            case '2': {
                return string("abc");
            }
            case '3': {
                return string("def");
            }
            case '4': {
                return string("ghi");
            }
            case '5': {
                return string("jkl");
            }
            case '6': {
                return string("mno");
            }
            case '7': {
                return string("pqrs");
            }
            case '8': {
                return string("tuv");
            }
            case '9': {
                return string("wxyz");
            }
            default: {
                assert(0);
                return string("whatthefuckisthis?");
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if (digits.size() == 0) {
            string elem = string("");
            combinations.push_back(elem);
            return combinations;
        }
        if (digits.size() == 1) {
            string chars = digitToString(digits[0]);
            for (int i = 0; i < chars.size(); i++) {
                string elem = string(1, chars[i]);
                combinations.push_back(elem);
            }  // for
            return combinations;
        }
        
        char first = digits[0];
        digits.erase(digits.begin());
        combinations = letterCombinations(digits);
        string chars = digitToString(first);
        vector<string> result;
        for (int i = 0; i < chars.size(); i++) {
            string first = string(1, chars[i]);
            for (int j = 0; j < combinations.size(); j++) {
                string elem = first + combinations[j];
                result.push_back(elem);
            }
        }
        
        return result;
    }
};

static void print_vector(vector<string> &combinations) {
    for (int i = 0; i < combinations.size(); i++) {
        printf("%s\n", combinations[i].c_str());
    }
}

int main(int argc, char *argv[]) {
    Solution_Combinations_of_Phone_Number solution;
    string digits = string("23");
    vector<string> combinations = solution.letterCombinations(digits);
    printf("digits:%s\n", digits.c_str());
    print_vector(combinations);

    digits = string("234");
    combinations = solution.letterCombinations(digits);
    printf("digits:%s\n", digits.c_str());
    print_vector(combinations);

    return 0;
}

