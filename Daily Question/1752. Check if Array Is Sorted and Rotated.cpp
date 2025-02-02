class Solution {
public:
    bool check(vector<int>& nums) {
        bool encountered = false;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            int prev = nums[i-1];
            int curr = nums[i];
            if (prev > curr) {
                if (encountered) {
                    return false;
                }
                encountered = true;
            }
        }
        if (encountered) {
            return nums.back() <= nums[0];
        }
        return true;
        // bool encounter = false;
        // int curr, prev, globalMax, localMax = 0;;
        // for(int i = 0; i<nums.size(); ++i){
        //     if(i > 0) prev = nums[i-1];
        //     curr = nums[i];

        //     if(prev > cur && encounter == false) {
        //         encounter = true;
        //         localMax = prev;
        //     }else if(prev > cur && encounter == true){
        //         return false;
        //     }else if(prev > cur && )
        // }
        // if(!encounter) return true;
        

    }
};