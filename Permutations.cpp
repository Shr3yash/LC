class Solution {
public:
    void perm(int flg[],  vector<int>& ds, vector<vector<int>>& ans, vector<int>& nums){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i =0; i<nums.size(); i++){
            if(!flg[i]){
                ds.push_back(nums[i]);
                flg[i]=1;
                perm(flg, ds, ans, nums);
                ds.pop_back();
                flg[i]=0;
            }
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int flg[nums.size()];
        for(int i=0;i<nums.size();i++){
            
            flg[i]=0;
            }
        
        perm(flg, ds, ans, nums);
        return ans;
    }
};
