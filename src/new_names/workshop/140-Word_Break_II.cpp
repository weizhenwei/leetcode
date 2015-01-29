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
 * File: 140-Word_Break_II.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/word-break-ii/
 * Given a string s and a dictionary of words dict, add spaces in s to construct
 * a sentence where each word is a valid dictionary word.
 *
 * Return all such possible sentences.
 *
 * For example, given
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 *
 * A solution is ["cats and dog", "cat sand dog"].
 *
 *
 * Date: 2015.01.28
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <string>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_set;
using std::vector;


class Solution_Word_Break_II {
private:
    bool subWordBreak(vector<string> &results, string s,
            unordered_set<string> &dict) {
        if (s.size() == 0) {
            return true;
        }

        for (int i = 1; i <= s.size(); i++) {
            string substr = s.substr(0, i);
            if (dict.find(substr) != dict.end()) {
                vector<string> subresult;
                if (subWordBreak(subresult, s.substr(i, s.size()), dict)) {
                    if (subresult.size() > 0) {
                        for (int j = 0; j < subresult.size(); j++) {
                            string elem = substr + " " + subresult[j];
                            results.push_back(elem);
                        }  // for j
                    } else {
                        results.push_back(substr);
                    }
                }
            }
        }  // for i

        if (results.empty()) {
            return false;
        } else {
            return true;
        }
    }

public:
    // it's obvious that recursive version will cause TLE.
    vector<string> wordBreakRecursive(string s, unordered_set<string> &dict) {
        vector<string> results;
        if (s.size() == 0) {
            return results;
        }

        if (subWordBreak(results, s, dict)) {
            return results;
        } else {
            return vector<string>();
        }
    }

    typedef struct elem {
        string sentence;
        int position;
        elem(string s, int p): sentence(s), position(p) {}
    } elem;

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        if (s.size() == 0 || dict.size() == 0) {
                return vector<string>();
        }
        unordered_set<string>::iterator iter;
        iter = dict.begin();
        int minLen = (*iter).size();
        int maxLen = (*iter).size();
        iter++;
        for (iter; iter != dict.end(); iter++) {
            if (minLen > (*iter).size()) {
                minLen = (*iter).size();
            }
            if (maxLen < (*iter).size()) {
                maxLen = (*iter).size();
            }
        }  // for

        vector<elem> dp;
        for (int i = minLen; i <= maxLen; i++) {
            string substr = s.substr(0, i);
            if (dict.find(substr) != dict.end()) {
                printf("substr = %s, i = %d\n", substr.c_str(), i);
                struct elem e(substr, i);
                dp.push_back(e);
            }
        }  // for

        while (1) {
            vector<elem>::iterator iter;
            for (iter = dp.begin(); iter != dp.end(); iter++) {
                int position = (*iter).position;
                for (int i = minLen; i <= maxLen; i++) {
                    string substr = s.substr(position, i);
                    if (dict.find(substr) != dict.end()) {
                        printf("ssssubstr = %s, i = %d\n", substr.c_str(), i);
                    }
                }  // for i
            }  // for iter

            break;
        }

        return vector<string>();
    }
};

int main(int argc, char *argv[]) {
    Solution_Word_Break_II solution;
    string s = "catsanddog";
    unordered_set<string> dict;
    dict.insert("cat");
    dict.insert("cats");
    dict.insert("and");
    dict.insert("sand");
    dict.insert("dog");
    vector<string> result = solution.wordBreak(s, dict);
    for (int i = 0; i < result.size(); i++) {
        printf("%s\n", result[i].c_str());
    }

    return 0;
}

