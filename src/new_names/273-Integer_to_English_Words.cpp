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
 * File: 273-Integer_to_English_Words.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/integer-to-english-words/
 * Convert a non-negative integer to its english words representation. Given input
 * is guaranteed to be less than 2^31 - 1.

 * For example,
 * 123 -> "One Hundred Twenty Three"
 * 12345 -> "Twelve Thousand Three Hundred Forty Five"
 * 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty
 * Seven"
 *
 * Date: 2015.09.21
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <map>
#include <string>

using std::map;
using std::pair;
using std::string;



class Solution_Integer_to_English_Words {
public:
    string numberToWords(int num) {
        // 2^31 = 2,147,483,648
        if (num == 0) {
            return string("Zero");
        }

        map<int, string> theGeMap;
        theGeMap.insert(pair<int, string>(1, "One"));
        theGeMap.insert(pair<int, string>(2, "Two"));
        theGeMap.insert(pair<int, string>(3, "Three"));
        theGeMap.insert(pair<int, string>(4, "Four"));
        theGeMap.insert(pair<int, string>(5, "Five"));
        theGeMap.insert(pair<int, string>(6, "Six"));
        theGeMap.insert(pair<int, string>(7, "Seven"));
        theGeMap.insert(pair<int, string>(8, "Eight"));
        theGeMap.insert(pair<int, string>(9, "Nine"));
        theGeMap.insert(pair<int, string>(10, "Ten"));
        theGeMap.insert(pair<int, string>(11, "Eleven"));
        theGeMap.insert(pair<int, string>(12, "Twelve"));
        theGeMap.insert(pair<int, string>(13, "Thirteen"));
        theGeMap.insert(pair<int, string>(14, "Fourteen"));
        theGeMap.insert(pair<int, string>(15, "Fifteen"));
        theGeMap.insert(pair<int, string>(16, "Sixteen"));
        theGeMap.insert(pair<int, string>(17, "Seventeen"));
        theGeMap.insert(pair<int, string>(18, "Eighteen"));
        theGeMap.insert(pair<int, string>(19, "Nineteen"));
        map<int, string> theShiMap;
        theShiMap.insert(pair<int, string>(20, "Twenty"));
        theShiMap.insert(pair<int, string>(30, "Thirty"));
        theShiMap.insert(pair<int, string>(40, "Forty"));
        theShiMap.insert(pair<int, string>(50, "Fifty"));
        theShiMap.insert(pair<int, string>(60, "Sixty"));
        theShiMap.insert(pair<int, string>(70, "Seventy"));
        theShiMap.insert(pair<int, string>(80, "Eighty"));
        theShiMap.insert(pair<int, string>(90, "Ninety"));

        map<int, string> theQianMap;
        theQianMap.insert(pair<int, string>(1, "Thousand"));
        theQianMap.insert(pair<int, string>(2, "Million"));
        theQianMap.insert(pair<int, string>(3, "Billion"));

        string result;
        int stage = 0;
        bool prelogue = false;
        while (num > 0) {
            prelogue = false;
            string tempString;
            int reminder = num % 1000;

            map<int, string>::iterator iter;
            if (reminder / 100 > 0) {
                iter = theGeMap.find(reminder / 100);
                tempString += iter->second + " " + "Hundred";
                reminder = reminder % 100;
                prelogue = true;
            }
            if (reminder / 10 > 0) {
                if (reminder / 10 > 1) {
                    iter = theShiMap.find(reminder / 10 * 10);
                    if (prelogue) {
                        tempString += " " + iter->second;
                    } else {
                        tempString += iter->second;
                        prelogue = true;
                    }

                    reminder = reminder % 10;
                    if (reminder > 0) {
                        iter = theGeMap.find(reminder);
                        tempString += " " + iter->second;
                    }
                } else {
                    iter = theGeMap.find(reminder);
                    if (prelogue) {
                        tempString += " " + iter->second;
                    } else {
                        tempString += iter->second;
                        prelogue = true;
                    }
                }
            } else {
                if (reminder > 0) {
                    iter = theGeMap.find(reminder);
                    if (prelogue) {
                        tempString += " " + iter->second;
                    } else {
                        tempString += iter->second;
                        prelogue = true;
                    }
                }
            }

            if (prelogue) {
                if (stage > 0) {
                    iter = theQianMap.find(stage);
                    tempString += " " + iter->second;
                }
                if (result.size() > 0) {
                    result = tempString + " " + result;
                } else {
                    result = tempString;

                }
            }

            num = num / 1000;
            stage++;
        }  // while

        return result;
    }
};

void testcase() {
    Solution_Integer_to_English_Words solution;
    int num = 123;
    string result = solution.numberToWords(num);
    printf("num = %d, result = %s\n", num, result.c_str());

    num = 12345;
    result = solution.numberToWords(num);
    printf("num = %d, result = %s\n", num, result.c_str());

    num = 1234567;
    result = solution.numberToWords(num);
    printf("num = %d, result = %s\n", num, result.c_str());

    num = 111234567;
    result = solution.numberToWords(num);
    printf("num = %d, result = %s\n", num, result.c_str());

    num = 101030507;
    result = solution.numberToWords(num);
    printf("num = %d, result = %s\n", num, result.c_str());
}

int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

