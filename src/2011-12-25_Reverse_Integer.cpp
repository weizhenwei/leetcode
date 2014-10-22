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
 * File: 2011-12-25_Reverse_Integer.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/reverse-integer/
 * Reverse digits of an integer.
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *
 *
 * Date: 2014.10.21
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>

class Solution_Reverse_Integer {
public:
    int reverse(int x) {
        int a = x < 0 ? -x : x;
        int b = 0;

        while ( a > 0) {
            b = b * 10 + a % 10;
            a = a / 10;
        }

        return x < 0 ? -b : b;
    }
};

int main(int argc, char *argv[]) {
    Solution_Reverse_Integer ri;

    int a = -1, b = -1;

    a = 0;
    b = ri.reverse(a);
    printf("a = %d, b = %d\n", a, b);

    a = -0;
    b = ri.reverse(a);
    printf("a = %d, b = %d\n", a, b);

    a = 123;
    b = ri.reverse(a);
    printf("a = %d, b = %d\n", a, b);

    a = -123;
    b = ri.reverse(a);
    printf("a = %d, b = %d\n", a, b);

    a = 120300;
    b = ri.reverse(a);
    printf("a = %d, b = %d\n", a, b);

    return 0;
}

