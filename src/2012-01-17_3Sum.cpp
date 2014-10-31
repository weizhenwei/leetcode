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
 * File: 2012-01-17_3Sum.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/3sum/
 * Given an array S of n integers, are there elements a, b, c in S such that a +
 * b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤
 * c)
 * The solution set must not contain duplicate triplets.
 *     For example, given array S = {-1 0 1 2 -1 -4},
 *
 *         A solution set is:
 *             (-1,  0, 1)
 *             (-1, -1, 2)
 *
 *
 * Date: 2014.10.31
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>

using std::map;
using std::multimap;
using std::pair;
using std::vector;

class Solution_threeSum {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        if (num.size() <= 2)
            return result;

        sort(num.begin(), num.begin() + num.size());
        if (num.size() == 3) {
            if (num[0] + num[1] + num[2] == 0) {
                vector<int> got;
                got.push_back(num[0]);
                got.push_back(num[1]);
                got.push_back(num[2]);
                result.push_back(got);
                return result;
            }
        }

        map<vector<int>, int> tmpmap;
        map<int, vector<int> > hashmap;
        vector<int>::iterator iter;
        int j = 0;
        for (j = 0; j < num.size(); j++) {
            hashmap[num[j]].push_back(j);
        }

        int i = 0;
        for (i = 0; i < num.size() - 2; i++) {
            if (i > 0 && num[i] == num[i-1]) continue;

            int a = num[i];
            int j = i + 1;
            while (j < num.size()) {
                if (j > i + 1 && num[j] == num[j-1]) {
                    j++;
                    continue;
                }

                int b = num[j];
                int c = -(a + b);
                map<int, vector<int> >::iterator miter;
                if ((miter = hashmap.find(c)) != hashmap.end()) {
                    vector<int> v = (*miter).second;
                    int idx = v[v.size()-1];
                    if (idx > j) {
                        vector<int> got;
                        got.push_back(a);
                        got.push_back(b);
                        got.push_back(c);
                        if (tmpmap.find(got) == tmpmap.end()) {
                            tmpmap.insert(pair<vector<int>, int>(got, j));
                            result.push_back(got);
                        }
                    }
                }
                
                j++;
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

static void print_vector2(vector<vector<int> > &v) {
    vector<vector<int> >::iterator iter1;
    for (iter1 = v.begin(); iter1 != v.end(); iter1++) {
        vector<int> elem = *iter1;
        vector<int>::iterator iter2;
        for (iter2 = elem.begin(); iter2 != elem.end(); iter2++) {
            printf("%d ", *iter2);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_threeSum solution;
    vector<int> num;
    num.push_back(-1);
    num.push_back(0);
    num.push_back(1);
    num.push_back(2);
    num.push_back(-1);
    num.push_back(-4);
    print_vector(num);
    vector<vector<int> > result = solution.threeSum(num);
    print_vector2(result);

    num.clear();
    num.push_back(-1);
    num.push_back(0);
    num.push_back(1);
    print_vector(num);
    result = solution.threeSum(num);
    print_vector2(result);

    num.clear();
    num.push_back(0);
    num.push_back(0);
    num.push_back(0);
    print_vector(num);
    result = solution.threeSum(num);
    print_vector2(result);

    num.clear();
    num.push_back(0);
    num.push_back(0);
    num.push_back(-1);
    num.push_back(1);
    num.push_back(1);
    print_vector(num);
    result = solution.threeSum(num);
    print_vector2(result);

    num.clear();
    num.push_back(0);
    num.push_back(0);
    num.push_back(0);
    num.push_back(0);
    num.push_back(0);
    print_vector(num);
    result = solution.threeSum(num);
    print_vector2(result);

    return 0;
}
