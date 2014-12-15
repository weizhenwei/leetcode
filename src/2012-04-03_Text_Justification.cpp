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
 * File: 2012-04-03_Text_Justification.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/text-justification/
 * Given an array of words and a length L, format the text such that each line
 * has exactly L characters and is fully (left and right) justified.
 *
 * You should pack your words in a greedy approach; that is, pack as many words
 * as you can in each line. Pad extra spaces ' ' when necessary so that each
 * line has exactly L characters.
 *
 * Extra spaces between words should be distributed as evenly as possible. If
 * the number of spaces on a line do not divide evenly between words, the empty
 * slots on the left will be assigned more spaces than the slots on the right.
 *
 * For the last line of text, it should be left justified and no extra space is
 * inserted between words.
 *
 * For example,
 * words: ["This", "is", "an", "example", "of", "text", "justification."]
 * L: 16.
 *
 * Return the formatted lines as:
 * [
 *    "This    is    an",
 *    "example  of text",
 *    "justification.  "
 * ]
 * Note: Each word is guaranteed not to exceed L in length.
 *
 * Corner Cases:
 * A line other than the last line might contain only one word. What
 * should you do in this case? In this case, that line should be left-justified.
 *
 *
 * Date: 2014.12.15
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <vector>
#include <string>

using std::vector;
using std::string;

// originates from:
// https://oj.leetcode.com/discuss/13610/share-my-concise-c-solution-less-than-20-lines
class Solution_Text_Justification {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        for (int i = 0, k, l; i < words.size(); i += k) {
            for (k = l = 0; (i + k < words.size()) && (l + words[i+k].size() <= L - k); k++) {
                l += words[i+k].size();
            }

            string tmp = words[i];
            for (int j = 0; j < k - 1; j++) {
                if (i + k >= words.size()) {
                    tmp += " ";
                } else {
                    tmp += string((L - l) / (k - 1) + (j < (L - l) % (k - 1)), ' ');
                }
                tmp += words[i+j+1];
            }  // for j

            tmp += string(L - tmp.size(), ' ');
            res.push_back(tmp);
        }  // for i

        return res;
    }
};

static void print_vector(vector<string> &v) {
    for (int i = 0; i < v.size(); i++) {
        printf("%s\n", v[i].c_str());
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Text_Justification solution;
    vector<string> words;
    words.push_back("This");
    words.push_back("is");
    words.push_back("an");
    words.push_back("example");
    words.push_back("of");
    words.push_back("text");
    words.push_back("justification");

    printf("words:\n");
    print_vector(words);

    int L = 15;
    vector<string> full = solution.fullJustify(words, L);
    printf("full justification:\n");
    print_vector(full);

    words.clear();
    words.push_back("what");
    words.push_back("must");
    words.push_back("be");
    words.push_back("shall");
    words.push_back("be.");
    L = 12;
    printf("words:\n");
    print_vector(words);
    full = solution.fullJustify(words, L);
    printf("full justification:\n");
    print_vector(full);

    return 0;
}

