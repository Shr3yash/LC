//TLE
//O(n2) & O(1)
class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int water=0;
        vector<int>::iterator it;
        for(int i=0; i<height.size(); i++)
        {
            int ptrLeft=i, ptrRight=i, maxLeft=0, maxRight=0;
            while(ptrLeft>=0)
            {
                maxLeft=max(maxLeft,height[ptrLeft]);
                ptrLeft--;
            }
            while(ptrRight<height.size())
            {
                maxRight=max(maxRight,height[ptrRight]);
                ptrRight++;
            }
            
            int currentWater=min(maxLeft,maxRight)-height[i];
            
            if(currentWater>=0)
            {
                water+=currentWater;
            } 
        }
        return water;
    }
};
