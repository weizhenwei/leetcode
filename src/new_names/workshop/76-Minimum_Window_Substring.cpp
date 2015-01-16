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
 * File: 76-Minimum_Window_Substring.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/minimum-window-substring/
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 *
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 *
 * Note:
 * If there is no such window in S that covers all characters in T, return the
 * emtpy string "".
 *
 * If there are multiple such windows, you are guaranteed that there will always
 * be only one unique minimum window in S.
 *
 *
 * Date: 2014.12.26
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string>
#include <map>

using std::map;
using std::string;

class Solution_Minimum_Window_Substring {
private:
    static void check_integrity(map<char, int> &charset) {
        for (map<char, int>::iterator iter = charset.begin();
                iter != charset.end(); iter++) {
            assert((*iter).second == 0);
        }  // for
    }

public:
    string minWindow(string S, string T) {
        if (S.size() == 0 || T.size() == 0) {
            return string("");
        }

        map<char, int> charset;
        for (int i = 0; i < T.size(); i++) {
            map<char, int>::iterator iter = charset.find(T[i]);
            if (iter == charset.end()) {
                charset[T[i]] = 1;
            } else {
                (*iter).second += 1;
            }
        }  // for i

        // find the start point;
        int i = 0;
        while (i < S.size()) {
            if (charset.find(S[i]) != charset.end()) {
                    break;
            }
            i++;
        }
        if (i == S.size()) {
            return string("");
        }

        map<char, int> workingSet;
        workingSet[S[i]] = 1;

        int start = i;
        int end = start + 1;
        int total = T.size();
        int minlength = INT_MAX;
        string result = string("");
        while (end < S.size()) {
            map<char, int>::iterator iter = charset.find(S[end]);
            if (iter == charset.end()) {
                end++;
                continue;
            } else {
                char target = (*iter).first;
                int num = charset[target];
                int current = workingSet[target];
                workingSet[target]++;
                if (current < num) {
                    if (--total == 0) {
                        string candidate = string(S.begin() + start,
                                S.begin() + end);
                        if (candidate.size() < minlength) {
                            result = candidate;
                            minlength = candidate.size();
                        }

                        int j = start + 1;
                        while (j < S.size()) {
                            map<char, int>::iterator iter = charset.find(S[j]);
                            if (iter != charset.end()) {
                                char target = (*iter).first;
                                int num = charset[target];
                                int current = workingSet[target];
                                if (current <= num) {
                                    break;
                                } else {
                                    workingSet[target]--;
                                }
                            }
                            j++;
                        }
                        if (j == S.size()) {
                            return result;
                        }
                        end = start + 1;

                    } else {
                        end++;
                    }
                } else {
                    end++;
                }
            }
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution_Minimum_Window_Substring solution;
    string S = "ADOBECODEBANC";
    string T = "ABC";
    string result = solution.minWindow(S, T);
    printf("%s\n", result.c_str());

    return 0;
}

