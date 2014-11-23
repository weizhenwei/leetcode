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
 * File: 2012-01-08_Container_With_Most_Water.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/container-with-most-water/
 * Given n non-negative integers a1, a2, ..., an, where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines,
 * which together with x-axis forms a container,
 * such that the container contains the most water.
 *
 * Note: You may not slant the container.
 *
 *
 * Date: 2014.10.23
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <algorithm>
#include <stdio.h>
#include <vector>

using std::min;
using std::vector;

class Solution_Container_With_Most_Water {
public:
    int maxAreaStupid(vector<int> &height) {
        if (height.size() <= 1)
            return 0;
        if (height.size() == 2) {
            int min = height[0] < height[1] ? height[0] : height[1];
            return min * 1;
        }

        int result = 0;
        int pivot = 0, increment = 0;
        int interval = 0, tall = 0;

        pivot = 1;
        while (pivot < height.size()) {
            // odd situation;
            increment = 0;
            while ((pivot - increment >= 0)) {
                if (pivot + increment < height.size()
                        && pivot + increment + 1 < height.size()) {
                    // odd situation;
                    interval = increment * 2;
                    tall = height[pivot - increment] < height[pivot + increment] ?
                        height[pivot - increment] : height[pivot + increment];
                    if (result < tall * interval)
                        result = tall *interval;

                    // even situation;
                    interval = 2 *increment + 1;
                    tall = height[pivot - increment]
                        < height[pivot + increment + 1] ?
                        height[pivot - increment] : height[pivot + increment + 1];
                    if (result < tall * interval)
                        result = tall *interval;
                } else if (pivot + increment < height.size()) {
                    // odd situation;
                    interval = increment * 2;
                    tall = height[pivot - increment] < height[pivot + increment] ?
                        height[pivot - increment] : height[pivot + increment];
                    if (result < tall * interval)
                        result = tall *interval;
                } else if (pivot + increment + 1 < height.size()) {
                    // even situation;
                    interval = 2 *increment + 1;
                    tall = height[pivot - increment]
                        < height[pivot + increment + 1] ?
                        height[pivot - increment] : height[pivot + increment + 1];
                    if (result < tall * interval)
                        result = tall *interval;
                }

                increment++;
            }

            pivot++;
        }

        return result;
    }

    // idea originates from:
    // https://oj.leetcode.com/discuss/14610/very-simple-o-n-solution
    int maxArea(vector<int> &height) {
        int start = 0;
        int end = height.size() - 1;
        int max = 0;
        while (start < end) {
            int tmp = (end - start) * min(height[end], height[start]);
            if (max < tmp) {
                max = tmp;
            }

            // possible situations where maxier may happen!
            if (height[start] < height[end]) {
                start++;
            } else {
                end--;
            }
        }  // while

        return max;
    }
};

static void print_vector(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Container_With_Most_Water solution;
    vector<int> height;
    int result = 0;

    height.push_back(3);
    result = solution.maxArea(height);
    print_vector(height);
    printf("maxArea = %d\n", result);

    height.clear();
    height.push_back(3);
    height.push_back(4);
    result = solution.maxArea(height);
    print_vector(height);
    printf("maxArea = %d\n", result);

    height.clear();
    height.push_back(3);
    height.push_back(4);
    height.push_back(5);
    height.push_back(2);
    result = solution.maxArea(height);
    print_vector(height);
    printf("maxArea = %d\n", result);

    height.clear();
    height.push_back(3);
    height.push_back(4);
    height.push_back(5);
    height.push_back(2);
    height.push_back(3);
    result = solution.maxArea(height);
    print_vector(height);
    printf("maxArea = %d\n", result);



    return 0;
}
