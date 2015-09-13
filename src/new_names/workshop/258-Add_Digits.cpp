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
 * File: 258-Add_Digits.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/add-digits/
 * Given a non-negative integer num, repeatedly add all its digits until the
 * result has only one digit.
 * 
 * For example:
 * 
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only
 * one digit, return it.
 * 
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 * 
 * Hint:
 * 
 * A naive implementation of the above process is trivial. Could you come up
 * with other methods?
 * What are all the possible results?
 * How do they occur, periodically or randomly?
 * You may find this Wikipedia article useful.
 * https://en.wikipedia.org/wiki/Digital_root
 *
 * Date: 2015.09.13
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <limits.h>

class Solution_Add_Digits {
public:
    int addDigits(int num) {
        while (num / 10 > 0) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }

        return num;
    }


    // take reference at: https://en.wikipedia.org/wiki/Digital_root
    int addDigits2(int num) {
        return num - (num - 1) / 9 * 9;
    }
};


void testcase() {
    Solution_Add_Digits solution;
    int num = 38;
    int digit = solution.addDigits(num);
    printf("num = %d, digit = %d\n", num, digit);

    num = 0;
    digit = solution.addDigits(num);
    printf("num = %d, digit = %d\n", num, digit);

    num = INT_MAX;
    digit = solution.addDigits(num);
    printf("num = %d, digit = %d\n", num, digit);

    num = INT_MAX - 1;
    digit = solution.addDigits(num);
    printf("num = %d, digit = %d\n", num, digit);

    num = 1000000;
    digit = solution.addDigits(num);
    printf("num = %d, digit = %d\n", num, digit);

    num = 100;
    digit = solution.addDigits(num);
    printf("num = %d, digit = %d\n", num, digit);

    num = 87;
    digit = solution.addDigits(num);
    printf("num = %d, digit = %d\n", num, digit);
}

int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

