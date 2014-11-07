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
 * File: 2012-04-06_Search_a_2D_Matrix.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/search-a-2d-matrix/
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * For example,
 *
 * Consider the following matrix:
 *
 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * Given target = 3, return true.
 *
 *
 * Date: 2014.11.07
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <assert.h>
#include <stdio.h>
#include <vector>

using std::vector;

class Solution_Search_a_2D_Matrix {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size() == 0)
            return false;
        if (matrix[0].size() == 0)
            return false;

        int m = matrix.size();
        int n = matrix[0].size();

        int left, right, middle;
        left = 0;
        right = m * n - 1;
        middle = (left + right) / 2;
        while (left <= right) {  // binary search!
            int x = middle / n;  // row;
            int y = middle % n;  // column;
            vector<int> v = matrix[x];

            if (v[y] == target) {
                return true;
            }

            if (v[y] < target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
            middle = (left + right) / 2;
        }  // while

        return false;
    }
};

static void print_vector(vector<vector<int> > &matrix) {
    int row = matrix.size();
    int column = matrix[0].size();

    for(int i = 0; i < row; i++) {
        vector<int> v = matrix[i];
        for (int j = 0; j < column; j++) {
            printf("%d ", v[j]);
        }
        printf("\n");
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Search_a_2D_Matrix solution;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    vector<vector<int> > matrix;

    v1.clear();
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    matrix.push_back(v1);

    v2.clear();
    v2.push_back(5);
    v2.push_back(6);
    v2.push_back(7);
    v2.push_back(8);
    matrix.push_back(v2);

    v3.clear();
    v3.push_back(9);
    v3.push_back(10);
    v3.push_back(11);
    v3.push_back(12);
    matrix.push_back(v3);

    v4.clear();
    v4.push_back(13);
    v4.push_back(14);
    v4.push_back(15);
    v4.push_back(16);
    matrix.push_back(v4);

    print_vector(matrix);
    int target = 1;
    bool result = solution.searchMatrix(matrix, target);
    printf("target = %d, result = %d\n", target, result);

    target = 2;
    result = solution.searchMatrix(matrix, target);
    printf("target = %d, result = %d\n", target, result);

    target = 3;
    result = solution.searchMatrix(matrix, target);
    printf("target = %d, result = %d\n", target, result);

    target = 4;
    result = solution.searchMatrix(matrix, target);
    printf("target = %d, result = %d\n", target, result);

    target = 6;
    result = solution.searchMatrix(matrix, target);
    printf("target = %d, result = %d\n", target, result);

    target = 0;
    result = solution.searchMatrix(matrix, target);
    printf("target = %d, result = %d\n", target, result);

    target = 16;
    result = solution.searchMatrix(matrix, target);
    printf("target = %d, result = %d\n", target, result);

    target = 17;
    result = solution.searchMatrix(matrix, target);
    printf("target = %d, result = %d\n", target, result);

    matrix.clear();
    matrix.push_back(v4);
    print_vector(matrix);
    target = 16;
    result = solution.searchMatrix(matrix, target);
    printf("target = %d, result = %d\n", target, result);
    target = 17;
    result = solution.searchMatrix(matrix, target);
    printf("target = %d, result = %d\n", target, result);

    return 0;
}

