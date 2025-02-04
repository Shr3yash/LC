class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int globalMax = nums[0], localMax = nums[0];

        for(int i = 1; i<nums.size(); ++i){
            if(nums[i - 1] < nums[i]){
                localMax+=nums[i];
            }else if(nums[i-1]>=nums[i]){
                localMax = nums[i];
            }
            globalMax = max(globalMax, localMax);
        }
        return globalMax;
    }
};