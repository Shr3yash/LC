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

class Solution {
    //linked list approach we will traverse the array with two ptrs slow is
    //half the speed of fast. therefore when they two meet fast has travelled sx and 
//     slow x. now make fast to 0 which means they have travelled equal, therefore after 
//         that when we traverse them with one speed they are bound to meet at the node where 
//         the joint is present in the linked list or the node which is duplicate.
        
//         linked list is made by the elements of array in space with their given sequence. 
//            ____
//           /	   \
// nums[0]--<      |
//           \____/
public:
    int findDuplicate(vector<int>& nums) {
        int fast=nums[0]; 
        int slow=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        
        fast=nums[0];
        while(fast!=slow){
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
        
    }
};
