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
 * File: 2011-12-05_ZigZag_Conversion.cpp
 *
 * Brief: https://oj.leetcode.com/problems/zigzag-conversion/
 * The string "PAYPALISHIRING" is written in a zigzag pattern
 * on a given number of rows like this: (you may want to display this pattern
 * in a fixed font for better legibility)
 *
 *  P   A   H   N
 *  A P L S I I G
 *  Y   I   R
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion
 * given a number of rows:
 *     string convert(string text, int nRows);
 *
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 *
 * Date: 2014.10.22
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <math.h>
#include <string>

using std::string;

class Solution_ZigZag_Conversion {
public:
    void convert(string s, int nRows) {
        int i = 0, j = 0;
        int len = s.length();
        int k = (int) ceil((double) len / (2 * nRows - 2));

        printf("after:");
        for (i = 0; i < nRows; i++) {
            for (j = 0; j < k; j++) {
                int a = j * (2 * nRows - 2) + i;
                int b = j * (2 * nRows - 2) + i + 2 * (nRows - i - 1);
                if ((a < len) && (a < j * (2 * nRows - 2) + 2 * nRows -2)) {
                    printf("%c", s[a]);
                }

                if ((b < len) && (b > a) &&
                        (b < j * (2 * nRows - 2) + 2 * nRows - 2)) {
                    printf("%c", s[b]);
                }
            }  // for
        }  // for

        printf("\n");
    }
};

int main(int argc, char *argv[]) {
    Solution_ZigZag_Conversion zc;
    int nRows = 6;
    string s = "abcdefghijklmnopqrstuvwxyz";
    printf("before:nRows = %d, string = %s\n", nRows, s.c_str());
    zc.convert(s, nRows);

    return 0;
}
