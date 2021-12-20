//   TLE (54/60)
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
