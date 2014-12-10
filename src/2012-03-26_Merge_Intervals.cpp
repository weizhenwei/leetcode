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
 * File: 2012-03-26_Merge_Intervals.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/merge-intervals/
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 *
 *
 * Date: 2014.12.10
 *
 * Author: weizhenwei <weizhenwei1988@gmail.com>
 *
 * *****************************************************************************
 */

#include <stdio.h>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

// Definiiton for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}

    bool operator < (const struct Interval &interval) const {
        return start < interval.start;
    }
};

class Solution_Merge_Intervals {
public:
    static bool comp(const struct Interval &a, const struct Interval &b) {
        return a.start < b.start;
    }

    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end(), comp);

        vector<Interval> results;
        int start = 0;
        int len = intervals.size();
        while (start < len) {
            int end = start;
            int last = intervals[start].end;
            while (end < len - 1
                    && last >= intervals[end+1].start) {
                end++;
                if (last < intervals[end].end) {
                    last = intervals[end].end;
                }
            }
            
            Interval elem = Interval(intervals[start].start, last);
            results.push_back(elem);
            
            start = end + 1;
        }  // while

        return results;
    }
};

static void print_intervals(vector<Interval> &intervals) {
    for (int i = 0; i < intervals.size(); i++) {
        printf("[%d, %d]\n", intervals[i].start, intervals[i].end);
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    Solution_Merge_Intervals solution;
    vector<Interval> intervals;
    intervals.push_back(Interval(1, 3));
    intervals.push_back(Interval(2, 6));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(15, 18));

    print_intervals(intervals);
    vector<Interval> results = solution.merge(intervals);
    print_intervals(results);

    intervals.clear();
    intervals.push_back(Interval(1, 33));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(2, 6));
    intervals.push_back(Interval(15, 18));
    print_intervals(intervals);
    results = solution.merge(intervals);
    print_intervals(results);

    intervals.clear();
    intervals.push_back(Interval(1, 3));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(2, 14));
    intervals.push_back(Interval(15, 18));
    print_intervals(intervals);
    results = solution.merge(intervals);
    print_intervals(results);

    return 0;
}

