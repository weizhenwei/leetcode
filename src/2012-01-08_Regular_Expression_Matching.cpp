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
 * File: 2012-01-08_Regular_Expression_Matching.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/regular-expression-matching/
 * Implement regular expression matching with support for '.' and '*'.
 *
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 *
 * The matching should cover the entire input string (not partial).
 *
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 *
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b") → true
 *
 *
 * Date: 2014.10.22
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

class Solution_Regular_Expression_Matching {
public:
    bool isMatch(const char *s, const char *p) {
        const char *pp = s;
        const char *qq = p;

        int eat_all = 0;
        while (*pp != '\0') {
            if (*qq == '\0') { // pattern is over;
                return false;
            } else if (*qq == '.') { // match any single character;
                if (*(qq + 1) != '\0') {
                    if (*(qq + 1) == '*') {
                        if (*(qq + 2) != '\0') {
                            if (*pp != *(qq + 2)) {
                                pp++;
                                eat_all++;
                            } else {
                                if (*(qq + 3) != '\0') {
                                    if (*(qq + 3) == '*') {
                                        pp++;
                                        qq += 2;
                                        eat_all = 0;
                                    } else {
                                        pp++;
                                        qq += 3;
                                        eat_all = 0;
                                    }
                                } else {
                                    return true;
                                }
                            }
                        } else {
                            return true;
                        }
                    } else {
                        pp++;
                        qq++;
                    }
                } else {
                    pp++;
                    qq++;
                }
            } else if (*qq == '*') { // match zero or many 
                // can't happen here!
                return false;
            } else { // just match;
                if (*(qq + 1) != '\0') {
                    if (*(qq + 1) == '*') {
                        if (*(qq + 2) != '\0') {
                            if (*pp != *(qq + 2)) {
                                if (*pp != *qq) {
                                    qq += 2;
                                } else {
                                    pp++;
                                    eat_all++;
                                }
                            } else {
                                if (*(qq + 3) != '\0') {
                                    if (*(qq + 3) == '*') {
                                        pp++;
                                        qq += 2;
                                        eat_all = 0;
                                    } else {
                                        pp++;
                                        qq += 3;
                                        eat_all = 0;
                                    }
                                } else {
                                    if (*pp == *qq) {
                                        pp++;
                                    } else {
                                        pp++;
                                        qq += 3;
                                        eat_all = 0;
                                    }
                                }
                            }
                        } else {
                            if (*pp != *qq) {
                                return false;
                            } else {
                                pp++;
                            }
                        }
                    } else {
                        pp++;
                        qq++;
                    }
                } else { // reach end of p;
                    if (*pp == *qq) {
                        pp++;
                        qq++;
                    } else {
                        return false;
                    }
                }
            }
        }  // while

        int last = *(qq - 1);
        int loop = 0;
        while (*qq != '\0' && *(qq + 1) != '\0'
                && *qq != '*' && *(qq + 1) == '*') {
            loop = 1;
            qq += 2;
        }

        int eaten = 0;
        while (*qq == '.') {
            eaten = 1;
            eat_all--;
            qq++;
        }
        if (eaten == 1 && eat_all != 0)
            return false;

        if (*qq == '\0') {
            return true;
        } else {
            if (*(qq + 1) != '\0') {
                if (*qq != '*' && (*(qq + 1) == '*')) {
                    if (*(qq + 2) != '\0') {
                        if (*(qq + 2) == *(pp - 1)) {
                            return true;
                        } else {
                            return false;
                        }
                    } else {
                        return true;
                    }
                } else {
                    return false;
                }
            } else {
                if (loop == 1 && *qq == *(pp - 1)) {
                    if (*qq == last) {
                        return false;
                    } else {
                        return true;
                    }
                } else {
                    return false;
                }
            }
        }

        return false;
    }
};

static void testcase(const char *s, const char *p, bool expected) {
    Solution_Regular_Expression_Matching solution;
    bool result = false;

    result = solution.isMatch(s, p);
    printf("s = %s, p = %s, reslt = %d\n", s, p, result);
    assert(result == expected);
}
int main(int argc, char *argv[]) {
    const char *s = NULL;
    const char *p = NULL;

    s = "aa";
    p = "a";
    testcase(s, p, false);

    s = "aa";
    p = "aa";
    testcase(s, p, true);

    s = "aa";
    p = "aaa";
    testcase(s, p, false);

    s = "aa";
    p = "a*";
    testcase(s, p, true);

    s = "ab";
    p = ".*";
    testcase(s, p, true);

    s = "aab";
    p = "c*a*b";
    testcase(s, p, true);

    s = "ab";
    p = ".*c";
    testcase(s, p, false);

    s = "aaa";
    p = "a*a";
    testcase(s, p, true);

    s = "aaa";
    p = "ab*a*c*a";
    testcase(s, p, true);

    s = "a";
    p = "ab*a";
    testcase(s, p, false);

    s = "ab";
    p = ".*..";
    testcase(s, p, true);

    s = "aasdfasdfasdfasdfas";
    p = "aasdf.*asdf.*asdf.*asdf.*s";
    testcase(s, p, true);

    s = "bbbba";
    p = ".*a*a";
    testcase(s, p, true);

    s = "abbbcd";
    p = "ab*bbbcd";
    testcase(s, p, true);

    s = "abcd";
    p = "d*";
    testcase(s, p, false);

    s = "aaa";
    p = "ab*a";
    testcase(s, p, false);

    s = "aaba";
    p = "ab*a*c*a";
    testcase(s, p, false);

    s = "abcdede";
    p = "ab.*de";
    testcase(s, p, true);

    return 0;
}
