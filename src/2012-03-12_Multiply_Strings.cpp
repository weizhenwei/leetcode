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
 * File: 2012-03-12_Multiply_Strings.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/multiply-strings/
 * Given two numbers represented as strings, return multiplication of the
 * numbers as a string.
 *
 * Note: The numbers can be arbitrarily large and are non-negative.
 *
 *
 * Date: 2014.11.01
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <assert.h>
#include <stdio.h>
#include <string>

using std::string;

class Solution_Multiply_Strings {
public:
    string multiply(string num1, string num2) {
        if (num1.size() == 1) {
            if (num1[0] == '0') {
                return string("0");
            }
        }
        if (num2.size() == 1) {
            if (num2[0] == '0') {
                return string("0");
            }
        }

        int i, j, k;
        int len1 = num1.size();
        int len2 = num2.size();
        string result;
        string aline;

        int a, b;
        int current, carry;
        carry = 0;
        current = 0;
        b = num2[num2.size() - 1] - '0';
        for (j = num1.size() - 1; j >= 0; j--) {
            a = num1[j] - '0';
            current = (a * b + carry) % 10 + '0';
            carry = (a * b + carry) / 10;
            aline.insert(aline.begin(), current);
        }
        if (carry > 0) {
            aline.insert(aline.begin(), carry + '0');
        }
        result = string(aline);

        int skip = 1;
        for (i = num2.size() - 2; i >= 0; i--) {
            b = num2[i] - '0';
            if (b == 0) {
                skip++;
                continue;
            }

            carry = 0;
            current = 0;
            aline.clear();
            for (j = num1.size() - 1; j >= 0; j--) {
                a = num1[j] - '0';
                current = (a * b + carry) % 10 + '0';
                carry = (a * b + carry) / 10;
                aline.insert(aline.begin(), current);
            }
            if (carry > 0) {
                aline.insert(aline.begin(), carry + '0');
            }

            string prefix = string(skip, '0');
            result = prefix + result;
            int aa, bb;
            int ccurrent = 0;
            int ccarry = 0;
            int m = aline.size() - 1;
            for (k = result.size() - (num2.size() - i); k >= 0, m >= 0;
                    k--, m--) {
                if (k < 0 || m < 0)
                    break;

                aa = result[k] - '0';
                bb = aline[m] - '0';
                ccurrent = (aa + bb + ccarry) % 10 + '0';
                ccarry = (aa + bb + ccarry) / 10;
                result[k] = ccurrent;
            }

            skip = 1;
            while (m >= 0) {
                bb = aline[m] - '0';
                ccurrent = (bb + ccarry) % 10 + '0';
                ccarry = (bb + ccarry) / 10;
                result.insert(result.begin(), ccurrent);
                m--;
                skip = 0;
            }

            if (ccarry > 0) {
                ccurrent = ccarry + '0';
                if (k >= 0) {
                    result[k] = ccurrent;
                } else {
                    result.insert(result.begin(), ccurrent);
                }
            }
        }

        while (result[0] == '0') {
            result.erase(result.begin());
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution_Multiply_Strings solution;
    string  num1 = string("123");
    string  num2 = string("234");
    string mul = solution.multiply(num1, num2);
    printf("num1 = %s, num2 = %s, multiply = %s\n",
            num1.c_str(), num2.c_str(), mul.c_str());
    assert(mul == string("28782"));

    num1 = string("123000");
    num2 = string("11110");
    mul = solution.multiply(num1, num2);
    printf("num1 = %s, num2 = %s, multiply = %s\n",
            num1.c_str(), num2.c_str(), mul.c_str());
    assert(mul == string("1366530000"));

    num1 = string("123000");
    num2 = string("0");
    mul = solution.multiply(num1, num2);
    printf("num1 = %s, num2 = %s, multiply = %s\n",
            num1.c_str(), num2.c_str(), mul.c_str());
    assert(mul == string("0"));

    num1 = string("123");
    num2 = string("101");
    mul = solution.multiply(num1, num2);
    printf("num1 = %s, num2 = %s, multiply = %s\n",
            num1.c_str(), num2.c_str(), mul.c_str());
    assert(mul == string("12423"));


    num1 = string("123456789");
    num2 = string("987654321");
    mul = solution.multiply(num1, num2);
    printf("num1 = %s, num2 = %s, multiply = %s\n",
            num1.c_str(), num2.c_str(), mul.c_str());
    assert(mul == string("121932631112635269"));

    num1 = string("237");
    num2 = string("284");
    mul = solution.multiply(num1, num2);
    printf("num1 = %s, num2 = %s, multiply = %s\n",
            num1.c_str(), num2.c_str(), mul.c_str());
    assert(mul == string("67308"));

    num1 = string("3");
    num2 = string("38");
    mul = solution.multiply(num1, num2);
    printf("num1 = %s, num2 = %s, multiply = %s\n",
            num1.c_str(), num2.c_str(), mul.c_str());
    assert(mul == string("114"));

    num1 = string("5");
    num2 = string("12");
    mul = solution.multiply(num1, num2);
    printf("num1 = %s, num2 = %s, multiply = %s\n",
            num1.c_str(), num2.c_str(), mul.c_str());
    assert(mul == string("60"));

    return 0;
}
