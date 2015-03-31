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
 * File: 190-Reverse_Bits.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/reverse-bits/
 * Reverse bits of a given 32 bits unsigned integer.
 *
 * For example, given input 43261596 (represented in binary as
 * 00000010100101000001111010011100), return 964176192 (represented in binary as
 * 00111001011110000010100101000000).
 *
 *
 * Date: 2015.03.31
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdint.h>

using std::swap;

class Solution_Reverse_Bits {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned char bits[32];
        uint32_t radix = 1;
        for (int i = 0; i < 32; i++) {
            radix = pow(2, i);
            uint32_t tmp = n & radix;
            if (tmp > 0) {
                bits[i] = '1';
            } else {
                bits[i] = '0';
            }
        }

        int start = 0;
        int end = 31;
        while (start < end) {
            swap(bits[start], bits[end]);
            start++;
            end--;
        }

        radix = 1;
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            radix = pow(2, i);
            result += radix * (bits[i] - '0');
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution_Reverse_Bits solution;
    uint32_t n = 43261596;
    uint32_t reverse = solution.reverseBits(n);
    printf("n = %d, reverse_n = %d\n", n, reverse);

    return 0;
}

