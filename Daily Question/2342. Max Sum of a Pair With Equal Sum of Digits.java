import java.util.HashMap;

class Solution {
    public int maximumSum(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int maxSum = -1;
        for (int i = 0; i < nums.length; ++i) {
            int key = summer(nums[i]);
            if (map.containsKey(key)) {
                maxSum = Math.max(nums[i] + map.get(key), maxSum);
            }
            map.put(key, Math.max(map.getOrDefault(key, 0), nums[i]));
        }
        return maxSum;
    }

    private int summer(int n) {
        int sum = 0;
        while (n > 0) {
            sum+=n%10;
            n-=n%10;
            n /= 10;
        }
        return sum;
    }
}
