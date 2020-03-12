/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 *
 * https://leetcode.com/problems/non-overlapping-intervals/description/
 *
 * algorithms
 * Medium (41.83%)
 * Likes:    626
 * Dislikes: 26
 * Total Accepted:    49.3K
 * Total Submissions: 117.8K
 * Testcase Example:  '[[1,2]]'
 *
 * Given a collection of intervals, find the minimum number of intervals you
 * need to remove to make the rest of the intervals non-overlapping.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,2],[2,3],[3,4],[1,3]]
 * Output: 1
 * Explanation: [1,3] can be removed and the rest of intervals are
 * non-overlapping.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,2],[1,2],[1,2]]
 * Output: 2
 * Explanation: You need to remove two [1,2] to make the rest of intervals
 * non-overlapping.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [[1,2],[2,3]]
 * Output: 0
 * Explanation: You don't need to remove any of the intervals since they're
 * already non-overlapping.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * You may assume the interval's end point is always bigger than its start
 * point.
 * Intervals like [1,2] and [2,3] have borders "touching" but they don't
 * overlap each other.
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool intervalsComparator(vector<int> v1, vector<int> v2) {
        return (v1.back() < v2.back());
    }    
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int num = 0;
        int lastEnd;

        if (intervals.size()==0)
        {
            return 0;
        }
        
        sort(intervals.begin(), intervals.end(), intervalsComparator);

        lastEnd = intervals[0].back();
        num = 1;

        for (int i = 1; i < intervals.size(); i++)
        {
            if (lastEnd <= intervals[i].front())
            {
                lastEnd = intervals[i].back();
                num++;
            }
        }
        
        return intervals.size() - num;        
    }
};
// @lc code=end

