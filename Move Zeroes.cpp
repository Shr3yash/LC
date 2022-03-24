//sol1

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nz=0;
        for(int j=0; j<nums.size(); j++){
            if(nums[j]!=0){
                swap(nums[j],nums[nz]);
                nz++;
            }
        }
    }
};



//sol2 
//bit faster
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> x;
        int count=0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==0){

                count++;
            }
            else{
                x.push_back(nums[i]);}
            
        }
        while(count--) x.push_back(0);
        nums=x;
    }
};
