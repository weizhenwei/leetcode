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
 * File: 2011-04-02_Valid_Number.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/valid-number/
 * Validate if a given string is numeric.
 *
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * Note: It is intended for the problem statement to be ambiguous. You should
 * gather all requirements up front before implementing one.
 *
 * Date: 2014.10.30
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <assert.h>
#include <stdio.h>
#include <string.h>

class Solution_Valid_Number {
public:
    bool isNumber(const char *s) {
        if (strlen(s) == 0)
            return false;
        if (strlen(s) == 1) {
            if (s[0] < '0' || s[0] > '9') {
                return false;
            } else {
                return true;
            }
        }

        int signal_token = 0;
        int signal_position = -1;
        int e_token = 0;
        int e_position = -1;
        int dot_token = 0;
        int dot_position = -1;
        int empty_token = 0;
        int i = 0;
        int start;
        int end;
        int has_number = 0;
        while (s[i] == ' ' && i < strlen(s)) {  // remove profix ' '
            i++;
        }
        if (i == strlen(s)) {
            return false;
        }
        start = i;
        while (s[i] != ' ' && i < strlen(s)) {
            i++;
        }
        end = i - 1;

        while (i < strlen(s)) {  // remove suffix ' '
            if (s[i] != ' ') {
                return false;
            }
            i++;
        }

        i = start;
        while (i <= end) {
            if (s[i] == '+' || s[i] == '-') {
                if (signal_token == 0) {
                    if (i > start) {  // signal must after e_token;
                        if (e_token == 1) {
                            signal_token++;
                            signal_position = i;
                        } else {
                            return false;
                        }
                    } else {
                        signal_token++;
                        signal_position = i;
                    }
                } else if (signal_token == 1) {
                    if (e_token == 0) {  // signal must after e_token;
                        return false;
                    } else {
                        signal_token++;
                        signal_position = i;
                    }
                } else if (signal_token >= 2) {  // too much signal;
                    return false;
                }
            } else if (s[i] == '.') {
                if (dot_token == 0) {
                    if (e_token >= 1) {  // dot after e_token, invalid;
                        return false;
                    } else {
                        dot_token++;
                        dot_position = i;
                    }
                } else {  // too much dot;
                    return false;
                }
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (i == start) {  // is this valid ?
                    return false;
                } else {
                    if (e_token >= 1) {  // too much e_token;
                        return false;
                    } else {
                        if (has_number == 0) {
                            return false;
                        } else {
                            e_token++;
                            e_position = i;
                        }
                    }
                }
            } else if (s[i] < '0' || s[i] > '9') {
                while (s[i] == ' ') {
                    i++;
                }
                if (i != strlen(s)) {
                    return false;
                } else {
                    if (dot_position == end) {
                        return false;
                    } else {
                        return true;
                    }
                }
            } else {
                has_number = 1;
            }

            i++;
        }  // while

        if (signal_position == end)
            return false;

        if (e_position == end) {
            return false;
        } else {
            if (dot_position == end) {
                if (has_number) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return true;
            }
        }
    }
};

int main(int argc, char *argv[]) {
    Solution_Valid_Number solution;
    const char *s = "1232";
    bool valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == true);

    s = "s";
    valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == false);

    s = "+0";
    valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == true);

    s = ".";
    valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == false);

    s = "2 ";
    valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == true);

    s = " .";
    valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == false);

    s = ". ";
    valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == false);

    s = " .1";
    valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == true);

    s = "1.";
    valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == true);

    s = "3. ";
    valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == true);

    s = "0.0";
    valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == true);

    s = "+1.0";
    valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == true);

    s = "0e";
    valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == false);

    s = "0e ";
    valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == false);

    s = "+1.0e";
    valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == false);

    s = "4e+";
    valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == false);

    s = ".e1";
    valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == false);

    s = "+1.0e12";
    valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == true);

    s = "+1.0e-12";
    valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == true);

    s = "+1.0e+12";
    valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == true);

    s = "+-1.0e+12";
    valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == false);

    s = "+1.+0e+12";
    valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == false);

    s = "+1.e+12";
    valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == true);

    s = "+1.e+1.2";
    valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == false);

    s = "+1.e+0e+12";
    valid = solution.isNumber(s);
    printf("s = %s, %d\n", s, valid);
    assert(valid == false);

    return 0;
}
