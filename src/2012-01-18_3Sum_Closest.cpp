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
 * File: 2012-01-18_3Sum_Closest.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/3sum-closest/
 * Given an array S of n integers, find three integers in S such that the sum is
 * closest to a given number, target. Return the sum of the three integers. You
 * may assume that each input would have exactly one solution.
 *
 *     For example, given array S = {-1 2 1 -4}, and target = 1.
 *     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 *
 * Date: 2014.11.02
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using std::map;
using std::multimap;
using std::pair;
using std::vector;
using std::set;

class Solution_threeSum_Closest {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if (num.size() < 3)  // input error!
            return target;

        if (num.size() == 3)
            return num[0] + num[1] + num[2];


        sort(num.begin(), num.begin() + num.size());

        int i = 0;
        int closest = INT_MAX;
        int result = closest;
        for (i = 0; i < num.size() - 2; i++) {
            int left = i + 1;
            int right = num.size() - 1;
            while (left < right) {
                int candidate = num[i] + num[left] + num[right];
                if (candidate == target) {
                    return target;
                } else if (candidate > target) {  // bigger;
                    if (abs(candidate - target) < closest) {
                        closest = abs(candidate - target);
                        result = candidate;
                    }

                    while (right > 0 && num[right] == num[right-1]) {
                        right--;
                    }
                    right--;
                } else {  // smaller
                    if (abs(candidate - target) < closest) {
                        closest = abs(candidate - target);
                        result = candidate;
                    }

                    while (left < num.size() && num[left] == num[left+1]) {
                        left++;
                    }
                    left++;
                }
            }  // while
        }  // for

        return result;
    }
};

static void print_vector(vector<int> &v) {
    vector<int>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
        printf("%d ", *iter);
    }
    printf("\n");

}

int main(int argc, char *argv[]) {
    Solution_threeSum_Closest solution;
    vector<int> num;
    num.push_back(-1);
    num.push_back(2);
    num.push_back(1);
    num.push_back(-4);
    print_vector(num);
    int target = 1;
    int result = solution.threeSumClosest(num, target);
    printf("target = %d, Cloest 3sum = %d\n", target, result);

    num.clear();
    num.push_back(-1);
    num.push_back(0);
    num.push_back(1);
    print_vector(num);
    target = 0;
    result = solution.threeSumClosest(num, target);
    printf("target = %d, Cloest 3sum = %d\n", target, result);

    num.clear();
    num.push_back(-1);
    num.push_back(0);
    num.push_back(1);
    num.push_back(0);
    num.push_back(0);
    num.push_back(0);
    num.push_back(0);
    num.push_back(0);
    num.push_back(0);
    num.push_back(0);
    num.push_back(0);
    print_vector(num);
    target = -3;
    result = solution.threeSumClosest(num, target);
    printf("target = %d, Cloest 3sum = %d\n", target, result);

    num.clear();
    num.push_back(1);
    num.push_back(1);
    num.push_back(1);
    num.push_back(0);
    print_vector(num);
    target = -100;
    result = solution.threeSumClosest(num, target);
    printf("target = %d, Cloest 3sum = %d\n", target, result);

    // num.clear();
    // num.push_back(0);
    // num.push_back(0);
    // num.push_back(0);
    // num.push_back(0);
    // num.push_back(0);
    // print_vector(num);
    // result = solution.threeSum(num);
    // print_vector2(result);

    return 0;
}
