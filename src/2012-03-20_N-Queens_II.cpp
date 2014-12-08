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
 * File: 2012-03-20_N_Queens_II.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/n-queens-ii/
 * Follow up for N-Queens problem.
 *
 * Now, instead outputting board configurations, return the total number of
 * distinct solutions.
 *
 *
 * Date: 2014.12.08
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using std::vector;

// originate from:
// https://oj.leetcode.com/discuss/17950/sharing-my-very-simple-solution-and-easy-to-understand
class Solution_N_Queens_II {
private:
    vector<int> x;
    int total;
public:
    bool place(int k, int i) {
        for (int j = 0; j < k; j++) {
            if (x[j] == i || abs(x[j] - i) == abs(j - k))
                return false;
        }  // for

        return true;
    }

    void rNQ(int k, int n) {
        for (int i = 0; i < n; i++) {
            if (place(k, i)) {
                x[k] = i;
                if (k == n - 1) {
                    total++;
                } else {
                    rNQ(k + 1, n);
                }
            }  // if
        }  // for
    }

    int totalNQueens(int n) {
        int k = 0;

        // intial
        total = 0;
        x.assign(n, 0);

        rNQ(k, n);
        
        return total;
    }

};

int main(int argc, char *argv[]) {
    Solution_N_Queens_II solution;
    int n = 4;
    int total = solution.totalNQueens(n);
    printf("n = %d, total = %d\n", n, total);

    n = 5;
    total = solution.totalNQueens(n);
    printf("n = %d, total = %d\n", n, total);

    n = 6;
    total = solution.totalNQueens(n);
    printf("n = %d, total = %d\n", n, total);

    n = 7;
    total = solution.totalNQueens(n);
    printf("n = %d, total = %d\n", n, total);

    return 0;
}

