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
 * File: 2012-03-27_Length_of_Last_Word.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/two-sum/
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 *
 * For example, 
 * Given s = "Hello World",
 * return 5.
 *
 *
 * Date: 2014.10.28
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <string.h>

class Solution_Length_of_Last_Word {
public:
    int lengthOfLastWord(const char *s) {
        int length = strlen(s);
        int i = length - 1;
        bool b = false;
        while (i >= 0 && s[i] == ' ') {
            b = true;
            i--;
        }
        if (i == -1) {
            return 0;
        }

        if (b == true) {
            length = i + 1;
        }
        while (i >= 0) {
            if (s[i] == ' ') {
                return length - i - 1;
            } else {
                i--;
            }
        }

        if (i == -1) {
            return length;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution_Length_of_Last_Word solution;
    const char *s = "Hello World";
    int length = solution.lengthOfLastWord(s);
    printf("s = %s, last word's length = %d\n", s, length);

    s =  "fsdfsdfsdfsd";
    length = solution.lengthOfLastWord(s);
    printf("s = %s, last word's length = %d\n", s, length);

    s =  "fsdfsdfsdfs ";
    length = solution.lengthOfLastWord(s);
    printf("s = %s, last word's length = %d\n", s, length);

    s =  "fsdfsdfs fss";
    length = solution.lengthOfLastWord(s);
    printf("s = %s, last word's length = %d\n", s, length);

    s =  "a";
    length = solution.lengthOfLastWord(s);
    printf("s = %s, last word's length = %d\n", s, length);

    s =  "a ";
    length = solution.lengthOfLastWord(s);
    printf("s = %s, last word's length = %d\n", s, length);

    return 0;
}
