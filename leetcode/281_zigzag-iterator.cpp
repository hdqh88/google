//Given two 1d vectors, implement an iterator to return their elements alternately.
//
//For example, given two 1d vectors:
//
//    v1 = [1, 2]
//    v2 = [3, 4, 5, 6]
//By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].
//
//Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?
//
//Clarification for the follow up question - Update (2015-09-18):
//The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example, given the following input:
//
//    [1,2,3]
//    [4,5,6,7]
//    [8,9]
//It should return [1,4,8,2,5,9,3,6,7].

#include <iostream>
#include <vector>

using namespace std;

// Exp: My Own
// Time:	O(1)
// Space:	O(1)
class ZigzagIterator {
    vector<vector<int>::iterator> iters, ends;
    int i;
public:
    ZigzagIterator(vector<int> &v1, vector<int> &v2) {
        iters = {v1.begin(), v2.begin()};
        ends = {v1.end(), v2.end()};
        i = 0;
    }

    int next() {
        int val = *iters[i]++;
        i = (i + 1) % iters.size();
        return val;
    }

    bool hasNext() {
        int end_count = 0;
        while (end_count < iters.size()) {
            if (iters[i] != ends[i]) return true;
            i = (i + 1) % iters.size();
            end_count++;
        }
        return false;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */