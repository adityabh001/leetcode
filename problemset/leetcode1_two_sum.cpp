/*
https://leetcode.com/problems/two-sum/

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 
Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,vector<int>> hm;
        
        for(int i=0;i<nums.size();i++)
        {
            hm[nums[i]].push_back(i);
        }
        
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++)
        {
            if(hm.find(target-nums[i])!=hm.end())
            {
                if(target-nums[i]==nums[i] && hm[nums[i]].size()>1)
                {
                    ans.push_back(hm[nums[i]].front());
                    ans.push_back(hm[nums[i]].back());
                    break;
                }
                else if(target-nums[i]==nums[i] && hm[nums[i]].size()==1)
                    continue;
                else
                {
                    ans.push_back(hm[nums[i]].front());
                    ans.push_back(hm[target-nums[i]].front());
                    break;
                }
                
            }
        }
        return ans;
        
    }
};

// Time complexity = O(n)
// Space complexity = o(n)