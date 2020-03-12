/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (44.03%)
 * Likes:    1122
 * Dislikes: 54
 * Total Accepted:    229.3K
 * Total Submissions: 520.7K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> powerset;
    vector<int> tmpset;

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        backtrace(nums, 0);
        return powerset;
    }

    void backtrace(vector<int>& nums, int start) {
        powerset.push_back(tmpset);

        for (int i = start; i < nums.size(); i++)
        {
            if (i>start && nums[i]==nums[i-1]) continue;//skip the same elements            
            tmpset.push_back(nums[i]);

            backtrace(nums, i+1);
            
            tmpset.pop_back();
        }
        
    }
};
// @lc code=end

