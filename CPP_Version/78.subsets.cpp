/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (55.72%)
 * Likes:    2460
 * Dislikes: 59
 * Total Accepted:    431.3K
 * Total Submissions: 773.4K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
    private:
    vector<vector<int>> powerset;
    vector<int> tmpset;

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrace(nums, 0);
        return powerset;
    }

    void backtrace(vector<int>& nums, int start) {
        powerset.push_back(tmpset);

        for (int i = start; i < nums.size(); i++)
        {
            tmpset.push_back(nums[i]);
            backtrace(nums, i+1);
            tmpset.pop_back();
        }
    }
};
// @lc code=end



/**
 * need to absorb this, basically it is to find all leaf nodes.
 * 
 * class Solution {
private:
    vector<vector<int>> powerset;
    vector<int> subset;
public:
    vector<vector<int>> subsets(vector<int>& nums) {        
        backtrack(nums, 0);
        return powerset;
    }

    void backtrack(vector<int>& nums, int start){
        if(start == nums.size()) powerset.push_back(subset);
        else{
            subset.push_back(nums[start]);
            backtrack(nums, start+1);

            subset.pop_back();
            backtrack(nums, start+1);
        }
    }
};
*/
