class Solution {
    public boolean hasDuplicate(int[] nums) {
        // for(int i = 0; i < nums.length; i++){
        //     for(int j = i+1; j<nums.length; j++){
        //         if(nums[i] == nums[j])
        //             return true;
        //     }
        // }
        // return false;
        //n2, 1
        Set<Integer> hashmap = new HashSet<>();
        for(int n = 0; n<nums.length; n++){
            if(hashmap.contains(nums[n])){
                return true;
            }
            hashmap.add(nums[n]);
        }
        return false;
        //n, n
    }
}

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
