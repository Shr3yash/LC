class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int globalMax = 1, localMaxInc = 1, localMaxDec = 1;
        for(int i = 0; i<nums.size()-1; ++i){
            //to check if strictly increasing
            if(nums[i]<nums[i+1]){
                localMaxInc++;
            }else if(nums[i]>=nums[i+1])localMaxInc = 1;

            //to check if strictly decreasing
            if(nums[i]>nums[i+1]){
                localMaxDec++;
            }else if(nums[i]<=nums[i+1]) localMaxDec = 1;

            globalMax = max(localMaxDec, globalMax);
            globalMax = max(localMaxInc, globalMax);
        }
        return globalMax;
    }
};