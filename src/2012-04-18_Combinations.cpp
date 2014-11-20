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
 * File: 2012-04-18_Combinations.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/combinations/
 * Given two integers n and k, return all possible combinations of k numbers out
 * of 1 ... n.
 *
 * For example,
 * If n = 4 and k = 2, a solution is:
 *
 * [
 *  [2,4],
 *  [3,4],
 *  [2,3],
 *  [1,2],
 *  [1,3],
 *  [1,4],
 * ]
 *
 *
 * Date: 2014.11.20
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <vector>

using std::vector;

class Solution_Combinations {
public:
    // C(n, k) = C(n - 1, k - 1) + C(n - 1, k);
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > combinations;
        if (n == k) {
            vector<int> elem;
            for (int i = 1; i <= n; i++) {
                elem.push_back(i);
            }
            combinations.push_back(elem);
            return combinations;
        } else if (k == 1) {
            vector<int> elem;
            for (int i = 1; i <= n; i++) {
                elem.clear();
                elem.push_back(i);
                combinations.push_back(elem);
            }
            return combinations;
        } else {
            vector<vector<int> > first = combine(n - 1, k - 1);
            for (int i = 0; i < first.size(); i++) {
                first[i].push_back(n);
                combinations.push_back(first[i]);
            }

            vector<vector<int> > second = combine(n - 1, k);
            for (int i = 0; i < second.size(); i++) {
                combinations.push_back(second[i]);
            }

            return combinations;
        }
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
    Solution_Combinations solution;

    int n = 1;
    int k = 1;
    vector<vector<int> > combinations = solution.combine(n, k);
    printf("n = %d, k = %d\n", n, k);
    print_vector(combinations);

    n = 2;
    k = 1;
    combinations = solution.combine(n, k);
    printf("n = %d, k = %d\n", n, k);
    print_vector(combinations);

    n = 4;
    k = 2;
    combinations = solution.combine(n, k);
    printf("n = %d, k = %d\n", n, k);
    print_vector(combinations);

    return 0;
}

