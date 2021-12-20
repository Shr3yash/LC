class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++) {
            int TestElement = nums[i], NumToFind = target - TestElement;
            if (seen.count(NumToFind)) return {seen[NumToFind], i};
            else
                seen[TestElement] = i;
        }
        return {};
    }
};
