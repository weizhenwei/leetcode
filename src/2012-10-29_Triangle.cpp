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
 * File: 2012-10-29_Triangle.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/triangle/
 * Given a triangle, find the minimum path sum from top to bottom. Each step you
 * may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * Note:
 * Bonus point if you are able to do this using only O(n) extra
 * space, where n is the total number of rows in the triangle.
 *
 * Date: 2014.11.16
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <algorithm>
#include <vector>

using std::vector;

class Solution_Triangle {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size() == 1) {
            return triangle[0][0];
        }

        vector<int> sumbefore;
        vector<int> sumcurrent;
        sumbefore.push_back(triangle[0][0]);
        for (int i = 1; i < triangle.size(); i++) {
            sumcurrent.clear();
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) {
                    sumcurrent.push_back(sumbefore[0] + triangle[i][j]);
                } else if (j == triangle[i].size() - 1) {
                    sumcurrent.push_back(sumbefore[j-1] + triangle[i][j]);
                } else {
                    sumcurrent.push_back(triangle[i][j]
                        + (sumbefore[j-1] < sumbefore[j]
                        ? sumbefore[j-1] : sumbefore[j]));
                }
            }
            
            swap(sumbefore, sumcurrent);
        }

        int min = sumbefore[0];
        for (int i = 1; i < sumbefore.size(); i++) {
            if (sumbefore[i] < min) {
                min = sumbefore[i];
            }
        }

        return min;
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
    Solution_Triangle solution;

    vector<vector<int> > triangle;
    vector<int> elem;
    elem.push_back(2);
    triangle.push_back(elem);
    elem.clear();
    elem.push_back(3);
    elem.push_back(4);
    triangle.push_back(elem);
    elem.clear();
    elem.push_back(6);
    elem.push_back(5);
    elem.push_back(7);
    triangle.push_back(elem);
    elem.clear();
    elem.push_back(4);
    elem.push_back(1);
    elem.push_back(8);
    elem.push_back(3);
    triangle.push_back(elem);
    
    print_vector(triangle);
    int min = solution.minimumTotal(triangle);
    printf("minimum = %d\n", min);


    triangle.clear();

    elem.clear();
    elem.push_back(-1);
    triangle.push_back(elem);
    elem.clear();
    elem.push_back(2);
    elem.push_back(3);
    triangle.push_back(elem);
    elem.clear();
    elem.push_back(1);
    elem.push_back(-1);
    elem.push_back(-1);
    triangle.push_back(elem);
    print_vector(triangle);
    min = solution.minimumTotal(triangle);
    printf("minimum = %d\n", min);

    return 0;
}
