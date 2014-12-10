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
 * File: 2012-03-27_Insert_Interval.cpp
 *
 *
 * Brief: https://oj.leetcode.com/problems/insert-interval/
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their
 * start times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as
 * [1,2],[3,10],[12,16].
 *
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
};

class Solution_Merge_Intervals {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> results;
        if (intervals.size() == 0) {
            results.push_back(newInterval);
            return results;
        }

        int left = newInterval.start;
        int right = newInterval.end;

        int start = 0;
        int minStart = 0;
        while (start < intervals.size()) {
            if (left < intervals[start].start) {
                if (right < intervals[start].start) {  // left < right < start < end;
                    results.push_back(Interval(left, right));
                    for (start; start < intervals.size(); start++) {
                        results.push_back(intervals[start]);
                    }
                    return results;
                } else {  // left < start < right < end;
                    minStart = left;
                    break;
                }
            } else {
                if (left > intervals[start].end) {  // right > left > end > start
                    results.push_back(intervals[start]);
                    start++;
                    if (start == intervals.size()) {
                        minStart = left;
                    }
                } else {  // start <= left <= end;
                    minStart = intervals[start].start;
                    break;
                }
            }
        }  // while start;

        int end = start;
        int maxEnd = 0;
        while (end < intervals.size()) {
            if (intervals[end].end < right) {
                end++;
            } else {
                if (intervals[end].start > right) {
                    maxEnd = right;
                    end--;
                } else {
                    maxEnd = intervals[end].end;
                }
                break;
            }
        }  // while end;

        if (end == intervals.size()) {
            maxEnd = right;
        }
        results.push_back(Interval(minStart, maxEnd));

        end++;
        while (end < intervals.size()) {
            results.push_back(intervals[end]);
            end++;
        }

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
    intervals.push_back(Interval(4, 6));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(15, 18));

    Interval newInterval = Interval(2, 9);
    print_intervals(intervals);
    printf("interval to be insert:[%d, %d]\n",
            newInterval.start, newInterval.end);
    vector<Interval> results = solution.insert(intervals, newInterval);
    print_intervals(results);
    printf("\n");


    intervals.clear();
    intervals.push_back(Interval(1, 5));
    print_intervals(intervals);

    newInterval = Interval(6, 8);
    printf("interval to be insert:[%d, %d]\n",
            newInterval.start, newInterval.end);
    results = solution.insert(intervals, newInterval);
    print_intervals(results);
    printf("\n");


    intervals.clear();
    intervals.push_back(Interval(0, 4));
    intervals.push_back(Interval(7, 15));
    print_intervals(intervals);

    newInterval = Interval(0, 5);
    printf("interval to be insert:[%d, %d]\n",
            newInterval.start, newInterval.end);
    results = solution.insert(intervals, newInterval);
    print_intervals(results);
    printf("\n");


    intervals.clear();
    intervals.push_back(Interval(4, 6));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(15, 18));
    print_intervals(intervals);

    newInterval = Interval(1, 3);
    printf("interval to be insert:[%d, %d]\n",
            newInterval.start, newInterval.end);
    results = solution.insert(intervals, newInterval);
    print_intervals(results);


    intervals.clear();
    intervals.push_back(Interval(1, 2));
    intervals.push_back(Interval(3, 4));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(15, 18));
    print_intervals(intervals);

    newInterval = Interval(2, 3);
    printf("interval to be insert:[%d, %d]\n",
            newInterval.start, newInterval.end);
    results = solution.insert(intervals, newInterval);
    print_intervals(results);


    intervals.clear();
    intervals.push_back(Interval(1, 2));
    intervals.push_back(Interval(3, 4));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(15, 18));
    print_intervals(intervals);

    newInterval = Interval(16, 17);
    printf("interval to be insert:[%d, %d]\n",
            newInterval.start, newInterval.end);
    results = solution.insert(intervals, newInterval);
    print_intervals(results);


    intervals.clear();
    intervals.push_back(Interval(1, 2));
    intervals.push_back(Interval(3, 4));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(15, 18));
    print_intervals(intervals);

    newInterval = Interval(16, 27);
    printf("interval to be insert:[%d, %d]\n",
            newInterval.start, newInterval.end);
    results = solution.insert(intervals, newInterval);
    print_intervals(results);

    return 0;
}

