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
 * File: 204-Count_Primes.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/count-primes/
 * Description:

 * Count the number of prime numbers less than a non-negative number, n.
 *
 *
 * Date: 2015.09.26
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */ 
#include <stdio.h>
#include <math.h>
#include <vector>

using std::vector;

class Solution_Count_Primes {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }

        int isqrt = sqrt(n);
        vector<int> theVector = vector<int>(n + 1, 1);
        theVector[0] = 0;
        theVector[1] = 0;

        // Eratosthenes Sieve to search prime number;
        for (int i = 2; i <= isqrt; i++) {
            if (theVector[i] == 0) {
                continue;
            } else {
                int j = 2;
                while (j * i <= n) {
                    theVector[j*i] = 0;
                    j++;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (theVector[i] == 1) {
                count++;
            }
        }  // for

        return count;
    }
};

void testcase() {
    Solution_Count_Primes solution;
    for (int i = 0; i <= 100; i++) {
        printf("i = %d, prime count = %d\n", i, solution.countPrimes(i));
    }
}

int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

