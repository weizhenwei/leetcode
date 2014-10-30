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
 * File: 2012-04-03_Climbing_Stairs.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/climbing-stairs/
 *
 *
 * Date: 2014.10.30
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <assert.h>
#include <stdio.h>

class Solution_Climbing_Stairs {
public:
    int climbStairs_iterative(int n) {  // so called Fibonacci Sequence
        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }

        int n1 = 1;
        int n2 = 2;
        int i = 3;
        int result = n2;
        while (i <= n) {
            result = n1 + n2;
            n1 = n2;
            n2 = result;
            i++;
        }

        return result;
    }

    int climbStairs_recursive(int n) {
        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }

        return climbStairs_recursive(n - 1) + climbStairs_recursive(n - 2);
    }
};

int main(int argc, char *argv[]) {
    Solution_Climbing_Stairs solution;
    int n1 = 0, n2 = 0;
    for (int i = 1;  i <= 30; i++) {
        n1 = solution.climbStairs_iterative(i);
        n2 = solution.climbStairs_recursive(i);
        assert(n1 == n2);
        printf("i = %d, n1 = %d, n2 = %d\n", i, n1, n2);
    }

    return 0;
}
