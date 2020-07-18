/*
Problem Statement #
Given a list of intervals, merge all the overlapping intervals to produce a list that has only mutually exclusive intervals.

Example 1:

Intervals: [[1,4], [2,5], [7,9]]
Output: [[1,5], [7,9]]
Explanation: Since the first two intervals [1,4] and [2,5] overlap, we merged them into
one [1,5].
svg viewer
Example 2:

Intervals: [[6,7], [2,4], [5,9]]
Output: [[2,4], [5,9]]
Explanation: Since the intervals [6,7] and [5,9] overlap, we merged them into one [5,9].

Example 3:

Intervals: [[1,4], [2,6], [3,5]]
Output: [[1,6]]
Explanation: Since all the given intervals overlap, we merged them into one.
*/

using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class MergeIntervals {
 public:
  static vector<Interval> merge(vector<Interval> &intervals) {
    if (intervals.size() < 2) {
      return intervals;
    }

    // sort the intervals by start time
    sort(intervals.begin(), intervals.end(),
         [](const Interval &x, const Interval &y) { return x.start < y.start; });

    vector<Interval> mergedIntervals;

    vector<Interval>::const_iterator intervalItr = intervals.begin();
    Interval interval = *intervalItr++;
    int start = interval.start;
    int end = interval.end;
    while (intervalItr != intervals.end()) {
      interval = *intervalItr++;
      if (interval.start <= end) {  // overlapping intervals, adjust the 'end'
        end = max(interval.end, end);
      } else {  // non-overlapping interval, add the previous interval and reset
        mergedIntervals.push_back({start, end});
        start = interval.start;
        end = interval.end;
      }
    }
    // add the last interval
    mergedIntervals.push_back({start, end});
    return mergedIntervals;
  }
};

int main(int argc, char *argv[]) {
  vector<Interval> input = {{1, 3}, {2, 5}, {7, 9}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{6, 7}, {2, 4}, {5, 9}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{1, 4}, {2, 6}, {3, 5}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
}
