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
 * File: 2012-03-03_Valid_Sudoku.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/valid-sudoku/
 * Determine if a Sudoku is valid,
 * according to: Sudoku Puzzles - The Rules.
 * http://sudoku.com.au/TheRules.aspx
 *
 * The Sudoku board could be partially filled, where empty cells are filled with
 * the character '.'.
 *
 *
 * A partially filled sudoku which is valid.
 *
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only the
 * filled cells need to be validated.
 *
 *
 * Date: 2014.12.02
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <vector>

using std::vector;

class Solution_Valid_Sudoku {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int judge[9] = {0};
        assert(board.size() == 9);
        assert(board.size() == board[0].size());

        // row judge
        for (int i = 0; i < board.size(); i++) {
            memset(judge, 0, 9 * sizeof(int));
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                assert(board[i][j] >= '1' && board[i][j] <= '9');
                if (judge[board[i][j] - '0' - 1] == 0) {
                    judge[board[i][j] - '0' - 1] = 1;
                } else if (judge[board[i][j] - '0' - 1] == 1) {
                    return false;
                } else {
                    assert(0);
                }
            }  // for i;
        }  // for j;

        // column judge
        for (int j = 0; j < board.size(); j++) {
            memset(judge, 0, 9 * sizeof(int));
            for (int i = 0; i < board[j].size(); i++) {
                if (board[i][j] == '.') {
                    continue;
                }

                assert(board[i][j] >= '1' && board[i][j] <= '9');
                if (judge[board[i][j] - '0' - 1] == 0) {
                    judge[board[i][j] - '0' - 1] = 1;
                } else if (judge[board[i][j] - '0' - 1] == 1) {
                    return false;
                } else {
                    assert(0);
                }
            }  // for i;
        }  // for j;
        
        // sub-box judge
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int rowStart = i * 3;
                int rowEnd = rowStart + 3;
                int columnStart = j * 3;
                int columnEnd = columnStart + 3;

                memset(judge, 0, 9 * sizeof(int));
                for (int m = rowStart; m < rowEnd; m++) {
                    for (int n = columnStart; n < columnEnd; n++) {
                        if (board[m][n] == '.') {
                            continue;
                        }

                        assert(board[m][n] >= '1' && board[m][n] <= '9');

                        int idx = (m - rowStart) * 3 + (n - columnStart);
                        if (judge[board[m][n] - '0' - 1] == 0) {
                            judge[board[m][n] - '0' - 1] = 1;
                        } else if (judge[board[m][n] - '0' -1] == 1) {
                            return false;
                        } else {
                            assert(0);
                        }
                    }  // for n;
                } // for m;
                printf("end one sub-box\n");
            }  // for j;
        }  // for i;

        return true;
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
    Solution_Valid_Sudoku solution;
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
    bool valid = solution.isValidSudoku(board);
    printf("is valid %d\n", valid);
}

void testcase2() {
    Solution_Valid_Sudoku solution;
    vector<vector<char> > board;
    for (int i = 0; i < 9; i++) {
        vector<char> elem = vector<char>(9, '.');
        board.push_back(elem);
    }

    board[0][4] = '5';
    board[0][7] = '1';

    board[1][1] = '4';
    board[1][3] = '3';

    board[2][5] = '3';
    board[2][8] = '1';

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
    bool valid = solution.isValidSudoku(board);
    printf("is valid %d\n", valid);
}

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();


    return 0;
}


