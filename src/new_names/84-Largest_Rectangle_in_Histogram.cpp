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
 * File: 84-Largest_Rectangle_in_Histogram.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/largest-rectangle-in-histogram/
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * The largest rectangle is shown in the shaded area, which has area = 10 unit.
 *
 * For example,
 * Given height = [2,1,5,6,2,3],
 * return 10.
 *
 *
 * Date: 2015.01.15
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <vector>

using std::vector;

class Solution_Largest_Rectangle {
public:
    int largestRectangleArea_Stupid(vector<int> &height) {
        if (height.size() == 0) {
                return 0;
        }
        if (height.size() == 1) {
                return height[0];
        }

        vector<int> dpArray = vector<int>(height);
        vector<int> maxArray = vector<int>(height);
        int largest = dpArray[0];
        for (int i = 1; i < dpArray.size(); i++) {
            if (largest < dpArray[i]) {
                largest = maxArray[i] = dpArray[i];
            }
        }

        int length = 1;
        while (length <= height.size()) {
            for (int i = 0; i < height.size() - length; i++) {
                int target = height[i+length];
                if (dpArray[i] > target) {
                    dpArray[i] = target;
                }
                if (dpArray[i] * (length + 1) > maxArray[i]) {
                    maxArray[i] = dpArray[i] * (length + 1);
                    if (maxArray[i] > largest) {
                        largest = maxArray[i];
                    }
                }
            }  // for

            length++;
        }

        return largest;
    }

    int largestRectangleArea(vector<int> &height) {
        int ret = 0;
        height.push_back(0);
        vector<int> index;

        for (int i = 0; i < height.size(); i++) {
            while(index.size() > 0 && height[index.back()] >= height[i]) {
                int h = height[index.back()];
                index.pop_back();
                
                int sidx = index.size() > 0 ? index.back() : -1;
                if(h * (i-sidx-1) > ret)
                    ret = h * (i-sidx-1);
            }
            index.push_back(i);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution_Largest_Rectangle solution;
    vector<int> height;
    height.push_back(2);
    height.push_back(1);
    height.push_back(5);
    height.push_back(6);
    height.push_back(2);
    height.push_back(3);
    int largest = solution.largestRectangleArea(height);
    printf("largest rectangle area = %d\n", largest);

    height.clear();
    height.push_back(2);
    height.push_back(1);
    height.push_back(1);
    largest = solution.largestRectangleArea(height);
    printf("largest rectangle area = %d\n", largest);


    return 0;
}

