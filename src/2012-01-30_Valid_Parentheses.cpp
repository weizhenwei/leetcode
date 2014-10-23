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
 * File: 2012-01-30_Valid_Parentheses.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/valid-parentheses/
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}"
 * are all valid but "(]" and "([)]" are not.
 *
 * Date: 2014.10.21
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <stack>
#include <string>

using std::stack;
using std::string;

class Solution_Valid_Parentheses {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1)
            return false;

        int i = 0;
        stack<char> tstack;
        while (i < s.size()) {
            switch (s[i]) {
                case '(':
                case '[':
                case '{':
                    tstack.push(s[i]);
                    break;
                case ')':
                    if (tstack.empty() == true)
                        return false;
                    if (tstack.top() != '(') {
                        return false;
                    } else {
                        tstack.pop();
                    }
                    break;
                case ']':
                    if (tstack.empty() == true)
                        return false;
                    if (tstack.top() != '[') {
                        return false;
                    } else {
                        tstack.pop();
                    }
                    break;
                case '}':
                    if (tstack.empty() == true)
                        return false;
                    if (tstack.top() != '{') {
                        return false;
                    } else {
                        tstack.pop();
                    }
                    break;
                default:
                    return false;

            }
            i++;
        }

        if (tstack.empty() != true)
            return false;
        else
            return true;
    }
};

int main(int argc, char *argv[]) {
    Solution_Valid_Parentheses solution;
    string s;
    bool result;

    s = "()()[][]{}";
    result = solution.isValid(s);
    printf("s = %s, result = %d\n", s.c_str(), result);

    s = ")(()([[]]}{";
    result = solution.isValid(s);
    printf("s = %s, result = %d\n", s.c_str(), result);

    s = "(())[{{}}]()";
    result = solution.isValid(s);
    printf("s = %s, result = %d\n", s.c_str(), result);

    s = "(())[{{}}](";
    result = solution.isValid(s);
    printf("s = %s, result = %d\n", s.c_str(), result);

    s = "(())[{{}}])";
    result = solution.isValid(s);
    printf("s = %s, result = %d\n", s.c_str(), result);

    s = "(())[{{}}]((";
    result = solution.isValid(s);
    printf("s = %s, result = %d\n", s.c_str(), result);

    s = "(())[{{}}]))";
    result = solution.isValid(s);
    printf("s = %s, result = %d\n", s.c_str(), result);

    return 0;
}
