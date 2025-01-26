class Solution {
public:
    void nodup(int index, int size, vector<vector<int>>& ans, vector<int>& ds, vector<int> nums) {
        ans.push_back(ds);
        for(int i=index; i<size; i++) //traverse over whole array
        {
            if(i!=index && nums[i]==nums[i-1]) continue; //skips if next index element is same as prev one when we popped and went to find another number at  
                                                         //SAME LEVEL in our ds. 
            
                ds.push_back(nums[i]);
                nodup(i+1, size, ans, ds, nums);
                ds.pop_back();
            
        }
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int size=nums.size();
        nodup(0, size, ans, ds, nums);
        return ans;
    }
};
