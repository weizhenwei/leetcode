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
 * File: 85-Maximal_Rectangle.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/maximal-rectangle/
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing all ones and return its area.
 *
 *
 * Date: 2015.01.19
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <vector>
#include <algorithm>

using std::vector;
using std::fill_n;
using std::max;
using std::min;

// originates from: https://oj.leetcode.com/discuss/20240/share-my-dp-solution
class Solution_Maximal_Rectangle {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty())
            return 0;

        const int m = matrix.size();
        const int n = matrix[0].size();
        int left[n], right[n], height[n];
        fill_n(left, n, 0);
        fill_n(right, n, n);
        fill_n(height, n, 0);
        int maxA = 0;
        for (int i = 0; i < m; i++) {
            int cur_left = 0;
            int cur_right = n;
            for (int j = 0; j < n; j++) {  // compute heigh;
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }  // for j
            for (int j = 0; j < n; j++) {  // compute left
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], cur_left);
                } else {
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }  // for j
            for (int j = n - 1; j >= 0; j--) {  // compute right;
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], cur_right);
                } else {
                    right[j] = n;
                    cur_right = j;
                }
            }  // for j

            for (int j = 0; j < n; j++) {
                maxA = max(maxA, (right[j] - left[j]) * height[j]);
            }
        }

        return maxA;
    }
};

static void print_matrix(vector<vector<char> > &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

}

int main(int argc, char *argv[]) {
    Solution_Maximal_Rectangle solution;
    vector<vector<char> > matrix;
    vector<char> elem;
    elem.clear();
    elem.push_back('0');
    elem.push_back('1');
    elem.push_back('1');
    elem.push_back('1');
    matrix.push_back(elem);
    elem.clear();
    elem.push_back('1');
    elem.push_back('1');
    elem.push_back('1');
    elem.push_back('1');
    matrix.push_back(elem);
    elem.clear();
    elem.push_back('1');
    elem.push_back('1');
    elem.push_back('1');
    elem.push_back('1');
    matrix.push_back(elem);
    elem.clear();
    elem.push_back('0');
    elem.push_back('1');
    elem.push_back('1');
    elem.push_back('1');
    matrix.push_back(elem);

    int max = solution.maximalRectangle(matrix);
    print_matrix(matrix);
    printf("max = %d\n", max);

    return 0;
}

