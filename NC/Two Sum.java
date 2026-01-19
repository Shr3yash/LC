class Solution {
    public int[] twoSum(int[] nums, int target) {
        //n2, 1

        int [] ans = {0,0};
        for(int i = 0; i < nums.length; ++i){
            int nt = target - nums[i];
            for(int j = i+1; j<nums.length; ++j){
                if(nums[j] == nt){
                    ans[0] = i; ans[1] = j;
                }
            }
        }
    
    HashMap <Integer, Integer> hm = new HashMap<>();
    for(int i  = 0; i <nums.length; ++i){
        if(hm.containsKey(target - nums[i])){
            ans[0] = hm.get(target - nums[i]);
            ans[1] = i;
            return ans;
        }
        hm.put(nums[i], i);
    }
            return ans;


}
}
