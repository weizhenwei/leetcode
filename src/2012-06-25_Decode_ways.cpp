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
 * File: 2012-06-25_Decode_Ways.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/decode-ways/
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given an encoded message containing digits, determine the total number of
 * ways to decode it.
 *
 * For example,
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 *
 * The number of ways decoding "12" is 2.
 *
 *
 * Date: 2014.11.19
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <assert.h>
#include <stdio.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution_Decode_Ways {
public:
    int numDecodings(string s) {
        if (s.size() == 0) {
            return 0;
        } else if (s.size() == 1) {
            assert(s[0] >= '0' && s[0] <= '9');
            if (s[0] == '0') {
                return 0;
            } else {
                return 1;
            }
        }

        if (s[0] == 0) {
            return 0;
        }

        assert(s[0] > '0' && s[0] <= '9');
        assert(s[1] >= '0' && s[0] <= '9');
        if (s[1] == '0') {
            if (s.size() == 2) {
                return 1;
            } else {
                s.erase(s.begin());
                s.erase(s.begin());
                return numDecodings(s);
            }
        } else {
            if (s[0] == '1') {
                if (s.size() == 2) {
                    return 2;
                } else {
                    s.erase(s.begin());
                    string first = string(s);
                    int num1 = numDecodings(first);
                    s.erase(s.begin());
                    int num2 = numDecodings(s);
                    return num1 + num2;
                }
            } else if (s[0] == '2') {
                if (s[1] <= '6') {
                    if (s.size() == 2) {
                        return 2;
                    } else {
                        s.erase(s.begin());
                        int num1 = numDecodings(s);
                        s.erase(s.begin());
                        int num2 = numDecodings(s);
                        return num1 + num2;
                    }
                } else {
                    s.erase(s.begin());
                    int num1 = numDecodings(s);
                    return num1;
                }
            } else {
                s.erase(s.begin());
                int num1 = numDecodings(s);
                return num1;
            }
        }
    }

    // one dimensational dynamic programming;
    // originate frome: https://oj.leetcode.com/discuss/13266/my-c-solution
    int numDecodingsGood(string s) {
        if (s.size() == 0)
            return 0;
        if (s[0] == '0') {
            return 0;
        }
        if (s.size() == 1) {
            return 1;
        }

        int first = 1;
        int second = 1;
        int total = 1;
        for (int i = 2; i <= s.size(); i++) {
            int current = 0;
            if (s[i-1] >= '1' && s[i-1] <= '9') {
                current = second;
            }
            if (s[i-2] == '1') {
                current += first;
            } else if (s[i-2] == '2' && s[i-1] >= '0' && s[i-1] <= '6') {
                current += first;
            }

            first = second;
            second = current;
            total = second;
        }

        return total;
    }
};

int main(int argc, char *argv[]) {
    Solution_Decode_Ways solution;
    string s = string("111");
    printf("s = %s, ", s.c_str());
    int num = solution.numDecodings(s);
    printf("num = %d\n", num);

    s = string("1111");
    printf("s = %s, ", s.c_str());
    num = solution.numDecodings(s);
    printf("num = %d\n", num);

    s = string("10");
    printf("s = %s, ", s.c_str());
    num = solution.numDecodingsGood(s);
    printf("num = %d\n", num);

    s = string("0");
    printf("s = %s, ", s.c_str());
    num = solution.numDecodingsGood(s);
    printf("num = %d\n", num);

    s = string("4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948");
    printf("s = %s, ", s.c_str());
    num = solution.numDecodingsGood(s);
    printf("num = %d\n", num);

    s = string("10");
    printf("s = %s, ", s.c_str());
    num = solution.numDecodingsGood(s);
    printf("num = %d\n", num);

    s = string("11");
    printf("s = %s, ", s.c_str());
    num = solution.numDecodingsGood(s);
    printf("num = %d\n", num);

    return 0;
}

