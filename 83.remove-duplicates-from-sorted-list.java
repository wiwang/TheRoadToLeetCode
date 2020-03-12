/*
 * @lc app=leetcode id=83 lang=java
 *
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (43.56%)
 * Likes:    1057
 * Dislikes: 90
 * Total Accepted:    395.5K
 * Total Submissions: 899.1K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->1->2
 * Output: 1->2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->2->3->3
 * Output: 1->2->3
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode previous = null;
        ListNode current = head;

        while (current != null) {
            if (previous!=null && previous.val==current.val) {
                previous.next = current.next;
            } else {
                previous = current;
            }
            current = current.next;
        }
        
        return head;
    }
}
// @lc code=end

