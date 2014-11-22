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
 * File: 2012-03-27_Permutation_Sequence.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/permutation-sequence/
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 *
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 *
 * Note: Given n will be between 1 and 9 inclusive.
 *
 *
 * Date: 2014.11.21
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <assert.h>
#include <stdio.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

static void print_vector(vector<vector<char> > &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            printf("%c", v[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

class Solution_Permutations_Sequence {
public:
    vector<vector<char> > permute(vector<int> &num) {
        vector<vector<char> > permutations;
        if (num.size() == 1) {
            vector<char> elem;
            elem.push_back(num[0] + '0');
            permutations.push_back(elem);
            return permutations;
        }

        for (int i = 0; i < num.size(); i++) {
            vector<int> subnum = vector<int>(num);
            int elem = subnum[i];
            subnum.erase(subnum.begin() + i);
            vector<vector<char> > subpermutations = permute(subnum);
            for (int j = 0; j < subpermutations.size(); j++) {
                subpermutations[j].insert(subpermutations[j].begin(),
                        elem + '0');
                permutations.push_back(subpermutations[j]);
            }
        }  // for outer

        return permutations;
    }
    string getPermutationStupid(int n, int k) {
        vector<int> num;
        for (int i = 1; i <= n; i++) {
            num.push_back(i);
        }

        vector<vector<char> > permutations = permute(num);
        printf("all permutations:\n");
        print_vector(permutations);


        string result;
        for (int i = 0; i < permutations[k-1].size(); i++) {
            result.push_back(permutations[k-1][i]);
        }

        return result;
    }

    string getPermutation(int n, int k) {
        assert(n >= 1 && n <= 9);
        if (k == 1) {
            string result;
            for (int i = 1; i <= n; i++) {
                result.push_back(i + '0');
            }
            return result;
        }

        vector<int> factorial;
        vector<int> remaining;
        factorial.push_back(1);
        for (int i = 1; i <= n; i++) {
            remaining.push_back(i);
            int prev = factorial[i-1];
            factorial.push_back(prev * i);
        }
        if (k == factorial[n]) {
            string result;
            for (int i = n; i >= 1; i--) {
                result.push_back(i + '0');
            }
            return result;
        }

        string result;
        for (int i = n; i >= 1; i--) {
            if (k % factorial[i-1] == 0) {
                if (k == 0) {
                    for (int j = remaining.size() - 1; j >= 0; j--) {
                        result.push_back(remaining[j] + '0');
                    }
                } else {
                    int index = k / factorial[i-1] - 1;
                    int target = remaining[index];
                    result.push_back(target + '0');
                    remaining.erase(remaining.begin() + index);
                    for (int j = remaining.size() - 1; j >= 0; j--) {
                        result.push_back(remaining[j] + '0');
                    }
                }
                return result;
            } else {
                int index = k / factorial[i-1];
                int target = remaining[index];
                result.push_back(target + '0');
                remaining.erase(remaining.begin() + index);
                k = k % factorial[i-1];
            }
        }  // for

        return result;
    }
};

static void print_array(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Permutations_Sequence solution;

    int n = 3;
    int k = 2;
    string result = solution.getPermutation(n, k);
    printf("n = %d, k = %d, result= %s\n", n, k, result.c_str());

    n = 3;
    k = 3;
    result = solution.getPermutation(n, k);
    printf("n = %d, k = %d, result= %s\n", n, k, result.c_str());

    n = 4;
    k = 3;
    result = solution.getPermutation(n, k);
    printf("n = %d, k = %d, result= %s\n", n, k, result.c_str());

    n = 9;
    k = 54494;
    result = solution.getPermutation(n, k);
    printf("n = %d, k = %d, result= %s\n", n, k, result.c_str());

    n = 9;
    k = 54494;
    result = solution.getPermutation(n, k);
    printf("n = %d, k = %d, result= %s\n", n, k, result.c_str());

    n = 1;
    k = 1;
    result = solution.getPermutation(n, k);
    printf("n = %d, k = %d, result= %s\n", n, k, result.c_str());

    n = 2;
    k = 1;
    result = solution.getPermutation(n, k);
    printf("n = %d, k = %d, result= %s\n", n, k, result.c_str());

    n = 2;
    k = 2;
    result = solution.getPermutation(n, k);
    printf("n = %d, k = %d, result= %s\n", n, k, result.c_str());

    n = 4;
    k = 24;
    result = solution.getPermutation(n, k);
    printf("n = %d, k = %d, result= %s\n", n, k, result.c_str());

    n = 9;
    k = 362880;
    result = solution.getPermutation(n, k);
    printf("n = %d, k = %d, result= %s\n", n, k, result.c_str());

    n = 9;
    k = 6280;
    result = solution.getPermutation(n, k);
    printf("n = %d, k = %d, result= %s\n", n, k, result.c_str());

    n = 6;
    k = 280;
    result = solution.getPermutation(n, k);
    printf("n = %d, k = %d, result= %s\n", n, k, result.c_str());

    return 0;
}

