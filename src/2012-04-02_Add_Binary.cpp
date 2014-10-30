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
 * File: 2012-04-02_Add_Binary.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/add-binary/
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 *
 *
 * Date: 2014.10.30
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <string>

using std::string;

class Solution_Add_Binary {
public:
    string addBinary(string a, string b) {
        if (a.size() == 0)
            return b;
        if (b.size() == 0)
            return a;

        string c;
        int aidx = a.size() - 1;
        int bidx = b.size() - 1;
        int carry = 0;
        while (aidx >= 0 && bidx >= 0) {
            int achar = a[aidx] - '0';
            int bchar = b[bidx] - '0';
            int sum =  achar + bchar + carry;
            carry = sum / 2;
            sum = sum % 2 + '0';
            c.insert(c.begin(), sum);

            aidx--;
            bidx--;
        }

        while (aidx >= 0) {
            int achar = a[aidx] - '0';
            int sum =  achar + carry;
            carry = sum / 2;
            sum = sum % 2 + '0';
            c.insert(c.begin(), sum);

            aidx--;
        }
        while (bidx >= 0) {
            int bchar = b[bidx] - '0';
            int sum =  bchar + carry;
            carry = sum / 2;
            sum = sum % 2 + '0';
            c.insert(c.begin(), sum);

            bidx--;
        }

        if (carry == 1) {
            c.insert(c.begin(), carry + '0');
        }

        return c;
    }
};

int main(int argc, char *argv[]) {
    Solution_Add_Binary solution;
    string a = string("0");
    string b = string("0");
    string c = solution.addBinary(a, b);
    printf("a = %s, b = %s, c = %s\n", a.c_str(), b.c_str(), c.c_str());

    a = string("11111");
    b = string("00000");
    c = solution.addBinary(a, b);
    printf("a = %s, b = %s, c = %s\n", a.c_str(), b.c_str(), c.c_str());

    a = string("11111");
    b = string("0");
    c = solution.addBinary(a, b);
    printf("a = %s, b = %s, c = %s\n", a.c_str(), b.c_str(), c.c_str());

    a = string("11111");
    b = string("1");
    c = solution.addBinary(a, b);
    printf("a = %s, b = %s, c = %s\n", a.c_str(), b.c_str(), c.c_str());

    a = string("11111");
    b = string("11111");
    c = solution.addBinary(a, b);
    printf("a = %s, b = %s, c = %s\n", a.c_str(), b.c_str(), c.c_str());

    return 0;
}
