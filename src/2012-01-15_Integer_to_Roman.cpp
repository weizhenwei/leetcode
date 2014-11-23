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
 * File: 2012-01-15_Integer_to_Roman.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/integer-to-roman/
 * Given an integer, convert it to a roman numeral.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
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

using std::string;

class Solution_Integer_to_Roman {
public:
    string intToRoman(int num) {
        assert(num >= 1 && num <= 3999);
        string roman;

        int thousand = num / 1000;
        if (thousand > 0) {
            for (int i = 0; i < thousand; i++) {
                roman.push_back('M');
            }
        }

        num = num % 1000;
        if (num >= 900) {
            roman.push_back('C');
            roman.push_back('M');
            num -= 900;
        }
        if (num >= 500) {
            roman.push_back('D');
            num -= 500;
        }
        if (num >= 400) {
            roman.push_back('C');
            roman.push_back('D');
            num -= 400;
        }
        if (num >= 100) {
            int hundred = num / 100;
            for (int i = 0; i < hundred; i++) {
                roman.push_back('C');
            }
            num = num % 100;
        }

        if (num >= 90) {
            roman.push_back('X');
            roman.push_back('C');
            num -= 90;
        }
        if (num >= 50) {
            roman.push_back('L');
            num -= 50;
        }
        if (num >= 40) {
            roman.push_back('X');
            roman.push_back('L');
            num -= 40;
        }
        if (num >= 10) {
            int ten = num / 10;
            for (int i = 0; i < ten; i++) {
                roman.push_back('X');
            }
            num = num % 10;
        }

        if (num == 9) {
            roman.push_back('I');
            roman.push_back('X');
            num -= 9;
        }
        if (num >= 5) {
            roman.push_back('V');
            num -= 5;
        }
        if (num >= 4) {
            roman.push_back('I');
            roman.push_back('V');
            num -= 4;
        }
        if (num >= 1) {
            for (int i = 0; i < num; i++) {
                roman.push_back('I');
            }
            num -= num;
        }

        assert(num == 0);


        return roman;
    }
};

int main(int argc, char *argv[]) {
    Solution_Integer_to_Roman solution;
    int num = 1;
    string roman = solution.intToRoman(num);
    printf("int = %d, roman = %s\n", num, roman.c_str());

    num = 2;
    roman = solution.intToRoman(num);
    printf("int = %d, roman = %s\n", num, roman.c_str());

    num = 10;
    roman = solution.intToRoman(num);
    printf("int = %d, roman = %s\n", num, roman.c_str());

    num = 100;
    roman = solution.intToRoman(num);
    printf("int = %d, roman = %s\n", num, roman.c_str());

    num = 1000;
    roman = solution.intToRoman(num);
    printf("int = %d, roman = %s\n", num, roman.c_str());

    num = 3000;
    roman = solution.intToRoman(num);
    printf("int = %d, roman = %s\n", num, roman.c_str());

    num = 3999;
    roman = solution.intToRoman(num);
    printf("int = %d, roman = %s\n", num, roman.c_str());

    return 0;
}

