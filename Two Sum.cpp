class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> prev;
        for (int i = 0; i < nums.size(); i++) {
            int p = nums[i], q = target - p;
            if (prev.count(q)) return {prev[q], i};
            seen[p] = i;
        }
        return {};
    }
};
        
