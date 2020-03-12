#include <unordered_map>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++)
        {
            int rest = target - nums[i];
            if (umap.find(rest) == umap.end())
            {
                umap.insert(make_pair(nums[i], i));
            }
            else
            {
                return vector<int>({i, umap[rest]});
            }    
        }

        throw("don't get the solution");   
    }
};
// @lc code=end

