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
 * File: 2012-03-24_Spiral_Matrix.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/spiral-matrix/
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 *
 * For example,
 * Given the following matrix:
 *
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * You should return [1,2,3,6,9,8,7,4,5].
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

class Solution_Spiral_Matrix {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if (matrix.size() == 0) {
            return result;
        }
        if (matrix.size() == 1) {
            return matrix[0];
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
        while (leftMost <= rightMost && upMost <= downMost) {
            if (direction == RIGHT) {
                while (startx <= rightMost) {
                    result.push_back(matrix[starty][startx]);
                    startx++;
                }
                startx--;
                upMost++;
                starty++;
                direction = DOWN;
            } else if (direction == DOWN) {
                while (starty <= downMost) {
                    result.push_back(matrix[starty][startx]);
                    starty++;
                }
                starty--;
                rightMost--;
                startx--;
                direction = LEFT;
            } else if (direction == LEFT) {
                while (startx >= leftMost) {
                    result.push_back(matrix[starty][startx]);
                    startx--;
                }
                startx++;
                downMost--;
                starty--;
                direction = UP;
            } else if (direction == UP) {
                while (starty >= upMost) {
                    result.push_back(matrix[starty][startx]);
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

        return result;
    }
};

static void print_array(vector<int> &v) {
    for(int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

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
    Solution_Spiral_Matrix solution;
    vector<vector<int> > matrix;
    vector<int> elem;
    elem.push_back(1);
    elem.push_back(2);
    elem.push_back(3);
    matrix.push_back(elem);
    elem.clear();
    elem.push_back(4);
    elem.push_back(5);
    elem.push_back(6);
    matrix.push_back(elem);
    elem.clear();
    elem.push_back(7);
    elem.push_back(8);
    elem.push_back(9);
    matrix.push_back(elem);

    print_matrix(matrix);
    vector<int> order = solution.spiralOrder(matrix);
    print_array(order);

    matrix.clear();
    elem.clear();
    elem.push_back(1);
    elem.push_back(2);
    elem.push_back(3);
    elem.push_back(4);
    matrix.push_back(elem);
    elem.clear();
    elem.push_back(5);
    elem.push_back(6);
    elem.push_back(7);
    elem.push_back(8);
    matrix.push_back(elem);
    elem.clear();
    elem.push_back(9);
    elem.push_back(10);
    elem.push_back(11);
    elem.push_back(12);
    matrix.push_back(elem);
    elem.clear();
    elem.push_back(13);
    elem.push_back(14);
    elem.push_back(15);
    elem.push_back(16);
    matrix.push_back(elem);

    print_matrix(matrix);
    order = solution.spiralOrder(matrix);
    print_array(order);

    return 0;
}

