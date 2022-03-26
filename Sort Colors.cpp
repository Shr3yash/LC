class Solution {
    //TC=O(nlogn) SC= O(n). Merge sort 
    //THEN we can use hash map/say, counting sort and run loop to fill the 0s and 1s 
    //TC=O(2N) SC=O(N) ASC=O(0)
    
    //best will be by use of Dutch nnational flag algorithm 
    //TC=O(N), SC=O(1)
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size()-1;
        int mid=nums[0];
        int low=nums[0];
        int high=nums[n];
        
        for(int i=0; i<=n; i++){
            if(nums[i]==0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if(nums[i]==1){
                mid++;
            }
            else{
                high--;
                swap(nums[high], nums[mid]);
            }
        
            
        }
    }
};
