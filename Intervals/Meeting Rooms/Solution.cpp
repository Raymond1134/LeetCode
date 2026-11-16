/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
            return a.start < b.start ? true : false;
        });

        int currentLatestEndTime = 0;

        for (Interval i : intervals) {
            if (i.start < currentLatestEndTime) return false;
            currentLatestEndTime = max(currentLatestEndTime, i.end);
        }

        return true;
    }
};
