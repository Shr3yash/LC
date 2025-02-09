class Solution {
    public long countBadPairs(int[] nums) {
        long badPairs = 0, totalPairs = 0, goodPairs = 0;

        /*
        for(int i = 0; i<nums.length-1; ++i){
            for(int j = i+1; j<nums.length; ++j){
                if(nums[j]-nums[i] != j-i) badPairs++;
            }
        }
        // O(n^2) TC - O(1) SC
        */
        HashMap<Integer, Integer> count =  new HashMap<>();

        for(int i = 0; i<nums.length; i++){
            totalPairs += i;
            goodPairs += count.getOrDefault(nums[i] - i, 0);
            count.put(nums[i] - i, count.getOrDefault(nums[i] - i, 0)+1);
        }
        return totalPairs - goodPairs;
    }
}