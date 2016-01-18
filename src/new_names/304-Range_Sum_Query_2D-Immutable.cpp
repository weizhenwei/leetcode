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
 * File: 304-Range_Sum_Query_2D-Immutable.cpp
 *
 * Brief: https://leetcode.com/problems/range-sum-query-2d-immutable/
 * Given a 2D matrix matrix, find the sum of the elements inside the rectangle
 * defined by its upper left corner (row1, col1) and lower right corner (row2,
 * col2).
 * Example:
 * Given matrix = [
 *   [3, 0, 1, 4, 2],
 *   [5, 6, 3, 2, 1],
 *   [1, 2, 0, 1, 5],
 *   [4, 1, 0, 1, 7],
 *   [1, 0, 3, 0, 5]
 *   ]
 *   sumRegion(2, 1, 4, 3) -> 8
 *   sumRegion(1, 1, 2, 2) -> 11
 *   sumRegion(1, 2, 2, 4) -> 12
 *
 *
 * Date: 2015.11.17
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <vector>

using std::vector;

template<typename T>
void printMatrix(vector< vector<T> > &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            printf("%ld ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

class NumMatrix {
public:
    NumMatrix(vector< vector<int> > &matrix) {
        if (matrix.size() > 0) {
            m_lSums = vector< vector<long int> >(matrix.size(),
                    vector<long int>(matrix[0].size(), 0));

            long int formerRowsSum = 0;
            for (int i = 0; i < matrix.size(); i++) {
                long int currentRowSum = 0;
                for (int j = 0; j < matrix[i].size(); j++) {
                    m_lSums[i][j] = formerRowsSum + currentRowSum + matrix[i][j];
                    currentRowSum += matrix[i][j];
                }  // for j
                formerRowsSum += currentRowSum;
            }  // for i
        }

        printMatrix(m_lSums);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 < 0 || row2 >= m_lSums.size() || row1 > row2
                || col1 < 0 || col2 >= m_lSums[0].size() || col1 > col2) {
            printf("parameter error!\n");
                return 0;
        }

        int sum = 0;
        for (int i = row1; i <= row2; i++) {
            sum += m_lSums[i][col2] - m_lSums[i][col1];
        }
        int leftlinesum = 0;
        if (col1 == 0) {
            if (row1 == 0) {
                leftlinesum += m_lSums[0][0];
                for (int i = 1; i <= row2; i++) {
                    leftlinesum += m_lSums[i][col1] - m_lSums[i-1][m_lSums[i-1].size()-1];
                }
            } else {
                for (int i = row1; i <= row2; i++) {
                    leftlinesum += m_lSums[i][col1] - m_lSums[i-1][m_lSums[i-1].size()-1];
                }
            }
        } else {
            for (int i = row1; i<= row2; i++) {
                leftlinesum += m_lSums[i][col1] - m_lSums[i][col1-1];
            }
        }

        sum += leftlinesum;

        return sum;
    }
private:
    vector< vector<long int> > m_lSums;
};

void testcase() {
    vector< vector<int> > matrix;
    int row = 5, col = 6;
    for (int i = 0; i < row; i++) {
        vector<int> elem;
        for (int j = 0; j < col; j++) {
            elem.push_back(i + j);
        }  // for j;
        matrix.push_back(elem);
    }  // for i;
    printMatrix(matrix);

    NumMatrix numMatrix = NumMatrix(matrix);
    int row1 = 0, col1 = 0, row2 = 0, col2 = 0, sum = 0;

    row1 = 0, col1 = 0, row2 = 0, col2 = 0, sum = 0;
    sum = numMatrix.sumRegion(row1, col1, col2, col2);
    printf("row1 = %d, col1 = %d, row2 = %d, col2 = %d, sum = %d\n",
            row1, col1, row2, col2, sum);

    row1 = 0, col1 = 0, row2 = 1, col2 = 1, sum = 0;
    sum = numMatrix.sumRegion(row1, col1, col2, col2);
    printf("row1 = %d, col1 = %d, row2 = %d, col2 = %d, sum = %d\n",
            row1, col1, row2, col2, sum);

    row1 = 0, col1 = 0, row2 = 4, col2 = 5, sum = 0;
    sum = numMatrix.sumRegion(row1, col1, row2, col2);
    printf("row1 = %d, col1 = %d, row2 = %d, col2 = %d, sum = %d\n",
            row1, col1, row2, col2, sum);

    row1 = 0, col1 = 0, row2 = 0, col2 = 5, sum = 0;
    sum = numMatrix.sumRegion(row1, col1, row2, col2);
    printf("row1 = %d, col1 = %d, row2 = %d, col2 = %d, sum = %d\n",
            row1, col1, row2, col2, sum);

    row1 = 0, col1 = 0, row2 = 3, col2 = 0, sum = 0;
    sum = numMatrix.sumRegion(row1, col1, row2, col2);
    printf("row1 = %d, col1 = %d, row2 = %d, col2 = %d, sum = %d\n",
            row1, col1, row2, col2, sum);
    row1 = 0, col1 = 0, row2 = 4, col2 = 0, sum = 0;
    sum = numMatrix.sumRegion(row1, col1, row2, col2);
    printf("row1 = %d, col1 = %d, row2 = %d, col2 = %d, sum = %d\n",
            row1, col1, row2, col2, sum);

    row1 = 0, col1 = 5, row2 = 3, col2 = 5, sum = 0;
    sum = numMatrix.sumRegion(row1, col1, row2, col2);
    printf("row1 = %d, col1 = %d, row2 = %d, col2 = %d, sum = %d\n",
            row1, col1, row2, col2, sum);
    row1 = 0, col1 = 5, row2 = 4, col2 = 5, sum = 0;
    sum = numMatrix.sumRegion(row1, col1, row2, col2);
    printf("row1 = %d, col1 = %d, row2 = %d, col2 = %d, sum = %d\n",
            row1, col1, row2, col2, sum);

    row1 = 1, col1 = 2, row2 = 3, col2 = 4, sum = 0;
    sum = numMatrix.sumRegion(row1, col1, row2, col2);
    printf("row1 = %d, col1 = %d, row2 = %d, col2 = %d, sum = %d\n",
            row1, col1, row2, col2, sum);
    row1 = 1, col1 = 2, row2 = 4, col2 = 5, sum = 0;
    sum = numMatrix.sumRegion(row1, col1, row2, col2);
    printf("row1 = %d, col1 = %d, row2 = %d, col2 = %d, sum = %d\n",
            row1, col1, row2, col2, sum);
}

int main(int argc, char *argv[]) {
    testcase();

    return 0;
}
