/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (31.94%)
 * Likes:    1082
 * Dislikes: 135
 * Total Accepted:    202.6K
 * Total Submissions: 632.9K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their
 * start times.
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        int num = 0;

        while (num<intervals.size() && intervals[num].back()<newInterval.front())
        {
            ans.push_back(intervals[num++]);
        }

        while (num<intervals.size() && intervals[num].front()<=newInterval.back())
        {
            newInterval.front() = min(newInterval.front(), intervals[num].front());
            newInterval.back() = max(newInterval.back(), intervals[num].back());
            num++;
        }

        ans.push_back(newInterval);
        
        while (num < intervals.size())
        {
            ans.push_back(intervals[num++]);
        }
        
        return ans;
    }
};
// @lc code=end

