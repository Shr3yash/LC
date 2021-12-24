//   TLE (54/60)
//   O(n^2) time, O(1) space
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAreaa=0,area=0;
        for(int i=0; i<height.size();i++)
            for(int j=i+1;j<height.size();j++){
                area=min(height[i],height[j])*(j-i);
                maxAreaa=max(maxAreaa,area);
        }
        return maxAreaa;
    }
};


//  optimized runs
//  O(n) time, O(n) space

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAreaa=0,area=0,i=0,j=height.size()-1;
        while(i<j){
            area=min(height[i],height[j])*(j-i);
            maxAreaa=max(maxAreaa,area);
            if(height[i]<=height[j]){i++;}
            else
                j--;
        }        
        return maxAreaa;
    }  
};
