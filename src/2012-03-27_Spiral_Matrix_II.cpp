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
 * File: 2012-03-27_Spiral_Matrix_II.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/spiral-matrix-ii/
 * Given an integer n, generate a square matrix filled with elements from 1 to
 * n2 in spiral order.
 *
 * For example,
 * Given n = 3,
 *
 * You should return the following matrix:
 * [
 *  [ 1, 2, 3 ],
 *  [ 8, 9, 4 ],
 *  [ 7, 6, 5 ]
 * ]
 *
 *
 * Date: 2014.11.17
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <assert.h>
#include <stdio.h>
#include <vector>

using std::vector;

class Solution_Spiral_Matrix_II {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix;
        if (n == 0) {
            return matrix;
        }
        if (n == 1) {
            vector<int> elem;
            elem.push_back(1);
            matrix.push_back(elem);
            return matrix;
        }

        for (int i = 0; i < n; i++) {
            vector<int> elem = vector<int>(n, 1);
            matrix.push_back(elem);
        }

        enum {
            RIGHT,
            LEFT,
            DOWN,
            UP,
        } direction = RIGHT;

        int startx = 0;
        int starty = 0;
        int leftMost = 0;
        int rightMost = matrix[0].size() - 1;
        int upMost = 0;
        int downMost = matrix.size() - 1;
        int current = 1;
        while (leftMost <= rightMost && upMost <= downMost) {
            if (direction == RIGHT) {
                while (startx <= rightMost) {
                    matrix[starty][startx] = current;
                    current++;
                    startx++;
                }
                startx--;
                upMost++;
                starty++;
                direction = DOWN;
            } else if (direction == DOWN) {
                while (starty <= downMost) {
                    matrix[starty][startx] = current;
                    current++;
                    starty++;
                }
                starty--;
                rightMost--;
                startx--;
                direction = LEFT;
            } else if (direction == LEFT) {
                while (startx >= leftMost) {
                    matrix[starty][startx] = current;
                    current++;
                    startx--;
                }
                startx++;
                downMost--;
                starty--;
                direction = UP;
            } else if (direction == UP) {
                while (starty >= upMost) {
                    matrix[starty][startx] = current;
                    current++;
                    starty--;
                }
                starty++;
                leftMost++;
                startx++;
                direction = RIGHT;
            } else {
                assert(0);
            }

        }  // while

        return matrix;
    }
};

static void print_matrix(vector<vector<int> > &v) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Spiral_Matrix_II solution;
    int n = 1;
    vector<vector<int> > matrix = solution.generateMatrix(n);
    print_matrix(matrix);

    n = 2;
    matrix = solution.generateMatrix(n);
    print_matrix(matrix);

    n = 3;
    matrix = solution.generateMatrix(n);
    print_matrix(matrix);

    n = 4;
    matrix = solution.generateMatrix(n);
    print_matrix(matrix);

    return 0;
}

