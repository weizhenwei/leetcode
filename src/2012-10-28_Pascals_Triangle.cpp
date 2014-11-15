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
 * File: 2012-10-28_Pascals_Triangle.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/pascals-triangle/
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5,
 * Return
 *
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 *
 * Date: 2014.11.15
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <vector>

using std::vector;

class Solution_Pascals_Triangle {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > triangle;
        if (numRows <= 0) {
            return triangle;
        }

        int i = 1;
        vector<int> elem;
        elem.push_back(1);
        triangle.push_back(elem);
        while (i < numRows) {
            elem.clear();
            for (int j = 0; j <= triangle[i-1].size(); j++) {
                if (j == 0 || j == triangle[i-1].size()) {
                    elem.push_back(1);
                } else {
                    elem.push_back(triangle[i-1][j-1] + triangle[i-1][j]);
                }
            }  // for

            triangle.push_back(elem);
            i++;
        } // while

        return triangle;
    }
};

static void print_vector(vector<vector<int> > &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Pascals_Triangle solution;
    int numRows = 1;
    vector<vector<int> > triangle = solution.generate(numRows);
    print_vector(triangle);

    numRows = 2;
    triangle = solution.generate(numRows);
    print_vector(triangle);

    numRows = 3;
    triangle = solution.generate(numRows);
    print_vector(triangle);

    numRows = 4;
    triangle = solution.generate(numRows);
    print_vector(triangle);

    numRows = 5;
    triangle = solution.generate(numRows);
    print_vector(triangle);

    return 0;
}
