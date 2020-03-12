/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (43.93%)
 * Likes:    1131
 * Dislikes: 51
 * Total Accepted:    258K
 * Total Submissions: 586.8K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
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
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
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
    vector<vector<int>> combinations;
    vector<int> tmpset;

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        explore(candidates, 0, target);

        return combinations;       
    }

    void explore(vector<int>& candidates, int start, int target) {
        if (target == 0) {
            combinations.push_back(tmpset);
            return;
        } 

        if(target < 0) {
            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            //skip this case due to the former case is the same case
            //which can lead to same subset
            if (i > start && candidates[i]==candidates[i-1]) continue;

            tmpset.push_back(candidates[i]);

            explore(candidates, i+1, target-candidates[i]);

            tmpset.pop_back();
        }
        
    }    
};
// @lc code=end

