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
 * File: 152-Maximum_Product_Subarray.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/maximum-product-subarray/
 * Find the contiguous subarray within an array (containing at least one number)
 * which has the largest product.
 *
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 *
 *
 * Date: 2015.01.21
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <limits.h>
#include <algorithm>

using std::max;

// originates from:
// https://oj.leetcode.com/discuss/15134/simpler-solution-with-6-lines-code-o-n-complexity
class Solution_Maximum_Product_Subarray {
public:
    int maxProduct(int A[], int n) {
        int b = 1;
        int f = 1;
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            res = max(res, max(b *= A[i], f *= A[n-i-1]));
            if (b == 0) {
                b = 1;
            }
            if (f == 0) {
                f = 1;
            }
        }  // for

        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution_Maximum_Product_Subarray solution;
    int A[6] = {-5, 2, 3, -2, 4, -6};
    int max = solution.maxProduct(A, 6);
    printf("max = %d\n", max);

    return 0;
}

