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
 * File: 264-Ugly_Number_II.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/ugly-number-ii/
 * Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 *
 * Note that 1 is typically treated as an ugly number.
 *
 * Date: 2015.09.15
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <algorithm>
#include <vector>

using std::min;
using std::vector;

// 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 
// 15, 16, 18, 20, 24, 25, 27, 30, 32, 36
class Solution_Ugly_Number_II {
public:
    int minThree(int t1, int t2, int t3) {
        return min(min(t1, t2), t3);
    }

    int nthUgly(int n) {
        int firstFive[] = {1, 2, 3, 4, 5};
        int count = sizeof(firstFive) / sizeof(int);
        vector<int> uglyNumbers(firstFive, firstFive + count);

        if (n < 5) {
            return uglyNumbers[n-1];
        }

        int index2 = 2;
        int index3 = 1;
        int index5 = 1;
        int min = 5;
        int nth = 5;
        while (nth < n) {
            while (uglyNumbers[index2] * 2 <= min) {
                index2++;
            }
            while (uglyNumbers[index3] * 3 <= min) {
                index3++;
            }
            while (uglyNumbers[index5] * 5 <= min) {
                index5++;
            }

            int min2 = uglyNumbers[index2] * 2;
            int min3 = uglyNumbers[index3] * 3;
            int min5 = uglyNumbers[index5] * 5;
            min = minThree(min2, min3, min5);
            uglyNumbers.push_back(min);
            nth++;
        }
        return min;
    }
};

void testcase() {
    Solution_Ugly_Number_II solution;
    for (int i = 1; i <= 21; i++) {
        printf("i = %d, ithUgly = %d\n", i, solution.nthUgly(i));
    }
}

int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

