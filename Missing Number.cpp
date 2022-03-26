class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xoro =nums.size();
        for(int i=0; i<nums.size(); i++){
            xoro ^= i;
            xoro ^= nums[i];
        }
        return xoro;
    }
};
