class Solution {
public:
    int solve(vector<int>& nums,  int ind, bool flag){
        int cnt=0;
        for(int i=ind+1; i<nums.size();++i){ //from each ind we check for possible values ahead of time in nums
            if((flag&&nums[i]>nums[ind])||(!flag&&nums[i]<nums[ind]))
                cnt=max(cnt, 1+solve(nums, i, !flag));
        }
        return cnt;
    }
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        return 1+max(solve(nums,0,true), solve(nums,0,false));
        //find for positive or negative diff'd values
    }
};
