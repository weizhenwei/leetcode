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
 * File: 2012-03-17_Rotate_Image.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/rotate-image/
 * You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 *
 * Follow up:
 * Could you do this in-place?
 *
 *
 * Date: 2014.10.21
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <vector>

using std::vector;

class Solution_Rotate_Image {
public:
    void rotate(vector<vector<int> > &matrix) {
        if (matrix.size() <= 1) {
            return;
        }
        vector<vector<int> > middle;
        for (int j = 0; j < matrix.size(); j++) {
            vector<int> elem;
            for (int i = matrix[0].size() - 1; i >= 0; i--) {
                elem.push_back(matrix[i][j]);
            }
            middle.push_back(elem);
        }
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                matrix[i][j] = middle[i][j];
            }
        }
    }
};

static void print_matrix(vector<vector<int> > &matrix) {
    for(int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Rotate_Image solution;
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
    printf("Before rotate:\n");
    print_matrix(matrix);
    solution.rotate(matrix);
    printf("After rotate:\n");
    print_matrix(matrix);

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
    printf("Before rotate:\n");
    print_matrix(matrix);
    solution.rotate(matrix);
    printf("After rotate:\n");
    print_matrix(matrix);
    return 0;
}

