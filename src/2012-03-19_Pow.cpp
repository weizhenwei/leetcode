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
 * File: 2012-03-19_Pow.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/powx-n/
 * Implement pow(x, n).
 *
 *
 * Date: 2014.11.05
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>

class Solution_Pow {
public:
    double pow(double x, int n) {
        if (x == 0)
            return 1;
        if (x == 1)
            return x;

        bool negative = false;
        if (n < 0) {
            n = -n;
            negative = true;
        }

        double array[32];
        int i = 0;
        array[0] = x;
        for (i = 1; i < 32; i++) {
            array[i] = array[i-1] * array[i-1];
        }

        double result = 1;
        for (i = 31; i >= 0; i--) {
            long long int base = ((long long int )1) << i;
            if ((long long int) n >= base) {
                result *= array[i];
                n -= base;
            }
        }

        if (negative == true) {
            result = 1 / result;
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution_Pow solution;
    double x = 1;
    int n = 2;
    double result = solution.pow(x, n);
    printf("x = %f, n =%d, pow = %f\n", x, n, result);

    x = 2;
    n = 10;
    result = solution.pow(x, n);
    printf("x = %f, n =%d, pow = %f\n", x, n, result);

    x = 2.1;
    n = 10;
    result = solution.pow(x, n);
    printf("x = %f, n =%d, pow = %f\n", x, n, result);

    x = 8.88023;
    n = 3;
    result = solution.pow(x, n);
    printf("x = %f, n =%d, pow = %f\n", x, n, result);

    x = 34.00515;
    n = -3;
    result = solution.pow(x, n);
    printf("x = %f, n =%d, pow = %f\n", x, n, result);


    return 0;
}
