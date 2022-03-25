class Solution {
public:
    //brute : sort array then on occurence of first similar indexed element return , 
    //sort(nums.begin(), nums.end());
    //nums[i]==num[i+1]; return nums[i];
    //Time Complexity: O(n Log n) 
    //Auxiliary Space: O(1)
    
    int findDuplicate(vector<int>& nums) {
        
        //better
        
        unordered_map<int,int> bet;
        //bet.assign(nums[nums.size()], 0);
        for(int i =0; i< nums.size(); i++){
            bet[nums[i]]++;
        }
        int maxCount=0, ans;
        for(auto& it: bet){
            if(maxCount<it.second){
                ans=it.first;
                maxCount=it.second;
            }
        }
        return ans;
        // Time Complexity : O(n) 
        // Auxiliary Space : O(n)
        
        
    }
};
