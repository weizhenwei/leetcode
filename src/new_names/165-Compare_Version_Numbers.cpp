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
 * File: 165-Compare_Version_Numbers.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/compare-version-numbers/
 * Compare two version numbers version1 and version1.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise
 * return 0.
 *
 * You may assume that the version strings are non-empty and contain only digits
 * and the . character.
 * The . character does not represent a decimal point and is used to separate
 * number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it
 * is the fifth second-level revision of the second first-level revision.
 *
 * Here is an example of version numbers ordering:
 *
 * 0.1 < 1.1 < 1.2 < 13.37
 *
 *
 * Date: 2015.01.22
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <string>

using std::string;
using std::stoull;

class Solution_Compare_Version_Numbers {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0; 
        while (i < version1.size() && j < version2.size()) {
            int dot1 = version1.find_first_of('.', i);
            int dot2 = version2.find_first_of('.', j);
            string sub1, sub2;
            if (dot1 == -1) {
                sub1 = version1.substr(i);
            } else {
                sub1 = version1.substr(i, dot1 - i);
            }
            if (dot2 == -1) {
                sub2 = version2.substr(j);
            } else {
                sub2 = version2.substr(j, dot2 - j);
            }
            // printf("sub1 = %s, sub2 = %s\n", sub1.c_str(), sub2.c_str());
            unsigned long long int num1 = stoull(sub1);
            unsigned long long int num2 = stoull(sub2);
            if (num1 < num2) {
                return -1;
            } else if (num1 > num2) {
                return 1;
            }

            if (dot1 == -1 || dot2 == -1) {
                if (dot1 == -1) {
                    i = version1.size() + 1;
                    if (dot2 != -1) {
                        j = dot2 + 1;
                    }
                }
                if (dot2 == -1) {
                    j = version2.size() + 1;
                    if (dot1 != -1) {
                        i = dot1 + 1;
                    }
                }
                break;
            } else {
                i = dot1 + 1;
                j = dot2 + 1;
            }
        }

        if (i > version1.size() && j > version2.size()) {
            return 0;
        } else if (i < version1.size()) {
            while (i < version1.size()) {
                int dot1 = version1.find_first_of('.', i);
                string sub1;
                if (dot1 == -1) {
                    sub1 = version1.substr(i);
                } else {
                    sub1 = version1.substr(i, dot1 - i);
                }
                unsigned long long int num1 = stoull(sub1);
                if (num1 > 0) {
                    return 1;
                }
                if (dot1 == -1) {
                    return 0;
                } else {
                    i = dot1 + 1;
                }
            }  // while
        } else {
            while (j < version2.size()) {
                int dot2 = version2.find_first_of('.', j);
                string sub2;
                if (dot2 == -1) {
                    sub2 = version2.substr(j);
                } else {
                    sub2 = version2.substr(j, dot2 - j);
                }
                unsigned long long int num2 = stoull(sub2);
                if (num2 > 0) {
                    return -1;
                }
                if (dot2 == -1) {
                    return 0;
                } else {
                    j = dot2 + 1;
                }
            }  // while
        }  // else

    }
};

int main(int argc, char *argv[]) {
    Solution_Compare_Version_Numbers solution;
    string version1 = "0.1.23.34";
    string version2 = "0.1.23.45";
    printf("version1 = %s, version2 = %s\n",
            version1.c_str(), version2.c_str());
    int i = solution.compareVersion(version1, version2);
    printf("compare result = %d\n", i);


    version1 = "0.10.23.34";
    version2 = "0.1.23.45";
    printf("version1 = %s, version2 = %s\n",
            version1.c_str(), version2.c_str());
    i = solution.compareVersion(version1, version2);
    printf("compare result = %d\n", i);

    version1 = "1.0";
    version2 = "1";
    printf("version1 = %s, version2 = %s\n",
            version1.c_str(), version2.c_str());
    i = solution.compareVersion(version1, version2);
    printf("compare result = %d\n", i);

    version1 = "1";
    version2 = "1.1";
    printf("version1 = %s, version2 = %s\n",
            version1.c_str(), version2.c_str());
    i = solution.compareVersion(version1, version2);
    printf("compare result = %d\n", i);

    return 0;
}

