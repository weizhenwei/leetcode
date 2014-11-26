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
 * File: 2012-03-06_Combination_Sum.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/combination-sum/
 * Given a set of candidate numbers (C) and a target number (T), find all unique
 * combinations in C where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order.
 * (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 2,3,6,7 and target 7, 
 * A solution set is: 
 * [7] 
 * [2, 2, 3] 
 *
 *
 * Date: 2014.11.26
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <algorithm>
#include <vector>

using std::sort;
using std::vector;


// originate from:
// https://oj.leetcode.com/discuss/12168/share-simple-solution-using-without-using-handle-duplicates
class Solution_Combination_Sum {
public:
    vector<vector<int> > res;
    void go(int startpos, vector<int>oneres, vector<int> &num, int target) {
        for (int i = startpos; i < num.size(); i++) {
            if (num[i] < target) {
                oneres.push_back(num[i]);
                // In question"Combination Sum", here should be i instead of i+1,
                // cuz it allow using one number more than once
                go(i, oneres, num, target-num[i]);
                oneres.pop_back();
            } else if (num[i] == target) {
                oneres.push_back(num[i]);
                res.push_back(oneres);
                oneres.pop_back();
                return;
            } else {
                return;
            }

            // handle duplicates
            while (i < num.size() - 1 && num[i] == num[i + 1])
                i++;
        }
    }

    vector<vector<int> > combinationSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<int>oneres;
        go(0, oneres, num, target);

        return res;
    }
};

static void print_vector(vector<int> &num) {
    for (int i = 0; i < num.size(); i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
}

static void print_vector2(vector<vector<int> > &num) {
    for (int i = 0; i < num.size(); i++) {
        for (int j = 0; j < num[i].size(); j++) {
            printf("%d ", num[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Combination_Sum solution;
    vector<int> num;
    int target;
    vector<vector<int> > result;

    num.clear();
    num.push_back(2);
    num.push_back(3);
    num.push_back(6);
    num.push_back(7);
    target = 7;
    printf("vector:\n");
    print_vector(num);
    result = solution.combinationSum(num, target);
    printf("result:\n");
    print_vector2(result);

    return 0;
}

