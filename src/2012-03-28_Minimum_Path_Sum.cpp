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
 * File: 2012-03-28_Minimum_Path_Sum.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/minimum-path-sum/
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 *
 * Date: 2014.11.01
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <vector>

using std::vector;

static void print_grid(vector<vector<int> > &grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

class Solution_Minimum_Path_Sum {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.size() == 0)
            return 0;

        vector<vector<int> > matrix;
        for (int i = 0; i < grid.size(); i++) {
            vector<int> elem = vector<int>(grid[i].size(), 0);
            matrix.push_back(elem);
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (i == 0) {
                    if (j == 0) {
                        matrix[i][j] += grid[i][j];
                    } else {
                        matrix[i][j] += matrix[i][j-1] + grid[i][j];
                    }
                } else if (j == 0) {
                    if (i == 0) {  // impossible to reach here
                        matrix[i][j] += grid[i][j];
                    } else {
                        matrix[i][j] += matrix[i-1][j] + grid[i][j];
                    }
                } else {
                    if (matrix[i-1][j] > matrix[i][j-1]) {
                        matrix[i][j] = matrix[i][j-1] + grid[i][j];
                    } else {
                        matrix[i][j] = matrix[i-1][j] + grid[i][j];
                    }
                }
            }  // for inner
        }  // for outer

        print_grid(matrix);

        return matrix[grid.size()-1][grid[0].size()-1];
    }

};

int main(int argc, char *argv[]) {
    Solution_Minimum_Path_Sum solution;
    vector<vector<int> > grid;
    int m = 4;
    int n = 3;
    for (int i = 0; i < m; i++) {
        vector<int> elem;
        for (int j = 0; j < n; j++) {
            elem.push_back((i + 1) * (j + 1));
        }
        grid.push_back(elem);
    }

    print_grid(grid);
    int min = solution.minPathSum(grid);
    printf("min path = %d\n", min);

    return 0;
}

