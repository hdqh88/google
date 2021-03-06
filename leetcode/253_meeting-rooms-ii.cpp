//Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
//
//For example,
//Given [[0, 30],[5, 10],[15, 20]],
//return 2.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution_253 {
public:
    // heap     faster
    // Exp: https://discuss.leetcode.com/topic/20958/ac-java-solution-using-min-heap
    // Time:	O(n * log(n))
    // Space:	O(n)
    int minMeetingRooms(vector<Interval> &intervals) {
        if (intervals.size() <= 1) return intervals.size();
        sort(intervals.begin(), intervals.end(), cmp1);
        priority_queue<Interval, vector<Interval>, cmp2> min_heap;
        min_heap.push(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            auto interval = min_heap.top();
            min_heap.pop();
            if (intervals[i].start >= interval.end)
                interval.end = intervals[i].end;
            else
                min_heap.push(intervals[i]);
            min_heap.push(interval);
        }
        return min_heap.size();
    }

    static bool cmp1(Interval a, Interval b) {
        return a.start < b.start;
    }

    struct cmp2 {
        bool operator()(Interval a, Interval b) {
            return a.end > b.end;
        }
    };


    // array, better idea.
    // Exp: https://discuss.leetcode.com/topic/20971/c-o-n-log-n-584-ms-3-solutions
    // Time:	O(n * log(n))
    // Space:	O(n)
    int minMeetingRooms1(vector<Interval> &intervals) {
        vector<vector<int>> times;
        for (Interval interval : intervals) {
            times.push_back({interval.start, 1});
            times.push_back({interval.end, -1});
        }
        sort(times.begin(), times.end(), cmp3);
        int count = 0, result = 0;
        for (auto &ele : times) {
            count += ele[1];
            result = max(result, count);
        }
        return result;
    }

    static bool cmp3(vector<int> a, vector<int> b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
    }
};