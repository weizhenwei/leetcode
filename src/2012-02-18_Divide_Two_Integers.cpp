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

#include <stdio.h>
#include <stdlib.h>
#include <stack>

using std::stack;

class Solution_Divide_Two_Integers {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) {
            return 0;
        }
        if (divisor == 1) {
            return dividend;
        } else if (divisor == -1) {
            return 0 - dividend;
        }
        
        int result = 0;
        int ddividend = dividend;
        int ddivisor = divisor;
        int ssignal = 0;
        if (dividend < 0) {
            ddividend = 0 - dividend;
            ssignal = -1;
        }
        if (divisor < 0) {
            ddivisor = 0 - divisor;
            if (ssignal == -1) {
                ssignal = 0;
            } else {
                ssignal = -1;
            }
        }
        
        stack<int> divs;
        stack<int> intevals;
        int inteval = 1;
        while (ddividend >= ddivisor) {
            result += inteval;
            ddividend -= ddivisor;
            divs.push(ddivisor);
            intevals.push(inteval);

            if (ddividend > ddivisor + ddivisor) {
                ddivisor += ddivisor;
                inteval += inteval;
            } else {
                while (ddividend > 0 && ddividend < ddivisor) {
                    if (!divs.empty()) {
                        ddivisor = divs.top();
                        inteval = intevals.top();
                        divs.pop();
                        intevals.pop();
                    } else {
                        break;
                    }
                }  // while
            }
        }  // while
        
        if (ssignal == -1) {
            return 0 - result;
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


    dividend = -2147483648;
    divisor = 2;
    result = solution.divide(dividend, divisor);
    printf("dividend = %d, divisor = %d, result = %d\n",
            dividend, divisor, result);

    long int a =  (long int) -2147483648;
    // long int a =  -214;
    long int b = abs(a);
    long int c = abs(a);
    printf("a = %ld, b = %ld, c = %ld\n", a, b, c);

    return 0;
}

