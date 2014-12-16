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
 * File: 2012-04-03_Simplify_Path.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/simplify-path/
 * Given an absolute path for a file (Unix-style), simplify it.
 *
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 *
 * Corner Cases:
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together,
 * such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 *
 *
 * Date: 2014.12.16
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <assert.h>
#include <stdio.h>
#include <stack>
#include <string>
#include <vector>

using std::stack;
using std::string;
using std::vector;

class Solution_Simplify_Path {
public:
    string simplifyPath(string path) {
        if (path.size() <= 0) {
            return string("");
        }
        assert(path[0] == '/');

        stack<string> stack;
        int current = 1;  // the root '/' is ignored;
        while (current < path.size()) {
            int slash_pos = path.find_first_of('/', current);
            int len = 0;
            string elem;
            if (slash_pos == -1) {  // no '/' any more;
                len = path.size() - current;
                elem = path.substr(current, len);
            } else {
                len = slash_pos - current;
                if (len == 0) {
                    current = slash_pos + 1;
                    continue;
                } else {
                    elem = path.substr(current, len);
                    current = slash_pos + 1;
                }
            }  // else

            if (elem == ".") {  // continue;
                if (slash_pos == -1) {
                    break;
                } else {
                    continue;
                }
            } else if (elem == "..") {
                if (!stack.empty()) {  // stack may be empty, judge first;
                    stack.pop();
                }
            } else {
                stack.push(elem);
            }

            if (slash_pos == -1) {
                break;
            }
        }  // while


        string result = string("");
        while (!stack.empty()) {
            string elem = "/" + stack.top();
            result = elem + result;
            stack.pop();
        }
        if (result.size() == 0) {
            result = "/";
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution_Simplify_Path solution;
    string path = string("/home/wzw/abc/../dirty");
    printf("original path:%s\n", path.c_str());
    string simplifypath = solution.simplifyPath(path);
    printf("simplifyPath:%s\n", simplifypath.c_str());

    path = string("/.");
    printf("original path:%s\n", path.c_str());
    simplifypath = solution.simplifyPath(path);
    printf("simplifyPath:%s\n", simplifypath.c_str());

    path = string("/home/wzw/abc/../dirty/");
    printf("original path:%s\n", path.c_str());
    simplifypath = solution.simplifyPath(path);
    printf("simplifyPath:%s\n", simplifypath.c_str());

    path = string("/home/wzw/abc//../dirty//");
    printf("original path:%s\n", path.c_str());
    simplifypath = solution.simplifyPath(path);
    printf("simplifyPath:%s\n", simplifypath.c_str());

    path = string("/home/../../.././dirty//");
    printf("original path:%s\n", path.c_str());
    simplifypath = solution.simplifyPath(path);
    printf("simplifyPath:%s\n", simplifypath.c_str());

    path = string("//../../.././//");
    printf("original path:%s\n", path.c_str());
    simplifypath = solution.simplifyPath(path);
    printf("simplifyPath:%s\n", simplifypath.c_str());

    return 0;
}

