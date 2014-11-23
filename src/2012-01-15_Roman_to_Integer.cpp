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
 * File: 2012-01-15_Roman_to_Integer.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/roman-to-integer/
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 *
 * Date: 2014.11.23
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <assert.h>
#include <stdio.h>
#include <string>

using std::string;

class Solution_Roman_to_Integer {
public:
    int romanToInt(string s) {
        int integer = 0;

        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case 'M':
                    {
                        integer += 1000;
                        break;
                    }
                case 'C':
                    {
                        if (i < s.size() - 1) {
                            if (s[i+1] == 'M') {
                                integer += 900;
                                i++;
                            } else if (s[i+1] == 'D') {
                                integer += 400;
                                i++;
                            } else {
                                integer += 100;
                            }
                        } else {
                            integer += 100;
                        }
                        break;
                    }
                case 'D':
                    {
                        integer += 500;
                        break;
                    }

                case 'X':
                    {
                        if (i < s.size() - 1) {
                            if (s[i+1] == 'C') {
                                integer += 90;
                                i++;
                            } else if (s[i+1] == 'L') {
                                integer += 40;
                                i++;
                            } else {
                                integer += 10;
                            }
                        } else {
                            integer += 10;
                        }
                        break;
                    }
                case 'L':
                    {
                        integer += 50;
                        break;
                    }

                case 'I':
                    {
                        if (i < s.size() - 1) {
                            if (s[i+1] == 'X') {
                                integer += 9;
                                i++;
                            } else if (s[i+1] == 'V') {
                                integer += 4;
                                i++;
                            } else {
                                integer += 1;
                            }
                        } else {
                            integer += 1;
                        }
                        break;
                    }
                case 'V':
                    {
                        integer += 5;
                        break;
                    }
                default:
                    assert(0);
            }  // switch
        }  // for

        assert(integer >= 0 && integer <= 3999);
        return integer;
    }
};

int main(int argc, char *argv[]) {
    Solution_Roman_to_Integer solution;
    string s = "MMMCMXCIX";
    int integer = solution.romanToInt(s);
    printf("roman = %s, integer = %d\n", s.c_str(), integer);

    s = "MMMCI";
    integer = solution.romanToInt(s);
    printf("roman = %s, integer = %d\n", s.c_str(), integer);

    s = "MMCI";
    integer = solution.romanToInt(s);
    printf("roman = %s, integer = %d\n", s.c_str(), integer);
    return 0;
}

