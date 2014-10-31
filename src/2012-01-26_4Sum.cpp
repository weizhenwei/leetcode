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
 * Brief: https://oj.leetcode.com/problems/4sum/
 * Given an array S of n integers, are there elements a, b, c, and d in S such
 * that a + b + c + d = target? Find all unique quadruplets in the array which
 * gives the sum of target.
 *
 * Note:
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤
 * b ≤ c ≤ d)
 * The solution set must not contain duplicate quadruplets.
 *     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 *
 *         A solution set is:
 *             (-1,  0, 0, 1)
 *             (-2, -1, 1, 2)
 *             (-2,  0, 0, 2)
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

class Solution_fourSum {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        if (num.size() <= 3)
            return result;

        sort(num.begin(), num.begin() + num.size());

        map<vector<int>, int> tmpmap;
        map<int, vector<int> > hashmap;
        vector<int>::iterator iter;
        int m = 0;
        for (m = 0; m < num.size(); m++) {
            hashmap[num[m]].push_back(m);
        }

        int i = 0;
        while (i < num.size() - 3) {
            if (i > 0 && num[i] == num[i-1]) {
                i++;
                continue;
            }

            int a = num[i];
            int j = i + 1;
            while (j < num.size() - 2) {
                if (j > i + 1 && num[j] == num[j-1]) {
                    if (num[j] == num[i]) {
                        break;
                    }
                    j++;
                    continue;
                }

                int b = num[j];
                int k = j + 1;
                while (k < num.size() - 1) {
                    if (k > j + 1 && num[k] == num[k-1]) {
                        if (num[k] == num[j]) {
                            break;
                        }
                        k++;
                        continue;
                    }

                    int c = num[k];
                    int d = target - (a + b + c);
                    map<int, vector<int> >::iterator miter;
                    if ((miter = hashmap.find(d)) != hashmap.end()) {
                        vector<int> v = (*miter).second;
                        int idx = v[v.size()-1];
                        if (idx > k) {
                            vector<int> got;
                            got.push_back(a);
                            got.push_back(b);
                            got.push_back(c);
                            got.push_back(d);
                            if (tmpmap.find(got) == tmpmap.end()) {
                                tmpmap.insert(pair<vector<int>, int>(got, k));
                                result.push_back(got);
                            }
                        }
                    }
                    k++;
                }  // while k
                j++;
            }  // while j
            i++;
        }  // while i

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
    Solution_fourSum solution;
    vector<int> num;
    num.push_back(1);
    num.push_back(0);
    num.push_back(-1);
    num.push_back(0);
    num.push_back(-2);
    num.push_back(2);
    print_vector(num);
    vector<vector<int> > result = solution.fourSum(num, 0);
    print_vector2(result);

//     num.clear();
//     num.push_back(-1);
//     num.push_back(0);
//     num.push_back(1);
//     num.push_back(1);
//     print_vector(num);
//     result = solution.threeSum(num);
//     print_vector2(result);
// 
//     num.clear();
//     num.push_back(0);
//     num.push_back(0);
//     num.push_back(0);
//     print_vector(num);
//     result = solution.threeSum(num);
//     print_vector2(result);
// 
//     num.clear();
//     num.push_back(0);
//     num.push_back(0);
//     num.push_back(-1);
//     num.push_back(1);
//     num.push_back(1);
//     print_vector(num);
//     result = solution.threeSum(num);
//     print_vector2(result);
// 
//     num.clear();
//     num.push_back(0);
//     num.push_back(0);
//     num.push_back(0);
//     num.push_back(0);
//     num.push_back(0);
//     print_vector(num);
//     result = solution.threeSum(num);
//     print_vector2(result);

    return 0;
}
