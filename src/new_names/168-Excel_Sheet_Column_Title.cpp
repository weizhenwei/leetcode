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
 * File: 168-Excel_Sheet_Column_Title.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/excel-sheet-column-title/
 * Given a positive integer, return its corresponding column title as appear in
 * an Excel sheet.
 *
 * For example:
 *
 *     1 -> A
 *     2 -> B
 *     3 -> C
 *     ...
 *     26 -> Z
 *     27 -> AA
 *     28 -> AB 
 *
 *
 * Date: 2015.01.07
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <math.h>
#include <stdio.h>
#include <string>
using std::string;

class Solution_Excel_Sheet_Column_Title {
public:
    string convertToTitle(int n) {
        string result;
        for (; n > 0; n /= 26) {
            n--;
            char c = n % 26 + 'A';
            result.insert(result.begin(), c);
        }

        return result;
    }

};

int main(int argc, char *argv[]) {
    Solution_Excel_Sheet_Column_Title solution;
    int n = 701;
    string s = solution.convertToTitle(n);
    printf("n = %d, s = %s\n", n, s.c_str());

    return 0;
}

