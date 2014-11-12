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
 * File: 2013-11-27_Evaluate_Reverse_Polish_Notation.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another
 * expression.
 *
 * Some examples:
 *   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *     ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 *
 *
 * Date: 2014.11.11
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stack>
#include <vector>

using std::stack;
using std::string;
using std::vector;

class Solution_Evaluate_Reverse_Polish_Notation {
public:
    int evalRPN(vector<string> &tokens) {
        int i = 0;
        stack<int> tokenStack;
        for (i = 0; i < tokens.size(); i++) {
            string str = tokens[i];
            if (str == "+") {
                int second = tokenStack.top();
                tokenStack.pop();
                int first = tokenStack.top();
                tokenStack.pop();
                int add = first + second;
                tokenStack.push(add);
            } else if (str == "-") {
                int second = tokenStack.top();
                tokenStack.pop();
                int first = tokenStack.top();
                tokenStack.pop();
                int sub = first - second;
                tokenStack.push(sub);
            } else if (str == "*") {
                int second = tokenStack.top();
                tokenStack.pop();
                int first = tokenStack.top();
                tokenStack.pop();
                int mul = first * second;
                tokenStack.push(mul);
            } else if (str == "/") {
                int second = tokenStack.top();
                tokenStack.pop();
                int first = tokenStack.top();
                tokenStack.pop();
                int div = first / second;
                tokenStack.push(div);
            } else {
                tokenStack.push(atoi(str.c_str()));
            }
        }  // for

        return tokenStack.top();
    }
};

static void print_vector(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        printf("%s ", v[i].c_str());
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Evaluate_Reverse_Polish_Notation solution;
    vector<string> rpn;
    rpn.push_back("2");
    rpn.push_back("1");
    rpn.push_back("+");
    rpn.push_back("3");
    rpn.push_back("*");
    print_vector(rpn);
    int result = solution.evalRPN(rpn);
    printf("result = %d\n", result);

    rpn.clear();
    rpn.push_back("4");
    rpn.push_back("13");
    rpn.push_back("5");
    rpn.push_back("/");
    rpn.push_back("+");
    print_vector(rpn);
    result = solution.evalRPN(rpn);
    printf("result = %d\n", result);
    return 0;
}

