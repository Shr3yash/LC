class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n=nums.size(), local=0, global=0;
        for(int i = 0; i<n-1; i++){
            if(nums[i] > nums[i + 1])local++;
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i]>nums[j])global++;
            }
        }
        if(local==global)return true;
        return false;
    }
};
