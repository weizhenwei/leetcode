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
 * File: 93-Restore_IP_Addresses.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/restore-ip-addresses/
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 *
 * For example:
 * Given "25525511135",
 *
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 *
 *
 * Date: 2015.01.21
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <string>
#include <vector>

// these two function are new in c++ 11;
// compiled with -std=c++0x
using std::stoi;
using std::stol;

using std::string;
using std::vector;

// originates from:
// https://oj.leetcode.com/discuss/6712/solution-explanation-improvement-suggestion-appreciated
class Solution_Restore_IP_Addresses {
private:
    vector<string> output;

public:
    vector<string> restoreIpAddresses(string s) {
        if (s.empty()) {
            return output;
        }
        vector<string> x(4);
        DFS(0, x, s, 0);
        return output;
    }

    void DFS(int t, vector<string> &x, string &s, int i) {
        if (i > s.size() - 1) {
            return;
        }

        if (t == 3) {
            if (s.size() - i > 3 || (s[i] == '0' && i < s.size() - 1)) {
                return;
            }
            string remainder = s.substr(i);
            if (stoi(remainder) < 256) {
                x[t] = remainder;
                string ip;
                int k = 0;
                for (int j = 0; j < 7; j++) {
                    if ((j & 1) == 0) {
                        ip.append(x[k++]);
                    } else {
                        ip.append(".");
                    }
                }  // for
                output.push_back(ip);
            }
            return;
        }
        x[t] =  s.substr(i, 1);
        DFS(t + 1, x, s, i + 1);
        if (s[i] == '0') {
            return;
        }
        if (s.size() - i >= 2) {
            x[t] = s.substr(i, 2);
            DFS(t + 1, x, s, i + 2);
        }
        if (s.size() - 1 >= 3 && stol(s.substr(i, 3)) < 256) {
            x[t] = s.substr(i, 3);
            DFS(t + 1, x, s, i + 3);
        }
    }
};

int main(int argc, char *argv[]) {
    Solution_Restore_IP_Addresses solution;
    string str = "25525511135";
    printf("%s\n", str.c_str());
    vector<string> ips = solution.restoreIpAddresses(str);
    for (int i = 0; i < ips.size(); i++) {
        printf("%s\n", ips[i].c_str());
    }

    return 0;
}
