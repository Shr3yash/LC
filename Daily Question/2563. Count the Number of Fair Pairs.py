class Solution:
    def lower_bound(self, nums, starti, endi, limit):
        while starti <= endi:
            mid = (starti + endi) // 2
            if nums[mid] >= limit:
                endi = mid - 1
            else:
                starti = mid + 1
        return starti

    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        ans = 0
        for i in range(len(nums)):
            low = self.lower_bound(nums, i + 1, len(nums) - 1, lower - nums[i])
            high = self.lower_bound(nums, i + 1, len(nums) - 1, upper - nums[i] + 1)
            ans += high - low
        return ans
