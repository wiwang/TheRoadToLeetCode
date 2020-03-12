/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (37.19%)
 * Likes:    901
 * Dislikes: 91
 * Total Accepted:    58.8K
 * Total Submissions: 157.2K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for
 * each cell.
 * 
 * The distance between two adjacent cells is 1.
 * 
 * 
 * 
 * Example 1: 
 * 
 * 
 * Input:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[0,0,0]]
 * 
 * Output:
 * [[0,0,0],
 * [0,1,0],
 * [0,0,0]]
 * 
 * 
 * Example 2: 
 * 
 * 
 * Input:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[1,1,1]]
 * 
 * Output:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[1,2,1]]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of elements of the given matrix will not exceed 10,000.
 * There are at least one 0 in the given matrix.
 * The cells are adjacent in only four directions: up, down, left and right.
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<vector<int>> bfs;
        int dist = 0;
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0) bfs.push(vector<int>({i, j}));    // keep track of all 0's 
                else matrix[i][j] = INT_MAX;                            // else initialize distance to infinity 
            }
        }
        
        vector<vector<int>> directions({{1,0}, {-1, 0}, {0, 1}, {0, -1}});
        
        while(!bfs.empty()){
            vector<int> current = bfs.front(); bfs.pop();
            
            for(auto d : directions){
                int i = current[0] + d[0];
                int j = current[1] + d[1];
                
                // if new cell is out of bounds or is already closer to another 0, stop further bfs in this cell  
                if(i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] <= matrix[current[0]][current[1]] + 1) continue;
              
                bfs.push(vector<int>({i, j}));                     // put in queue for further bfs operations
                matrix[i][j] = matrix[current[0]][current[1]] + 1; // update new smaller distance
            }
        }
        
        return matrix;
    }
};
// @lc code=end

