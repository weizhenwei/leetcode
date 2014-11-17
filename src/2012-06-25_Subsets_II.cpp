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
 * File: 2012-06-25_Subsets_II.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/subsets-ii/
 * Given a collection of integers that might contain duplicates, S, return all
 * possible subsets.
 *
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If S = [1,2,2], a solution is:
 *
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 *
 *
 * Date: 2014.11.17
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

using std::map;
using std::pair;
using std::vector;

class Solution_Subsets_II {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > results;
        int size = S.size();
        if (size == 0) {
            return results;
        }

        sort(S.begin(), S.end());

        int ceiling = 1 << size;
        map<vector<int>, vector<int> > sets;
        vector<int> set;
        sets.insert(sets.begin(), pair<vector<int>, vector<int> >(set, set));
        int counter = 1;
        while (counter < ceiling) {
            int tmp = counter;
            int idx = 0;
            set.clear();
            while (tmp > 0) {
                if (tmp % 2 == 1) {
                    set.push_back(S[idx]);
                }
                tmp = tmp / 2;
                idx++;
            }
            if (sets.find(set) == sets.end()) {
                sets.insert(sets.begin(),
                        pair<vector<int>, vector<int> >(set, set));
            }
            counter++;
        }  // while

        map<vector<int>, vector<int> >::iterator it;
        for (it = sets.begin(); it != sets.end(); it++) {
            results.push_back((*it).first);
        }

        return results;
    }
};

static void printVector(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

static void printVVector(vector<vector<int> > &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Subsets_II solution;

    vector<int> s;
    s.push_back(2);
    s.push_back(1);
    s.push_back(3);
    printf("original vector:");
    printVector(s);
    vector<vector<int> > sets = solution.subsetsWithDup(s);
    printf("subsets vector:");
    printVVector(sets);

    s.clear();
    s.push_back(2);
    s.push_back(1);
    s.push_back(2);
    printf("original vector:");
    printVector(s);
    sets = solution.subsetsWithDup(s);
    printf("subsets vector:");
    printVVector(sets);

    return 0;
}

