/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (43.26%)
 * Likes:    3382
 * Dislikes: 124
 * Total Accepted:    457.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */

// @lc code=start
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0; // number of groups 
      
        // iterating through given grid to find a '1'
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    ans++; // start a group and visit all members of this group using dfs
                    dfs(grid, i, j);
                }
            }
        }
        
        return ans;
    }
    
    void dfs(vector<vector<char>>& grid, int y, int x){
        // if out of bounds or at a cell with '0' or '*', simply stop and return | end the dfs
        if(x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size() || grid[y][x] != '1') return;
        
        grid[y][x] = '*'; // destroying visited cells so they are not re-visited
        
        // recursive dfs on all neighbours
        dfs(grid, y + 1, x);
        dfs(grid, y - 1, x);
        dfs(grid, y, x + 1);
        dfs(grid, y, x - 1);
    }
};
// @lc code=end

