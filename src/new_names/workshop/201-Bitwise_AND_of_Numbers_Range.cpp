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
 * File: 201-Bitwise_AND_of_Numbers_Range.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/bitwise-and-of-numbers-range/
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of
 * all numbers in this range, inclusive.

 * For example, given the range [5, 7], you should return 4.
 *
 *
 * Date: 2015.09.24
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>

class Solution_Bitwise_AND_of_NUmbers_Range {
public:
    // take reference at:
    // https://leetcode.com/discuss/56801/my-simple-recursive-solution-c-68ms
    int rangeBitwiseAnd(int m, int n) {
        if (m == n) {
            return m;
        }

        int range = rangeBitwiseAnd(m >> 1, n >> 1);
        return range << 1;
    }
};

void testcase() {
    Solution_Bitwise_AND_of_NUmbers_Range solution;
    int m = 5;
    int n = 7;
    int range = solution.rangeBitwiseAnd(m, n);
    printf("m = %d, n = %d, range = %d\n", m, n, range);
}

int main(int argc, char *argv[]) {
    testcase();

    return 0;
}
