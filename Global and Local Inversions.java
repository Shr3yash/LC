class Solution {
    public boolean isIdealPermutation(int[] nums) {
        int max=-1;
        for(int i=0; i<nums.length-2; i++){
            max=Math.max(max, nums[i]);
            if(max>nums[i+2])return false;
        }
        return true;
    }
}
