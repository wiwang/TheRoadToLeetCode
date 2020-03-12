/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (36.94%)
 * Likes:    2690
 * Dislikes: 211
 * Total Accepted:    431.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool intervalsComparator(vector<int> v1, vector<int> v2) {
        return (v1.front() < v2.front());
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        if (intervals.size() < 1)
        {
            return res;
        }
        
        sort(intervals.begin(), intervals.end(), intervalsComparator);


        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            if (res.back().back() < intervals[i].front())
            {
                res.push_back(intervals[i]);
            }
            else
            {
                res.back().back() = max(res.back().back(), intervals[i].back());
            }
            
        }
        
        return res;
    }
};
// @lc code=end

