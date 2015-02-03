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
 * File: 134-Gas_Station.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/gas-station/
 * There are N gas stations along a circular route, where the amount of gas at
 * station i is gas[i].
 *
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to
 * travel from station i to its next station (i+1). You begin the journey with
 * an empty tank at one of the gas stations.
 *
 * Return the starting gas station's index if you can travel around the circuit
 * once, otherwise return -1.
 *
 * Note:
 * The solution is guaranteed to be unique.
 *
 *
 * Date: 2015.02.03
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <vector>

using std::vector;

class Solution_Gas_Station {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.size() == 0 || cost.size() == 0 || gas.size() != cost.size()) {
            return -1;
        }

        vector<int> remain(gas.size(), 0);
        for (int i = 0; i < gas.size(); i++) {
            remain[i] = gas[i] - cost[i];
        }

        for (int i = 0; i < remain.size();) {
            while (remain[i] < 0 && i < remain.size()) {
                i++;
            }
            if (i == remain.size()) {
                return -1;
            }

            vector<int> loop(remain.begin() + i, remain.end());
            loop.insert(loop.end(), remain.begin(), remain.begin() + i);
            int left = 0;
            bool ok = true;
            int j = 0;
            for (j = 0; j < loop.size(); j++) {
                left += loop[j];
                if (left < 0) {
                    ok = false;
                    break;
                }
            }  // for j
            if (ok) {
                return i;
            } else {  // this optimization is important!
                i = i + j;
            }
        }  // for i

        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution_Gas_Station solution;
    vector<int> gas;
    gas.push_back(2);
    gas.push_back(4);
    vector<int> cost;
    cost.push_back(3);
    cost.push_back(4);
    int ok = solution.canCompleteCircuit(gas, cost);
    printf("ok = %d\n", ok);

    gas.clear();
    gas.push_back(2);
    gas.push_back(1);
    gas.push_back(3);
    cost.clear();
    cost.push_back(3);
    cost.push_back(1);
    cost.push_back(2);
    ok = solution.canCompleteCircuit(gas, cost);
    printf("ok = %d\n", ok);

    gas.clear();
    gas.push_back(1);
    gas.push_back(2);
    cost.clear();
    cost.push_back(2);
    cost.push_back(1);
    ok = solution.canCompleteCircuit(gas, cost);
    printf("ok = %d\n", ok);

    return 0;
}

