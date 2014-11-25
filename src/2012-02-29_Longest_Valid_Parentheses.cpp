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
 * File: 2012-02-29_Longest_Valid_Parentheses.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/longest-valid-parentheses/
 * Given a string containing just the characters '(' and ')', find the length of
 * the longest valid (well-formed) parentheses substring.
 *
 * For "(()", the longest valid parentheses substring is "()", which has length
 * = 2.
 *
 * Another example is ")()())", where the longest valid parentheses substring is
 * "()()", which has length = 4.
 *
 *
 * Date: 2014.11.25
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>

using std::max;
using std::string;
using std::stack;
using std::vector;

class Solution_Longest_Valid_Parentheses {
public:
    int longestValidParenthesesError(string s) {
        if (s.size() <= 1) {
            return 0;
        }

        int longest = 0;
        int start = 0;
        while (start < s.size()) {
            stack<char> charStack;
            int current = start;
            int pairs = 0;
            int flag = 0;
            while (current < s.size()) {
                switch(s[current]) {
                    case '(':
                        {
                            charStack.push(s[current]);
                            current++;
                            break;
                        }
                    case ')':
                        {
                            if (charStack.empty()) {
                                start = current + 1;
                                flag = 1;
                                break;
                            } else {
                                assert(charStack.top() == '(');
                                pairs++;
                                if (longest < pairs * 2) {
                                    longest = pairs * 2;
                                }
                                charStack.pop();
                                current++;
                                break;
                            }
                        }
                    default:
                        assert(0);
                        break;
                }
                if (flag)
                    break;
            }  // while inner;

            start = current + 1;
        }  // while

        return longest;
    }

    int longestValidParentheses(string s) {
        if (s.length() <= 1)
            return 0;

        int curMax = 0;
        vector<int> longest(s.size(), 0);
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    longest[i] = (i - 2) >= 0 ? (longest[i-2] + 2) : 2;
                    curMax = max(longest[i], curMax);
                } else { // if s[i-1] == ')', combine the previous length.
                    if (i - longest[i-1] - 1 >= 0
                            && s[i-longest[i-1]-1] == '(') {
                        longest[i] = longest[i-1] + 2
                            + ((i-longest[i-1]-2 >= 0) ? longest[i-longest[i-1]-2] : 0);
                        curMax = max(longest[i], curMax);
                    }
                }
            }
        }

        return curMax;
    }

};

int main(int argc, char *argv[]) {
    Solution_Longest_Valid_Parentheses solution;
    string s = string("(()");
    int longest = solution.longestValidParentheses(s);
    printf("s = %s, longest = %d\n", s.c_str(), longest);

    s = string("((");
    longest = solution.longestValidParentheses(s);
    printf("s = %s, longest = %d\n", s.c_str(), longest);

    s = string(")()))");
    longest = solution.longestValidParentheses(s);
    printf("s = %s, longest = %d\n", s.c_str(), longest);

    s = string("((((()()))");
    longest = solution.longestValidParentheses(s);
    printf("s = %s, longest = %d\n", s.c_str(), longest);

    s = string("()(()");
    longest = solution.longestValidParentheses(s);
    printf("s = %s, longest = %d\n", s.c_str(), longest);

    return 0;
}

