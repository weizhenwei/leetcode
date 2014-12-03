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
 * File: 2012-03-04_Sudoku_Solver.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/sudoku-solver/
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * Empty cells are indicated by the character '.'.
 *
 * You may assume that there will be only one unique solution.
 *
 *
 * Date: 2014.12.03
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unordered_map>
#include <vector>

using std::vector;
using std::unordered_map;
using std::pair;

// originate from:
// https://oj.leetcode.com/discuss/15612/bacetrack-c-sollution-with-bit-ops-ac-in-36ms
// can't understand!

class Solution_Sudoku_Solver {
public:
    unordered_map<int, int> int2bit;
    unordered_map<int, int> bit2int;

    bool solveSudoku(int n, vector<pair<int, int> > &blank,
            vector<vector<char> > &board, vector<int> &row,
            vector<int> &col, vector<int> &cell) {
        if (n == blank.size()) {
            return true;
        }

        int i = blank[n].first;
        int j = blank[n].second;
        int idx = (i / 3) * 3 + j / 3;
        int pos = row[i] & col[j] & cell[idx];
        while (pos) {
            int p = pos & (-pos);
            pos -= p;
            board[i][j] = '0' + bit2int[p];
            row[i] &= ~p;
            col[j] &= ~p;
            cell[idx] &= ~p;

            if (solveSudoku(n + 1, blank, board, row, col, cell) == true) {
                return true;
            }

            row[i] |= p;
            col[j] |= p;
            cell[idx] |= p;
        }  // while

        return false;
    }

    void solveSudoku(vector<vector<char> > &board) {
        for (int k = 1; k <= 9; k++) {
            int2bit[k] = 1 << (k - 1);
            bit2int[1 << (k - 1)] = k;
        }

        int limit = (1 << 9) - 1;
        vector<int> row(9, limit);
        vector<int> col(9, limit);
        vector<int> cell(9, limit);
        vector<pair<int, int> > blank;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int k = int2bit[board[i][j] - '0'];
                    row[i] &= ~k;
                    col[j] &= ~k;
                    int idx = (i / 3) * 3 + j / 3;
                    cell[idx] &= ~k;
                } else {
                    blank.push_back(pair<int, int>(i, j));
                }
            }  // j
        }  // i

        solveSudoku(0, blank, board, row, col, cell);
    }
};

static void print_board(vector<vector<char> > &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void testcase1() {
    Solution_Sudoku_Solver solution;
    vector<vector<char> > board;
    for (int i = 0; i < 9; i++) {
        vector<char> elem = vector<char>(9, '.');
        board.push_back(elem);
    }

    board[0][0] = '5';
    board[0][1] = '3';
    board[0][4] = '7';

    board[1][0] = '6';
    board[1][3] = '1';
    board[1][4] = '9';
    board[1][5] = '5';

    board[2][1] = '9';
    board[2][2] = '8';
    board[2][7] = '6';

    board[3][0] = '8';
    board[3][4] = '6';
    board[3][8] = '3';

    board[4][0] = '4';
    board[4][3] = '8';
    board[4][5] = '3';
    board[4][8] = '1';

    board[5][0] = '7';
    board[5][4] = '2';
    board[5][8] = '6';

    board[6][1] = '6';
    board[6][6] = '2';
    board[6][7] = '8';

    board[7][3] = '4';
    board[7][4] = '1';
    board[7][5] = '9';
    board[7][8] = '5';

    board[8][4] = '8';
    board[8][7] = '7';
    board[8][8] = '9';

    print_board(board);
    solution.solveSudoku(board);
    print_board(board);
}

void testcase2() {
    Solution_Sudoku_Solver solution;
    vector<vector<char> > board;
    for (int i = 0; i < 9; i++) {
        vector<char> elem = vector<char>(9, '.');
        board.push_back(elem);
    }

    board[0][4] = '5';
    board[0][7] = '1';

    board[1][1] = '4';

    board[2][5] = '3';

    board[3][0] = '8';
    board[3][7] = '2';

    board[4][2] = '2';
    board[4][4] = '7';

    board[5][1] = '1';
    board[5][2] = '5';

    board[6][5] = '2';

    board[7][1] = '2';
    board[7][3] = '9';

    board[8][2] = '4';

    print_board(board);
    solution.solveSudoku(board);
    print_board(board);
}

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();

    return 0;
}

