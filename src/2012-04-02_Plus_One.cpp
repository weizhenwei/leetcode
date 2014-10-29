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
 * File: 2011-04-02_Plus_One.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/plus-one/
 * Given a non-negative number represented as an array of digits, plus one to
 * the number.
 *
 * The digits are stored such that the most significant digit is at the head of
 * the list.
 *
 *
 * Date: 2014.10.29
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <assert.h>
#include <stdio.h>
#include <vector>

using std::vector;

class Solution_Plus_One {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> result;
        if (digits.size() == 0) {
            return result;
        }

        int carry = 1;
        int i = digits.size() - 1;
        while (i >= 0) {
            int digit = digits[i];
            int sum = digit + carry;
            if (sum == 10) {
                carry = 1;
                result.insert(result.begin(), 0);
                i--;
            } else {
                carry = 0;
                result.insert(result.begin(), sum);
                i--;
                break;
            }
        }  // while

        if (i < 0) {
            if (carry == 1) {
                result.insert(result.begin(), 1);
            }
        } else {
            while (i >= 0) {
                int digit = digits[i];
                int sum = digit + carry;
                if (sum == 10) {
                    carry = 1;
                    result.insert(result.begin(), 0);
                    i--;
                } else {
                    carry = 0;
                    result.insert(result.begin(), sum);
                    i--;
                }
            }
        }

        return result;
    }
};

static void print_vector(vector<int> &digits) {
    vector<int>::iterator iter;
    for (iter = digits.begin(); iter != digits.end(); iter++) {
        printf("%d", *iter);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Plus_One solution;
    vector<int> digits;
    vector<int> add_one;

    digits.clear();
    digits.push_back(1);
    printf("Before add one:");
    print_vector(digits);
    add_one = solution.plusOne(digits);
    printf("After  add one:");
    print_vector(add_one);

    digits.clear();
    digits.push_back(9);
    printf("Before add one:");
    print_vector(digits);
    add_one = solution.plusOne(digits);
    printf("After  add one:");
    print_vector(add_one);

    digits.clear();
    digits.push_back(1);
    digits.push_back(2);
    digits.push_back(3);
    printf("Before add one:");
    print_vector(digits);
    add_one = solution.plusOne(digits);
    printf("After  add one:");
    print_vector(add_one);

    digits.clear();
    digits.push_back(1);
    digits.push_back(2);
    digits.push_back(9);
    printf("Before add one:");
    print_vector(digits);
    add_one = solution.plusOne(digits);
    printf("After  add one:");
    print_vector(add_one);

    digits.clear();
    digits.push_back(1);
    digits.push_back(9);
    digits.push_back(9);
    printf("Before add one:");
    print_vector(digits);
    add_one = solution.plusOne(digits);
    printf("After  add one:");
    print_vector(add_one);

    digits.clear();
    digits.push_back(9);
    digits.push_back(9);
    digits.push_back(9);
    digits.push_back(9);
    printf("Before add one:");
    print_vector(digits);
    add_one = solution.plusOne(digits);
    printf("After  add one:");
    print_vector(add_one);

    return 0;
}
