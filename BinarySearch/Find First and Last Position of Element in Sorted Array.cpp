//TLE
//TC=nlogn
class Solution {
public:
    void fnl(vector<int>& ans, vector<int> nums, int target, int start, int end){
        int mid = start + (end-start)/2;
        while(start<=end){
            if(target==nums[mid]){
                ans.push_back(mid);
                if(nums[mid]==nums[mid+1])
                    ans.push_back(mid+1);
                ans.push_back(mid-1);
            }
            if(target<nums[mid]){
                fnl(ans, nums, target, start, mid-1);
            }
            if(target>nums[mid]){
                fnl(ans, nums, target, mid+1, end);
            }
           
        }
        ans.assign(2,-1);
        return;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int x=nums.size()-1;
        fnl(ans, nums, target, 0, x);
        return ans; 
    }
};
