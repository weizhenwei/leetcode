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
 * File: 2012-03-19_N_Queens.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/n-queens/
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 *
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 *
 * [
 *  [".Q..",  // Solution 1
 *   "...Q",
 *   "Q...",
 *   "..Q."],
 *
 *  ["..Q.",  // Solution 2
 *   "Q...",
 *   "...Q",
 *   ".Q.."]
 *  ]
 *
 *
 * Date: 2014.12.08
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using std::vector;
using std::string;

// originate from:
// https://oj.leetcode.com/discuss/3861/solved-with-backtracing
class Solution_N_Queens {
public:
    bool ok(vector<int> &col, int c, int idx) {
        // validate last queen with all previous queens
        for (int i = 0; i < idx; i++) {
            if (col[i] == c || abs(col[i] - c) == abs(i - idx))
                return false;  // clash!
        }  // for

        return true;
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<int> col = vector<int>(n, 0);
        vector<vector<string> > ans;
        int row = 0;

        while (1) {
            if (row == n) {
                // generate string for this solution;
                string str = string(n, '.');
                vector<string> t = vector<string>(n, str);
                for (int i = 0; i < n; i++) {
                    t[col[i]][i] = 'Q';
                }
                ans.push_back(t);
                
                // go back to previous row and incremen that queen by 1 column;
                col[--row]++;
            } else if (col[row] == n) {
                col[row--] = 0;  // rese this queen to column 0;
                if (row == -1)
                    break;

                // go back to previous row and incremen that queen by 1 column;
                col[row]++;
            } else if (!ok(col, col[row], row)) {
                col[row]++;  // problem at this column, so go to next column;
            } else {
                row++;  // everything is perfect, let's go to queen in next row;
            }
        }  // while

        return ans;
    }
};

static void print_matrix(vector<vector<string> > &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            printf("%s\n", matrix[i][j].c_str());
        }
        printf("\n\n");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_N_Queens solution;
    int n = 4;
    vector<vector<string> > ans = solution.solveNQueens(n);
    printf("n = %d\n", n);
    print_matrix(ans);

    n = 5;
    ans = solution.solveNQueens(n);
    printf("n = %d\n", n);
    print_matrix(ans);

    n = 6;
    ans = solution.solveNQueens(n);
    printf("n = %d\n", n);
    print_matrix(ans);

    return 0;
}

