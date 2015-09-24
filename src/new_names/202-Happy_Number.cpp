/*
 *
 * Copyright (c) 2015, weizhenwei
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
 * File: 202-Happy_Number.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/happy-number/
 * Write an algorithm to determine if a number is "happy".

 * A happy number is a number defined by the following process: Starting with any
 * positive integer, replace the number by the sum of the squares of its digits,
 * and repeat the process until the number equals 1 (where it will stay), or it
 * loops endlessly in a cycle which does not include 1. Those numbers for which
 * this process ends in 1 are happy numbers.

 * Example: 19 is a happy number
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 *
 * Date: 2015.09.24
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <set>

using std::set;

class Solution_Happy_Number {
public:
    bool isHappy(int n) {
        if (n == 1) {
            return true;
        }
        set<long int> sets;
        int current = n;
        while (1) {
            long int total = 0;
            while (current != 0) {
                int remainder= current % 10;
                total += remainder * remainder;
                current /= 10;
            }
            
            if (total == 1) {
                return true;
            } else if (sets.find(total) != sets.end()) {
                return false;
            } else {
                sets.insert(total);
                current = total;
            }
        }
    }
};

void testcase() {
    Solution_Happy_Number solution;
    int num = 19;
    bool is = false;

    is = solution.isHappy(num);
    printf("num = %d, isHappy = %d\n", num, is);
}

int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

