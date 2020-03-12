/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (51.29%)
 * Likes:    2563
 * Dislikes: 78
 * Total Accepted:    409.7K
 * Total Submissions: 798.5K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> combinations;
    vector<int> tmpset;

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        explore(candidates, 0, target);

        return combinations;
    }

    void explore(vector<int>& candidates, int start, int target) {
        if (target == 0) {
            combinations.push_back(tmpset); // yes! a valid solution found
            return;
        } 

        if(target < 0) { // this is when we lose hope and backtrack :(
            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            // explore all solutions using candidates[i] at least once
            tmpset.push_back(candidates[i]);

            explore(candidates, i, target-candidates[i]); //here we don't increase i by one, because we tend to use each elements from 0 to any times

            tmpset.pop_back();
        }
        
    }
};
// @lc code=end

