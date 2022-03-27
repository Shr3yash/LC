class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size=nums.size(), pivot, swapper;
        for(pivot=size-2; pivot>=0 ;pivot--){
            if(nums[pivot]<nums[pivot+1]){
                break;
            }
        }
        if(pivot<0){
            reverse(nums.begin(), nums.end());
        }else{
            for(swapper=z=size-1; swapper>pivot; swapper--){
                if(nums[swapper]>nums[pivot])
                {
                    break;
                }
            }
        swap(nums[pivot], nums[swapper]);
        reverse(nums.begin()+pivot+1, nums.end());
        }

    }
};
