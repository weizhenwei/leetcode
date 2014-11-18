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
 * File: 2012-11-06_Best_Time_to_Buy_and_Sell_Stock_II.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 * Say you have an array for which the ith element is the price of a given stock
 * on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most two
 * transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 *
 *
 * Date: 2014.11.18
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <vector>
#include <algorithm>

using std::max;
using std::min;
using std::vector;

class Solution_Stock_III {
public:
    int maxProfitSingle(vector<int> &prices, int start, int end) {

        int maxprofit = 0;
        int prevmin = prices[start];
        for (int pivot = start + 1; pivot <= end; pivot++) {
            maxprofit = max(maxprofit, prices[pivot] - prevmin);
            prevmin = min(prevmin, prices[pivot]);
        }

        return maxprofit;
    }

    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) {
            return 0;
        }

        // first sell once;
        int max = maxProfitSingle(prices, 0, prices.size() - 1);
        int pivot = 1;
        while (pivot < prices.size() - 1) {
            int firstsell = maxProfitSingle(prices, 0, pivot);
            int secondsell = maxProfitSingle(prices,
                    pivot + 1, prices.size() - 1);

            if (max < firstsell + secondsell) {
                max = firstsell + secondsell;
            }
            pivot++;
        }  // while

        return max;
    }

    // originate from
    // https://oj.leetcode.com/discuss/10427/share-my-simple-o-n-time-solution
    int maxProfitGood(vector<int> &prices) {
        if (prices.size() < 2)
            return 0;
        int len = prices.size();
        int result = 0;
        int low = prices[0];
        int high = prices[len - 1];

        vector<int> profits_history = vector<int>(len, 0);
        for (int i = 0; i < len; i++) {
            low = min(low, prices[i]);
            result = max(result, prices[i] - low);
            profits_history[i]=result; 
        }

        for (int i = len - 1; i >= 0; i--) {
            high = max(high, prices[i]);
            result = max(result, high - prices[i] + profits_history[i]);
        }

        return result;
    }
};

static void print_vector(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Stock_III solution;
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(3);
    prices.push_back(4);
    prices.push_back(5);
    prices.push_back(6);
    printf("prices:");
    print_vector(prices);
    int maxprofit = solution.maxProfit(prices);
    printf("max profit: %d \n", maxprofit);
    maxprofit = solution.maxProfitGood(prices);
    printf("max profit: %d \n", maxprofit);

    prices.clear();
    prices.push_back(6);
    prices.push_back(1);
    prices.push_back(3);
    prices.push_back(4);
    prices.push_back(8);
    prices.push_back(5);
    prices.push_back(2);
    prices.push_back(12);
    printf("prices:");
    print_vector(prices);
    maxprofit = solution.maxProfit(prices);
    printf("max profit: %d \n", maxprofit);
    maxprofit = solution.maxProfitGood(prices);
    printf("max profit: %d \n", maxprofit);

    prices.clear();
    prices.push_back(4);
    prices.push_back(2);
    printf("prices:");
    print_vector(prices);
    maxprofit = solution.maxProfit(prices);
    printf("max profit: %d \n", maxprofit);
    maxprofit = solution.maxProfitGood(prices);
    printf("max profit: %d \n", maxprofit);

    prices.clear();
    prices.push_back(4);
    prices.push_back(2);
    prices.push_back(1);
    printf("prices:");
    print_vector(prices);
    maxprofit = solution.maxProfit(prices);
    printf("max profit: %d \n", maxprofit);
    maxprofit = solution.maxProfitGood(prices);
    printf("max profit: %d \n", maxprofit);

    return 0;
}

