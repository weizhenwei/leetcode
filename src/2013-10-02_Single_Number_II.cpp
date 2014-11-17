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
 * File: 2013-10-02_Single_Number_II.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/single-number-ii/
 * Given an array of integers, every element appears three times except for one.
 * Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 *
 *
 * Date: 2014.11.04
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <map>

using std::map;

class Solution_Single_Number_II {
public:
    int singleNumber(int A[], int n) {
        if (n == 1) {
            return A[0];
        }
        
        map<int, int> sets;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (sets.find(A[i]) == sets.end()) {
                sets[A[i]] = A[i];
            }
            sum += A[i];
        }  // for

        int sum2 = 0;
        map<int, int>::iterator iter;
        for (iter = sets.begin(); iter != sets.end(); iter++) {
            sum2 += (*iter).first;
        }

        return sum - (sum - sum2) / 2 * 3;
    }
};

static void print_array(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    printf("\n");
}
int main(int argc, char *argv[]) {
    Solution_Single_Number_II solution;
    int A[5] = {1, 2, 1, 1};
    int n = 4;
    int single = solution.singleNumber(A, n);
    print_array(A, n);
    printf("Single number is %d\n", single);

    int B[7] = {3, 1, 3, 4, 1, 1, 3};
    n = 7;
    single = solution.singleNumber(B, n);
    print_array(B, n);
    printf("Single number is %d\n", single);

    return 0;
}

