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
 * File: 2012-02-18_Implement_strStr.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/implement-strstr/
 * Implement strStr().
 *
 * Returns a pointer to the first occurrence of needle in haystack, or null if
 * needle is not part of haystack.
 *
 *
 * Date: 2014.10.25
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <string.h>

class Solution_Implement_strStr {
public:
    char *strStr(char *haystack, char *needle) {
        if (needle == NULL || strlen(needle) == 0)
            return haystack;
        if (haystack == NULL || strlen(needle) == 0)
            return NULL;

        int i = 0;
        char *temp = new char[strlen(needle) + 1];
        while (i < strlen(haystack)) {
            while (haystack[i] != needle[0] && i < strlen(haystack)) {
                i++;
            }

            strncpy(temp, &haystack[i], strlen(needle));
            temp[strlen(needle)] = '\0';

            if (strcmp(temp, needle) == 0)
                return &haystack[i];

            i++;
        }  // while

        return NULL;
    }
};

static void print_result(char *haystack, char *needle, char *result) {
    printf("haystack:%s\n", haystack);
    printf("needle:%s\n", needle);
    printf("result:%s\n", result);
}

int main(int argc, char *argv[]) {
    Solution_Implement_strStr solution;
    char *haystack = NULL;
    char *needle = NULL;
    char *result = NULL;

    haystack = "Hello, world!";
    needle = "";
    result = solution.strStr(haystack, needle);
    print_result(haystack, needle, result);

    haystack = "Hello, world!";
    needle = "H";
    result = solution.strStr(haystack, needle);
    print_result(haystack, needle, result);

    haystack = "Hello, world!";
    needle = "Ht";
    result = solution.strStr(haystack, needle);
    print_result(haystack, needle, result);

    haystack = "Hello, world!";
    needle = "or";
    result = solution.strStr(haystack, needle);
    print_result(haystack, needle, result);

    haystack = "Hello, world!";
    needle = "ort";
    result = solution.strStr(haystack, needle);
    print_result(haystack, needle, result);

    haystack = "Hello, world!";
    needle = "!";
    result = solution.strStr(haystack, needle);
    print_result(haystack, needle, result);


    haystack = "Hello, world!";
    needle = "\n";
    result = solution.strStr(haystack, needle);
    print_result(haystack, needle, result);

    haystack = "";
    needle = "Hello";
    result = solution.strStr(haystack, needle);
    print_result(haystack, needle, result);

    return 0;
}
