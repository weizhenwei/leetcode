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
 * File: 2011-12-26_String_to_Integer.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/string-to-integer-atoi/
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases. If you want a challenge,
 * please do not see below and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given
 * input specs). You are responsible to gather all the input requirements up
 * front.
 * 
 *
 * Date: 2014.10.22
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <ctype.h>
#include <limits.h>

class Solution_String_to_Integer {
public:
    int atoi(const char *str) {
        if (str == NULL)
            return 0;
        const char *c = str;
        int negative = 0;
        long long int result = 0;

        while (isspace(*c) != 0)
            c++;

        if (*c == '-') {
            negative = 1;
            c++;
        } else if (*c == '+') {
            negative = 0;
            c++;
        }

        while (isdigit(*c) != 0) {
            result = result * 10 + (*c - '0');
            c++;
        }

        if (negative == 1) {
            result = -result;
            if (result < INT_MIN)
                return INT_MIN;
            else
                return result;
        } else {
            if (result > INT_MAX)
                return INT_MAX;
            else
                return result;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution_String_to_Integer sti;
    const char *a = NULL;
    int b = 0;

    a = "sdf    -4545sferwed23";
    b = sti.atoi(a);
    printf("a = %s, b = %d\n", a, b);

    a = "    -4545sferwed23";
    b = sti.atoi(a);
    printf("a = %s, b = %d\n", a, b);

    a = "    +34545adfad23";
    b = sti.atoi(a);
    printf("a = %s, b = %d\n", a, b);

    a = "    -3454523423423523523523423423";
    b = sti.atoi(a);
    printf("a = %s, b = %d\n", a, b);

    a = "    +3454523423423523523523423423";
    b = sti.atoi(a);
    printf("a = %s, b = %d\n", a, b);


    return 0;
}
