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
 * Brief: https://oj.leetcode.com/problems/pascals-triangle-ii/
 * Given an index k, return the kth row of the Pascal's triangle.
 *
 * For example, given k = 3,
 * Return [1,3,3,1].
 *
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 *
 * Date: 2014.11.15
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <algorithm>
#include <vector>

using std::vector;

class Solution_Pascals_Triangle_II {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> triangle;
        if (rowIndex < 0) {
            return triangle;
        }

        int i = 0;
        triangle.push_back(1);
        vector<int> tmptriangle;;
        while (i < rowIndex) {
            tmptriangle.clear();
            for (int j = 0; j <= triangle.size(); j++) {
                if (j == 0 || j == triangle.size()) {
                    tmptriangle.push_back(1);
                } else {
                    tmptriangle.push_back(triangle[j-1] + triangle[j]);
                }
            }  // for

            swap(tmptriangle, triangle);
            i++;
        } // while

        return triangle;
    }
};

static void print_vector(vector<int> &v) {
    for (int j = 0; j < v.size(); j++) {
        printf("%d ", v[j]);
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Pascals_Triangle_II solution;
    int numRows = 1;
    vector<int> triangle = solution.getRow(numRows);
    print_vector(triangle);

    numRows = 2;
    triangle = solution.getRow(numRows);
    print_vector(triangle);

    numRows = 3;
    triangle = solution.getRow(numRows);
    print_vector(triangle);

    numRows = 4;
    triangle = solution.getRow(numRows);
    print_vector(triangle);

    numRows = 5;
    triangle = solution.getRow(numRows);
    print_vector(triangle);

    return 0;
}
