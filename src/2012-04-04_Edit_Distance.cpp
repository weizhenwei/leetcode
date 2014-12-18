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
 * File: 2012-04-04_Edit_Distance.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/edit-distance/
 * Given two words word1 and word2, find the minimum number of steps required to
 * convert word1 to word2. (each operation is counted as 1 step.)
 *
 * You have the following 3 operations permitted on a word:
 *
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
 *
 *
 * Date: 2014.12.18
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

using std::min;
using std::vector;
using std::string;

// originates from:
// https://oj.leetcode.com/discuss/11989/my-dp-solution-in-c-with-comments
class Solution_Edit_Distance {
public:
    int minDistance(string word1, string word2) {
        // DP table i is the position in word1, and j is the position in word2;
        vector<vector<int> > distance(word1.length() + 1,
                vector<int>(word2.length() + 1, 0));

        // when i = 0 or j = 0 means empty string, the distance is the length of
        // another string;
        for (int i = 0; i < distance.size(); i++) {
            for (int j = 0; j < distance[i].size(); j++) {
                if (i == 0) {
                    distance[i][j] = j;
                } else if (j == 0) {
                    distance[i][j] = i;
                }
            }  // for j
        }  // for i

        // if word1[i] == word2[j], then the distance of i and j is the previous
        // i and j, otherwise we either replace, insert or delete a char:
        // when insert a char to word1 it means we are trying to match word1
        // at i - 1 to word2 at j;
        // when delete a char from word1 it equals to insert a char to word2,
        // which means we are trying to match word1 at i to word2 at j - 1;
        // when replace a char to word1, then we add one step to previous i and
        // j;
        for (int i = 1; i < distance.size(); i++) {
            for (int j = 0; j < distance[i].size(); j++) {
                if (word1[i-1] == word2[j-1]) {
                    distance[i][j] = distance[i-1][j-1];
                } else {
                    distance[i][j] = 1 + min(distance[i-1][j-1],
                            min(distance[i-1][j], distance[i][j-1]));
                }
            }  // for i
        }  // for j

        return distance[word1.length()][word2.length()];
    }
};

int main(int argc, char *argv[]) {
    Solution_Edit_Distance solution;
    string word1 = string("hello");
    string word2 = string("word");
    int min = solution.minDistance(word1, word2);
    printf("word1 = %s, word2 = %s, minDistance = %d\n",
            word1.c_str(), word2.c_str(), min);

    word1 = string("hello");
    word2 = string("hello");
    min = solution.minDistance(word1, word2);
    printf("word1 = %s, word2 = %s, minDistance = %d\n",
            word1.c_str(), word2.c_str(), min);

    word1 = string("hello");
    word2 = string("elloh");
    min = solution.minDistance(word1, word2);
    printf("word1 = %s, word2 = %s, minDistance = %d\n",
            word1.c_str(), word2.c_str(), min);

    return 0;
}

