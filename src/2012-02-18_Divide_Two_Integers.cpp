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
 * File: 2012-02-18_Divide_Two_Integers.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/divide-two-integers/
 * Divide two integers without using multiplication, division and mod operator.
 *
 * Date: 2014.10.25
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

class Solution_Divide_Two_Integers {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0)
            return 0;
        long long int new_dividend;
        long long int new_divisor;
        int sign = 0;
        if (dividend < 0) {
            new_dividend = llabs(dividend);
            sign = -1;
        } else {
            new_dividend = dividend;
        }

        if (divisor < 0) {
            new_divisor = llabs(divisor);
            if (sign == -1) {
                sign = 0;
            } else {
                sign = -1;
            }
        } else {
            new_divisor = divisor;
        }

        if (new_divisor == 1) {
            if (sign == -1) {
                return -new_dividend;
            } else {
                return  new_dividend;
            }
        }

        int i = 0;
        long long int bitmap[32];
        bitmap[0] = new_divisor;
        for (i = 1; i < 32; i++) {
            bitmap[i] = new_divisor << i;
            if (bitmap[i] > new_dividend)
                break;
        }

        i--;
        int result = 0;
        while (i >= 0) {
            while (new_dividend >= bitmap[i]) {
                result += 1 << i;
                new_dividend -= bitmap[i];
            }

            while (new_dividend < bitmap[i]) {
                i--;
            }
        }
        
        if (sign == -1) {
            return -result;
        } else {
            return result;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution_Divide_Two_Integers solution;
    int dividend = 0, divisor = 0, result = 0;
    
    dividend = 10;
    divisor = 5;
    result = solution.divide(dividend, divisor);
    printf("dividend = %d, divisor = %d, result = %d\n",
            dividend, divisor, result);

    dividend = 12;
    divisor = 5;
    result = solution.divide(dividend, divisor);
    printf("dividend = %d, divisor = %d, result = %d\n",
            dividend, divisor, result);

    dividend = 1208;
    divisor = 2;
    result = solution.divide(dividend, divisor);
    printf("dividend = %d, divisor = %d, result = %d\n",
            dividend, divisor, result);

    dividend = 1218;
    divisor = 3;
    result = solution.divide(dividend, divisor);
    printf("dividend = %d, divisor = %d, result = %d\n",
            dividend, divisor, result);

    dividend = 1219;
    divisor = 3;
    result = solution.divide(dividend, divisor);
    printf("dividend = %d, divisor = %d, result = %d\n",
            dividend, divisor, result);

    dividend = -1219;
    divisor = 3;
    result = solution.divide(dividend, divisor);
    printf("dividend = %d, divisor = %d, result = %d\n",
            dividend, divisor, result);


    dividend = -2147483648;
    divisor = 2;
    result = solution.divide(dividend, divisor);
    printf("dividend = %d, divisor = %d, result = %d\n",
            dividend, divisor, result);

    dividend = -2147483648;
    divisor = 1;
    result = solution.divide(dividend, divisor);
    printf("dividend = %d, divisor = %d, result = %d\n",
            dividend, divisor, result);

    dividend = -2147483648;
    divisor = -1;
    result = solution.divide(dividend, divisor);
    printf("dividend = %d, divisor = %d, result = %d\n",
            dividend, divisor, result);

    dividend = 5;
    divisor = 2;
    result = solution.divide(dividend, divisor);
    printf("dividend = %d, divisor = %d, result = %d\n",
            dividend, divisor, result);

    dividend = 2;
    divisor = 2;
    result = solution.divide(dividend, divisor);
    printf("dividend = %d, divisor = %d, result = %d\n",
            dividend, divisor, result);

    dividend = -2147483648;
    divisor = -2147483648;
    result = solution.divide(dividend, divisor);
    printf("dividend = %d, divisor = %d, result = %d\n",
            dividend, divisor, result);

    return 0;
}

