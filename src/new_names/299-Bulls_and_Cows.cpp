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
 * File: 299-Bulls_and_Cows.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/bulls-and-cows/
 * you are playing the following Bulls and Cows game with your friend: You write
 * a 4-digit secret number and ask your friend to guess it. Each time your friend
 * guesses a number, you give a hint. The hint tells your friend how many digits
 * are in the correct positions (called "bulls") and how many digits are in the
 * wrong positions (called "cows"). Your friend will use those hints to find out
 * the secret number.

 * For example:

 * Secret number:  "1807"
 * Friend's guess: "7810"
 * Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
 * Write a function to return a hint according to the secret number and friend's
 * guess, use A to indicate the bulls and B to indicate the cows. In the above
 * example, your function should return "1A3B".

 * Please note that both secret number and friend's guess may contain duplicate
 * digits, for example:

 * Secret number:  "1123"
 * Friend's guess: "0111"
 * In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow,
 * and your function should return "1A1B".
 * You may assume that the secret number and your friend's guess only contain
 * digits, and their lengths are always equal.
 *
 * Date: 2015.11.06
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <string>
#include <sstream>
#include <map>

using std::string;
using std::map;
using std::pair;
using std::stringstream;

class Solution_Bulls_and_Cows {
public:
    string getHint(string secret, string guess) {
        if (secret.size() != guess.size() || secret.size() == 0)
            return "0A0B";

        int bulls = 0;
        map<char, int> mapSecret, mapGuess;
        map<char, int>::iterator iterSecret, iterGuess;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                iterSecret = mapSecret.find(secret[i]);
                if (iterSecret != mapSecret.end()) {
                    iterSecret->second += 1;
                } else {
                    pair<char, int> p(secret[i], 1);
                    mapSecret.insert(p);
                }

                iterGuess = mapGuess.find(guess[i]);
                if (iterGuess != mapGuess.end()) {
                    iterGuess->second += 1;
                } else {
                    pair<char, int> p(guess[i], 1);
                    mapGuess.insert(p);
                }
            }
        }  // for;


        int cows = 0;
        for (iterSecret = mapSecret.begin(); iterSecret != mapSecret.end();
                iterSecret++) {
            char key = iterSecret->first;
            int num1 = iterSecret->second;
            if ((iterGuess = mapGuess.find(key)) != mapGuess.end()) {
                int num2 = iterGuess->second;
                if (num1 >= num2) {
                    cows += num2;
                } else {
                    cows += num1;
                }
            }
        }  // for;


        stringstream ostring;
        ostring << bulls << "A" << cows << "B";
        string result = ostring.str();

        return result;
    }
};

void testcase() {
    Solution_Bulls_and_Cows solution;
    string sSecret = "1807";
    string sGuess = "7810";
    string sHint = solution.getHint(sSecret, sGuess);
    printf("secret = %s, guess = %s, hit = %s\n",
            sSecret.c_str(), sGuess.c_str(), sHint.c_str());

    sSecret = "1123";
    sGuess = "0111";
    sHint = solution.getHint(sSecret, sGuess);
    printf("secret = %s, guess = %s, hit = %s\n",
            sSecret.c_str(), sGuess.c_str(), sHint.c_str());
} 

int main(int argc, char *argv[]) {
    testcase();

    return 0;
}

