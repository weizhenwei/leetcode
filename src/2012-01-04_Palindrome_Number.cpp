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
 * File: 2012-01-04_Palindrome_Number.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/palindrome-integer/
 * Determine whether an integer is a palindrome. Do this without extra space.
 *
 * Some hints:
 * Could negative integers be palindromes? (ie, -1)
 *
 * If you are thinking of converting the integer to string, note the
 * restriction of using extra space.
 *
 * You could also try reversing an integer. However, if you have solved the
 * problem "Reverse Integer", you know that the reversed integer might
 * overflow. How would you handle such case?
 *
 * There is a more generic way of solving this problem.
 *
 *
 * Date: 2014.10.22
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>

class Solution_Palindrome_Number {
public:
    bool isPalindrome(int x) {
        if (x < 0)  // negative is not Palindrome
            return false;

        long int a = x;
        long int b = 0;

        while ( a > 0) {
            b = b * 10 + a % 10;
            a = a / 10;
        }

        return b == x;
    }
};

int main(int argc, char *argv[]) {
    Solution_Palindrome_Number pn;

    int a = -1;
    bool b = false;

    a = 0;
    b = pn.isPalindrome(a);
    printf("a = %d, b = %d\n", a, b);

    a = -0;
    b = pn.isPalindrome(a);
    printf("a = %d, b = %d\n", a, b);

    a = -123321;
    b = pn.isPalindrome(a);
    printf("a = %d, b = %d\n", a, b);

    a = -123231;
    b = pn.isPalindrome(a);
    printf("a = %d, b = %d\n", a, b);

    a = 1203003021;
    b = pn.isPalindrome(a);
    printf("a = %d, b = %d\n", a, b);

    return 0;
}

