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
    string minWindow_wrong(string S, string T) {
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
        int total = T.size() - 1;  // already have one at S[start];
        if (total == 0) {
            return string(end - start, S[start]);
        }
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
                if (current < num) {
                    workingSet[target]++;
                    if (--total == 0) {
                        string candidate = string(S.begin() + start,
                                S.begin() + end + 1);
                        if (candidate.size() < minlength) {
                            result = candidate;
                            minlength = candidate.size();
                        }
                        
                        // remove the first element;
                        char first = S[start];
                        workingSet[first]--;
                        total++;

                        // moving start forward;
                        int j = start + 1;
                        while (j < S.size()) {  // first next start position;
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
                        start = j;
                        end++;

                    } else {
                        end++;
                    }
                } else {
                    assert(current == num);
                    int k = start;
                    while (k < end) {
                        if (S[k] == target) {
                            break;
                        }
                        k++;
                    }
                    if (k > start) {
                        char sStart = S[start];
                        if (sStart != target) {
                            workingSet[sStart]--;
                            total++;
                        }
                    }
                    start = k + 1;

                    int j = start;
                    while (j <= end) {
                        map<char, int>::iterator iter = charset.find(S[j]);
                        if (iter != charset.end()) {
                            break;
                        }
                        j++;
                    }
                    if (j == S.size()) {
                        return result;
                    }
                    start = j;
                    end++;
                }
            }
        }

        return result;
    }

    // originates from:
    // https://oj.leetcode.com/discuss/20053/three-concise-implemetation-according-leetcode-oj-discuss
    string minWindow(string S, string T) {
        int m = S.size(), n = T.size();
        if (n <= 0 || m < n) {
            return "";
        }

        int require[128] = {0};
        for (int i = 0; i < n; i++) {
            require[T[i]]++;
        }

        int count = 0;
        int minLen = INT_MAX;
        int minIndex = 0;
        for (int s = 0, e = 0; e < m; e++) {
            require[S[e]]--;
            if (require[S[e]] >= 0) {
                count++;
            }
            while (count == n) {
                if (e - s + 1 < minLen) {
                    minLen = e - s + 1;
                    minIndex = s;
                }

                require[S[s]]++;
                if (require[S[s]] > 0) {
                    count--;
                }
                s++;
            }  // while
        }  // for

        if (minLen == INT_MAX)
            return "";

        return S.substr(minIndex, minLen);
    }
};

int main(int argc, char *argv[]) {
    Solution_Minimum_Window_Substring solution;
    string S = "ADOBECODEBANC";
    string T = "ABC";
    string result = solution.minWindow(S, T);
    printf("S:%s\n", S.c_str());
    printf("T:%s\n", T.c_str());
    printf("%s\n", result.c_str());

    S = "caae";
    T = "cae";
    result = solution.minWindow(S, T);
    printf("S:%s\n", S.c_str());
    printf("T:%s\n", T.c_str());
    printf("%s\n", result.c_str());

    S = "acbbaca";
    T = "aba";
    result = solution.minWindow(S, T);
    printf("S:%s\n", S.c_str());
    printf("T:%s\n", T.c_str());
    printf("%s\n", result.c_str());

    S = "ADOBECODEBANC";
    T = "ABCC";
    result = solution.minWindow(S, T);
    printf("S:%s\n", S.c_str());
    printf("T:%s\n", T.c_str());
    printf("%s\n", result.c_str());

    T = "ABX";
    result = solution.minWindow(S, T);
    printf("S:%s\n", S.c_str());
    printf("T:%s\n", T.c_str());
    printf("%s\n", result.c_str());

    T = "AB";
    result = solution.minWindow(S, T);
    printf("S:%s\n", S.c_str());
    printf("T:%s\n", T.c_str());
    printf("%s\n", result.c_str());

    S = "A";
    T = "A";
    result = solution.minWindow(S, T);
    printf("S:%s\n", S.c_str());
    printf("T:%s\n", T.c_str());
    printf("%s\n", result.c_str());

    return 0;
}

