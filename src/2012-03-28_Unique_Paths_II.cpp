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

class Solution_Unique_Paths_II {
public:
    int uniquePathsWithObstackes(vector<vector<int> > &obstacleGrid) {
        vector<vector<int> > matrix;
        vector<int> elem;
        for (int j = 0; j < obstacleGrid[0].size(); j++) {
            if (obstacleGrid[0][j] == 1) {
                int n = obstacleGrid[0].size() - j;
                elem.insert(elem.begin() + elem.size(), n, 0);
                break;
            } else {
                elem.push_back(1);
            }
        }  // for
        matrix.push_back(elem);

        for (int i = 1; i < obstacleGrid.size(); i++) {
            elem.clear();
            for (int j = 0; j < obstacleGrid[i].size(); j++) {
                if (j == 0) {
                    if (obstacleGrid[i][j] == 1) {
                        elem.push_back(0);
                    } else {
                        elem.push_back(matrix[i-1][j]);
                    }
                } else {
                    if (obstacleGrid[i][j] == 1) {
                        elem.push_back(0);
                    } else {
                        elem.push_back(matrix[i-1][j] + elem[j-1]);
                    }
                }
            }  // for j
            matrix.push_back(elem);
        }  // for i

        return matrix[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }

};

static void print_matrix(vector<vector<int> > &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Unique_Paths_II solution;
    vector<vector<int> > obstacleGrid;
    vector<int> elem;
    elem.push_back(0);
    elem.push_back(0);
    elem.push_back(0);
    obstacleGrid.push_back(elem);
    elem.clear();
    elem.push_back(0);
    elem.push_back(1);
    elem.push_back(0);
    obstacleGrid.push_back(elem);
    elem.clear();
    elem.push_back(0);
    elem.push_back(0);
    elem.push_back(0);
    obstacleGrid.push_back(elem);

    print_matrix(obstacleGrid);
    int paths = solution.uniquePathsWithObstackes(obstacleGrid);
    printf("unique paths = %d\n", paths);

    obstacleGrid.clear();
    elem.clear();
    elem.push_back(1);
    elem.push_back(0);
    elem.push_back(0);
    obstacleGrid.push_back(elem);
    elem.clear();
    elem.push_back(0);
    elem.push_back(0);
    elem.push_back(0);
    obstacleGrid.push_back(elem);
    elem.clear();
    elem.push_back(0);
    elem.push_back(0);
    elem.push_back(0);
    obstacleGrid.push_back(elem);
    print_matrix(obstacleGrid);
    paths = solution.uniquePathsWithObstackes(obstacleGrid);
    printf("unique paths = %d\n", paths);

    return 0;
}

