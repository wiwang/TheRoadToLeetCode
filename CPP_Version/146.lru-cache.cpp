/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (27.88%)
 * Likes:    3826
 * Dislikes: 156
 * Total Accepted:    373K
 * Total Submissions: 1.3M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * The cache is initialized with a positive capacity.
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 */


#include <list>
#include <unordered_map>

using namespace std;

// @lc code=start
class LRUCache {
private:
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (m.find(key) == m.end())
        {
            return -1;
        }
        else
        {
            return m[key]->second;
        }
        
    }
    
    void put(int key, int value) {
        if (m.find(key) == m.end())
        {
            if (lru.size() == capacity)
            {
                pair<int, int> least = lru.back();
                lru.pop_back();
                m.erase(least.first);
            }
        }
        else
        {
            lru.erase(m[key]);
        }

        lru.push_front(make_pair(key, value));
        m[key] = lru.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

