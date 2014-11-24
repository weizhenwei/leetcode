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
 * File: 2012-02-12_Generate_Parentheses.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/generate-parentheses/
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 *
 *
 * Date: 2014.11.24
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution_Generate_Parenthesis {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        addingParenthesis(result, string(""), n, 0);

        return result;
    }
    
    void addingParenthesis(vector<string> &v, string current,
            int left, int right) {
        if (left == 0 && right == 0) {
            v.push_back(current);
            return;
        }

        if (left > 0) {
            addingParenthesis(v, current + "(", left - 1, right + 1);
        }
        if (right > 0) {
            addingParenthesis(v, current + ")", left, right - 1);
        }
    }
};

static void print_vector(vector<string> &v) {
    for (int i = 0; i < v.size(); i++) {
        printf("%s\n", v[i].c_str());
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Generate_Parenthesis solution;
    int n = 1;
    vector<string> parentheses = solution.generateParenthesis(n);
    printf("n = %d\n", n);
    print_vector(parentheses);

    n = 2;
    parentheses = solution.generateParenthesis(n);
    printf("n = %d\n", n);
    print_vector(parentheses);

    n = 3;
    parentheses = solution.generateParenthesis(n);
    printf("n = %d\n", n);
    print_vector(parentheses);

    n = 4;
    parentheses = solution.generateParenthesis(n);
    printf("n = %d\n", n);
    print_vector(parentheses);

    return 0;
}
