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
 * File: 278-First_Bad_Version.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/first-bad-version/
 * You are a product manager and currently leading a team to develop a new
 * product. Unfortunately, the latest version of your product fails the quality
 * check. Since each version is developed based on the previous version, all the
 * versions after a bad version are also bad.

 * Suppose you have n versions [1, 2, ..., n] and you want to find out the first
 * bad one, which causes all the following ones to be bad.

 * You are given an API bool isBadVersion(version) which will return whether
 * version is bad. Implement a function to find the first bad version. You should
 * minimize the number of calls to the API.
 *
 *
 * Date: 2015.09.14
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>

class Solution_First_Bad_Version {
public:
    Solution_First_Bad_Version() : m_iBadVersion(0) {}
    void setBadVersion(int version) {
        m_iBadVersion = version;
    }
    bool isBadVersion(int version) {
        if (version >= m_iBadVersion) {
            return true;
        } else {
            return false;
        }
    }

    int firstBadVersion(int n) {
        if (n == 1) {
            return isBadVersion(n);
        }

        int left = 1;
        int right = n;
        int middle = (left + right) / 2;
        while (left <= right) {
            if (isBadVersion(middle)) {
                if (middle > 1 && !isBadVersion(middle - 1)) {
                    return middle;
                }
                right = middle - 1;
                middle = (left + right) / 2;
            } else {
                if (middle < n && isBadVersion(middle + 1)) {
                    return middle;
                }
                left = middle + 1;
                middle = (left + right) / 2;
            }
        }
    }
private:
    int m_iBadVersion;
};

void testcase() {
    Solution_First_Bad_Version solution;
    int firstBad = 3;
    int version = 3;
    solution.setBadVersion(firstBad);
    int foundBadVersion = solution.firstBadVersion(version);
    printf("firstBadVersion = %d, version = %d, found firstBadVersion = %d\n",
            firstBad, version, foundBadVersion);

    for (int i = 1; i < 10; i++) {
        for (int j = 1; j <= i; j++) {
            int firstBad = j;
            int version = i;
            solution.setBadVersion(firstBad);
            int foundBadVersion = solution.firstBadVersion(version);
            if (foundBadVersion != firstBad) {
                printf("ERROR: firstBadVersion = %d, version = %d, found firstBadVersion = %d\n",
                    firstBad, version, foundBadVersion);
            } else {
                printf("firstBadVersion = %d, version = %d, found firstBadVersion = %d\n",
                    firstBad, version, foundBadVersion);
            }
        }  // for j;
    }  // for i;
}

int main(int argc, char *argv[]) {
    testcase();
    return 0;
}

