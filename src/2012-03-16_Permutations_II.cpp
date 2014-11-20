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
 * File: 2012-03-16_Permutations_II.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/permutations-ii/
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 *
 * For example,
 * [1,1,2] have the following unique permutations:
 * [1,1,2], [1,2,1], and [2,1,1].
 *
 *
 * Date: 2014.11.20
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <map>
#include <vector>

using std::map;
using std::vector;

class Solution_Permutations_II {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > permutations;
        if (num.size() == 1) {
            vector<int> elem;
            elem.push_back(num[0]);
            permutations.push_back(elem);
            return permutations;
        }

        map<vector<int>, int> flush;
        map<int, int> done;
        for (int i = 0; i < num.size(); i++) {
            if (done.find(num[i]) == done.end()) {
                done[num[i]] = num[i];
            } else {
                continue;
            }

            vector<int> subnum = vector<int>(num);
            int elem = subnum[i];
            subnum.erase(subnum.begin() + i);
            vector<vector<int> > subpermutations = permuteUnique(subnum);
            for (int j = 0; j < subpermutations.size(); j++) {
                subpermutations[j].insert(subpermutations[j].begin(), elem);
                if (flush.find(subpermutations[j]) == flush.end()) {
                    flush[subpermutations[j]] = j;
                    permutations.push_back(subpermutations[j]);
                }
            }
        }  // for outer

        return permutations;
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
static void print_array(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Permutations_II solution;
    vector<int> num;

    num.push_back(1);
    num.push_back(1);
    num.push_back(3);
    printf("vector:");
    print_array(num);
    vector<vector<int> > permutations = solution.permuteUnique(num);
    printf("permutations:\n");
    print_vector(permutations);

    num.clear();
    num.push_back(1);
    num.push_back(2);
    num.push_back(2);
    num.push_back(2);
    printf("vector:");
    print_array(num);
    permutations = solution.permuteUnique(num);
    printf("permutations:\n");
    print_vector(permutations);

    return 0;
}

