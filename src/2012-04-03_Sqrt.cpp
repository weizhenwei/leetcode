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
 * File: 2012-04-03_Sqrt.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/sqrtx/
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x.
 *
 *
 * Date: 2014.11.05
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>

class Solution_Sqrt {
public:
    int sqrt(int x) {
        if (x == 0) {
            return 0;
        }
        if (x <= 3) {
            return 1;
        }

        int left = 2;
        int right = x - 1;
        while (left < right) {
            long long int middle = ((long long int) left + (long long int) right) / 2;
            if ((long long int) middle * (long long int) middle
                    == (long long int) x) {
                return middle;
            } else if ((long long int)middle * (long long int) middle
                        < (long long int) x) {
                if ((long long int) (middle + 1) * (long long int) (middle + 1)
                            > (long long int) x) {
                    return middle;
                } else {
                    left = middle + 1;
                }
            } else {
                if ((long long int) (middle - 1) * (long long int) (middle - 1)
                        < (long long int) x) {
                    return middle - 1;
                } else {
                    right = middle - 1;
                }
            }
        }  // while

        return -1;  // something error;
    }
};

int main(int argc, char *argv[]) {
    Solution_Sqrt solution;
    int x = 0;
    int root = solution.sqrt(x);
    printf("x = %d, root = %d\n", x, root);

    x = 2147395599;
    root = solution.sqrt(x);
    printf("x = %d, root = %d\n", x, root);

    x = 2147483647;
    root = solution.sqrt(x);
    printf("x = %d, root = %d\n", x, root);

    x = 1;
    root = solution.sqrt(x);
    printf("x = %d, root = %d\n", x, root);

    x = 2;
    root = solution.sqrt(x);
    printf("x = %d, root = %d\n", x, root);

    x = 3;
    root = solution.sqrt(x);
    printf("x = %d, root = %d\n", x, root);

    x = 4;
    root = solution.sqrt(x);
    printf("x = %d, root = %d\n", x, root);

    x = 5;
    root = solution.sqrt(x);
    printf("x = %d, root = %d\n", x, root);

    x = 6;
    root = solution.sqrt(x);
    printf("x = %d, root = %d\n", x, root);

    x = 7;
    root = solution.sqrt(x);
    printf("x = %d, root = %d\n", x, root);

    x = 8;
    root = solution.sqrt(x);
    printf("x = %d, root = %d\n", x, root);

    x = 9;
    root = solution.sqrt(x);
    printf("x = %d, root = %d\n", x, root);

    x = 10;
    root = solution.sqrt(x);
    printf("x = %d, root = %d\n", x, root);

    x = 11;
    root = solution.sqrt(x);
    printf("x = %d, root = %d\n", x, root);

    x = 12;
    root = solution.sqrt(x);
    printf("x = %d, root = %d\n", x, root);

    x = 13;
    root = solution.sqrt(x);
    printf("x = %d, root = %d\n", x, root);

    x = 14;
    root = solution.sqrt(x);
    printf("x = %d, root = %d\n", x, root);

    x = 15;
    root = solution.sqrt(x);
    printf("x = %d, root = %d\n", x, root);

    x = 16;
    root = solution.sqrt(x);
    printf("x = %d, root = %d\n", x, root);

    x = 26;
    root = solution.sqrt(x);
    printf("x = %d, root = %d\n", x, root);


    return 0;
}

