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
 * File: 79-Word_Search.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/word-search/
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell, where
 * "adjacent" cells are those horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 *
 * For example,
 * Given board =
 *
 * [
 *   ["ABCE"],
 *   ["SFCS"],
 *   ["ADEE"]
 * ]
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 *
 *
 * Date: 2014.12.24
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution_Word_Search {
private:
    vector<vector<char> > *board;
    string *word;
    bool **used;
private:
    bool isInboard(int i, int j)
    {
        if(i < 0)return false;
        if(i >= board->size())return false;
        if(j < 0)return false;
        if(j >= (*board)[i].size())return false;
        return true;
    }

    bool DFS(int si, int sj, int n)
    {
        if(n == word->size())return true;
        if(isInboard(si, sj))
        {
            if(!used[si][sj] && (*board)[si][sj] == (*word)[n])
            {
                used[si][sj] = true;
                bool ret = false;
                if(DFS(si+1, sj, n+1))
                    ret = true;
                else if(DFS(si-1, sj, n+1))
                    ret = true;
                else if(DFS(si, sj+1, n+1))
                    ret = true;
                else if(DFS(si, sj-1, n+1))
                    ret = true;
                used[si][sj] = false;
                return ret;
            }
        }
        return false;
    }

public:
    bool exist(vector<vector<char> > &board, string word) {
        if(board.size() == 0)return false;
        this->board = &board;
        this->word = &word;
        used = new bool*[board.size()];
        for(int i = 0; i < board.size(); i ++)
        {
            used[i] = new bool[board[i].size()];
            for(int j = 0; j < board[i].size(); j ++)
                used[i][j] = false;
        }
        for(int i = 0; i < board.size(); i ++)
            for(int j = 0; j < board[i].size(); j ++)
                if(DFS(i, j, 0))return true;
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution_Word_Search solution;
    vector<vector<char> > board;
    vector<char> elem;
    elem.push_back('A');
    elem.push_back('B');
    elem.push_back('C');
    elem.push_back('E');
    board.push_back(elem);
    elem.clear();
    elem.push_back('S');
    elem.push_back('F');
    elem.push_back('C');
    elem.push_back('S');
    board.push_back(elem);
    elem.clear();
    elem.push_back('A');
    elem.push_back('D');
    elem.push_back('E');
    elem.push_back('E');
    board.push_back(elem);

    string word = string("ABCCED");
    bool exists = solution.exist(board, word);
    printf("%d\n", exists);

    return 0;
}

