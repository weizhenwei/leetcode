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
 * File: 2012-02-23_Substring_with_Concatenation_of_All_Words.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems
 *                /substring-with-concatenation-of-all-words
 * You are given a string, S, and a list of words, L,
 * that are all of the same length. Find all starting indices of substring(s)
 * in S that is a concatenation of each word in L exactly once
 * and without any intervening characters.
 *
 * For example, given:
 * S: "barfoothefoobarman"
 * L: ["foo", "bar"]
 * You should return the indices: [0,9].
 * (order does not matter).
 *
 * Date: 2014.10.25
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <unordered_map>
#include <map>
#include <queue>
#include <string>
#include <vector>

using std::unordered_map;
using std::map;
using std::pair;
using std::queue;
using std::string;
using std::vector;

class Solution_Substring_with_Concatenation_of_All_Words {
public:
    vector<int> findSubstringStupid(string S, vector<string> &L) {
        vector<int> result;
        if (L.size() == 0)
            return result;

        map<string, int> benchmap;
        map<string, int> judgemap;
        map<string, queue<int> > occurence;

        // preprocessing
        vector<string>::iterator iter;
        for (iter = L.begin(); iter != L.end(); iter++) {
            if (benchmap.find(*iter) == benchmap.end()) {
                benchmap[*iter] = 1;
            } else {
                benchmap[*iter] += 1;
            }
        }

        int i = 0;
        int sublen = L[0].size();
        int position = 0;
        while (i < S.size()) {
            string candidate = string(S, i, sublen);
            if (benchmap.find(candidate) != benchmap.end()) {  // valid
                if (judgemap.find(candidate) == judgemap.end()) { // first time
                    judgemap[candidate] = 1;
                    queue<int> q;
                    q.push(i);
                    occurence[candidate] = q;

                    if (benchmap == judgemap) { // good, we got one
                        result.push_back(position);
                        string remove = string(S, position, sublen);
                        if (judgemap[remove] == 1) {
                            judgemap.erase(remove);
                            occurence.erase(remove);
                        } else {
                            judgemap[remove] -= 1;
                            occurence[remove].pop();
                        }
                        
                        position += sublen;
                        i += sublen;
                    } else {  // just go on;
                        i += sublen;
                    }
                } else {
                    // need to check overflow;
                    if (judgemap[candidate] == benchmap[candidate]) {

                        position = occurence[candidate].front() + sublen;
                        occurence[candidate].pop();
                        occurence[candidate].push(i);
                        
                        map<string, int>::iterator jiter;
                        for (jiter = judgemap.begin(); jiter != judgemap.end();
                                jiter++) {
                            while ((*jiter).second > 0) {
                                if (occurence[(*jiter).first].front()
                                        < position) {
                                    occurence[(*jiter).first].pop();
                                    judgemap[(*jiter).first] =
                                        (*jiter).second - 1;
                                } else {
                                    break;
                                }
                            }  // while
                            if ((*jiter).second == 0) {
                                judgemap.erase((*jiter).first);
                            }
                        }  // for

                        i += sublen;
                    } else {
                        judgemap[candidate] += 1;
                        occurence[candidate].push(i);

                        if (benchmap == judgemap) { // good, we got one
                            result.push_back(position);
                            string remove = string(S, position, sublen);
                            if (judgemap[remove] == 1) {
                                judgemap.erase(remove);
                                occurence.erase(remove);
                            } else {
                                judgemap[remove] -= 1;
                                occurence[remove].pop();
                            }
                            position += sublen;
                            i += sublen;
                        } else {
                            i += sublen;
                        }
                    }
                }
            } else {  // invalid candidate, clean judgemap, occurence and go on;
                judgemap.clear();
                occurence.clear();
                position++; 
                i = position;
            }
        }  // while

        return result;
    }

    // originate
    // from:https://oj.leetcode.com/discuss/15587/a-concise-solution-in-c
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        int n = S.length();
        if (n==0)
            return res;

        int cnt = L.size();
        if (cnt == 0)
            return res;
        int wlen = L[0].length();
        unordered_map<string, int> count;
        unordered_map<string, int>::iterator it;
        for (int i = 0; i < cnt; i++)
            count[L[i]]++;

        int i = 0;
        int j = 0;
        while (i < n && j < n) {
            unordered_map<string, int> tmpcount = count;
            int tmpcnt = cnt;
            while (i + wlen * tmpcnt <= n
                    && tmpcnt > 0
                    && (it = tmpcount.find(S.substr(i,wlen))) != tmpcount.end()
                    && it->second > 0) {
                it->second--;
                tmpcnt--;
                i += wlen;
            }

            if(tmpcnt == 0) {
                res.push_back(j);
            }

            j++;
            i = j;
            if(i + wlen * cnt > n)
                break;
        }

        return res;
    }
};

static void print_int(vector<int> &v) {
    vector<int>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
        printf("%d ", *iter);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Substring_with_Concatenation_of_All_Words solution;
    vector<string> L;
    vector<int> result;

    string S = string("forbarger");
    string ss;
    ss = string("for");
    L.push_back(ss);

    ss = string("bar");
    L.push_back(ss);

    ss = string("ger");
    L.push_back(ss);

    result = solution.findSubstring(S, L);
    print_int(result);

    S = string("barfoothefoobarman");
    L.clear();
    ss = string("foo");
    L.push_back(ss);
    ss = string("bar");
    L.push_back(ss);
    result = solution.findSubstring(S, L);
    print_int(result);

    S = string("barbabarbarfoobarfoobarthefoobarfoo");
    L.clear();
    ss = string("bar");
    L.push_back(ss);
    ss = string("foo");
    L.push_back(ss);
    result = solution.findSubstring(S, L);
    print_int(result);

    S = string("a");
    L.clear();
    ss = string("a");
    L.push_back(ss);
    ss = string("a");
    L.push_back(ss);
    result = solution.findSubstring(S, L);
    print_int(result);

    S = string("lingmindraboofooowingdingbarrwingmonkeypoundcake");
    L.clear();
    ss = string("fooo");
    L.push_back(ss);
    ss = string("barr");
    L.push_back(ss);
    ss = string("wing");
    L.push_back(ss);
    ss = string("ding");
    L.push_back(ss);
    ss = string("wing");
    L.push_back(ss);
    result = solution.findSubstring(S, L);
    print_int(result);

    S = string("abababab");
    L.clear();
    ss = string("a");
    L.push_back(ss);
    ss = string("b");
    L.push_back(ss);
    ss = string("a");
    L.push_back(ss);
    result = solution.findSubstring(S, L);
    print_int(result);

    S = string("aaabbbc");
    L.clear();
    ss = string("a");
    L.push_back(ss);
    ss = string("a");
    L.push_back(ss);
    ss = string("b");
    L.push_back(ss);
    ss = string("b");
    L.push_back(ss);
    ss = string("c");
    L.push_back(ss);
    result = solution.findSubstring(S, L);
    print_int(result);

    S = string("abaababbaba");
    L.clear();
    ss = string("ab");
    L.push_back(ss);
    ss = string("ba");
    L.push_back(ss);
    ss = string("ab");
    L.push_back(ss);
    ss = string("ba");
    L.push_back(ss);
    result = solution.findSubstring(S, L);
    print_int(result);
    return 0;
}

