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
 * File: 2012-03-16_Jump_Game_II.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/jump-game-ii/
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * For example:
 * Given array A = [2,3,1,1,4]
 *
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from
 * index 0 to 1, then 3 steps to the last index.)
 *
 *
 * Date: 2014.12.04
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <vector>

using std::max;
using std::vector;

class Solution_Jump_Game_II {
public:
    bool canJump(int A[], int n) {
        int i = 0;
        int reach = 0;
        for (i = 0, reach = 0; i < n && i <= reach; i++) {
            reach = max(i + A[i], reach);
            if (reach == n) {
                return true;
            }
        }

        return i == n;
    }

    int jump(int A[], int n) {
        int i = 0;
        int reach = 0;
        vector<int> minJump = vector<int>(n, 0);
        for (i = 0, reach = 0; i < n && i <= reach; i++) {
            for (int j = reach + 1; j < n && j <= i + A[i]; j++) {
                minJump[j] = minJump[i] + 1;
            }
            reach = max(i + A[i], reach);
            if (reach >= n) {
                return minJump[n - 1];
            }
        }
        
        return minJump[n - 1];
    }
};

static void print_array(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Jump_Game_II solution;

    int A[5] = {2, 3, 1, 1, 4};
    int n = 5;
    int jump = solution.jump(A, n);
    print_array(A, n);
    printf("jump = %d\n", jump);

    int B[5] = {3, 2, 1, 1, 4};
    n = 5;
    jump = solution.jump(B, n);
    print_array(B, n);
    printf("jump = %d\n", jump);

    int C[5] = {4, 3, 1, 1, 4};
    n = 5;
    jump = solution.jump(C, n);
    print_array(C, n);
    printf("jump = %d\n", jump);

    return 0;
}

