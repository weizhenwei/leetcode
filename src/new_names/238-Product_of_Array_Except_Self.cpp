/*
 *
 * Copyright (c) 2015, weizhenwei
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
 * File: 238-Product_of_Array_Except_Self.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/product-of-array-except-self/
 * Given an array of n integers where n > 1, nums, return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].

 * Solve it without division and in O(n).

 * For example, given [1,2,3,4], return [24,12,8,6].

 * Follow up:
 * Could you solve it with constant space complexity? (Note: The output array does
 * not count as extra space for the purpose of space complexity analysis.)
 *
 *
 * Date: 2015.09.21
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <vector>

using std::vector;

class Solution_Product_of_Array_Except_Self {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result = vector<int>(nums.size(), 1);

        long int product = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            product *= nums[i];
            result[i+1] = product;
        }

        product = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            product *= nums[i];
            result[i-1] *= product;
        }

        return result;
    }
};

static void printVector(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

static void testcase() {
    Solution_Product_of_Array_Except_Self solution;
    vector<int> nums, product;

    nums.clear();
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);

    product = solution.productExceptSelf(nums);
    printVector(nums);
    printVector(product);

    nums.clear();
    nums.push_back(1);
    nums.push_back(2);

    product = solution.productExceptSelf(nums);
    printVector(nums);
    printVector(product);

    nums.clear();
    nums.push_back(1000);
    nums.push_back(1000);
    nums.push_back(1000);
    nums.push_back(1000);

    product = solution.productExceptSelf(nums);
    printVector(nums);
    printVector(product);
}

int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

