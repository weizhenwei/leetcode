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
 * File: 279-Perfect_Squares.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/perfect-squares/
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 *
 * For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13,
 * return 2 because 13 = 4 + 9.
 *
 *
 * Date: 2015.09.09
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <math.h>

#include <vector>

using std::vector;

class Solution_Perfect_Squares {
public:
    int numSquares(int n) {
        int sq = sqrt(n);
        if (n - sq * sq == 0) {
            return 1;
        } else {
            int num = 0;
            vector<int> array(n + 1);
            array[1] = 1;
            for (int i = 2; i <= n; i++) {
                int sq = sqrt(i);
                if (i - sq * sq == 0) {
                    array[i] = 1;
                } else {
                    array[i] = i;
                    for (int j = 1; j <= sqrt(i); j++) {
                        if (array[i] > array[i-j*j] + 1) {
                            array[i] = array[i-j*j] + 1;
                        }
                    }
                }
            }

            return array[n];
        }
    }
};

void testcase() {
    Solution_Perfect_Squares solution;
    for (int i = 1; i < 100; i++) {
        int num = solution.numSquares(i);
        printf("i = %d, num = %d\n", i, num);
    }
}

int main(int argc, char *argv[]) {
    testcase();

    return 0;
}
