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
 * File: 2012-03-28_Unique_Paths.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/unique-paths/
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 *
 * How many possible unique paths are there?
 *
 * Note: m and n will be at most 100;
 *
 *
 * Date: 2014.11.16
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <vector>

using std::vector;

class Solution_Unique_Paths {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0)
            return 0;
        if (m == 1 || n == 1) {
            return 1;
        }

        vector<vector<int> > matrix;
        vector<int> elem = vector<int>(n, 1);
        matrix.push_back(elem);
        for (int i = 1; i < m; i++) {
            elem.clear();
            elem.push_back(1);
            for (int j = 1; j < n; j++) {
                elem.push_back(matrix[i-1][j] + elem[j-1]);
            }
            matrix.push_back(elem);
        }
        return matrix[m-1][n-1];
    }

};

int main(int argc, char *argv[]) {
    Solution_Unique_Paths solution;
    int m = 1;
    int n = 1;
    int paths = solution.uniquePaths(m, n);
    printf("m = %d, n = %d, paths = %d\n", m, n, paths);

    m = 1;
    n = 3;
    paths = solution.uniquePaths(m, n);
    printf("m = %d, n = %d, paths = %d\n", m, n, paths);

    m = 3;
    n = 1;
    paths = solution.uniquePaths(m, n);
    printf("m = %d, n = %d, paths = %d\n", m, n, paths);

    m = 3;
    n = 2;
    paths = solution.uniquePaths(m, n);
    printf("m = %d, n = %d, paths = %d\n", m, n, paths);

    m = 23;
    n = 12;
    paths = solution.uniquePaths(m, n);
    printf("m = %d, n = %d, paths = %d\n", m, n, paths);

    m = 3;
    n = 3;
    paths = solution.uniquePaths(m, n);
    printf("m = %d, n = %d, paths = %d\n", m, n, paths);

    m = 2;
    n = 2;
    paths = solution.uniquePaths(m, n);
    printf("m = %d, n = %d, paths = %d\n", m, n, paths);

    return 0;
}

