class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashMap <Integer, Integer> zero = new HashMap<>();
        for(int num: nums){
            if(zero.containsKey(num) && zero.get(num)>=1) return true;
            zero.put(num, zero.getOrDefault(num, 0) + 1);
            }
            return false;
    }
}
