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
 * File: 2012-04-05_Set_Matrix_Zeroes.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/set-matrix-zeroes/
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0.
 * Do it in place.
 *
 * Follow up:
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 *
 *
 * Date: 2014.12.06
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <vector>

using std::vector;

class Solution_Set_Matrix_Zeroes {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.size() == 0)
            return;

        bool firstrowzero = false, firstcolzero = false;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                    firstrowzero = firstrowzero || (i == 0);
                    firstcolzero = firstcolzero || (j == 0);
                }  // if
            }  // for j
        }  // for i

        for (int i = 1; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                matrix[i].assign(matrix[i].size(), 0);
            }  // if
        }  // for i

        for (int i = 1; i < matrix[0].size(); i++) {
            if (matrix[0][i] == 0) {
                for (int j = 0; j < matrix.size(); j++) {
                    matrix[j][i] = 0;
                }  // for j
            }  // if
        }  // for i

        if (firstrowzero == true) {
            matrix[0].assign(matrix[0].size(), 0);
        }

        if (firstcolzero == true) {
            for (int j = 0; j < matrix.size(); j++) {
                matrix[j][0] = 0;
            }
        }
    }

};

static void print_matrix(vector<vector<int> > &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            printf("%d ", matrix[i][j]);
        }  // for j
        printf("\n");
    }  // for i
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Set_Matrix_Zeroes solution;
    vector<vector<int> > matrix;
    int m = 4;
    int n = 3;
    for (int i = 0; i < m; i++) {
        vector<int> elem = vector<int>(n, 1);
        matrix.push_back(elem);
    }

    matrix[2][1] = 0;
    print_matrix(matrix);
    solution.setZeroes(matrix);
    print_matrix(matrix);

    return 0;
}

