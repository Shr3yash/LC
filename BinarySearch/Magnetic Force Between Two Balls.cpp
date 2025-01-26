//Wrong answer.

class Solution {
public:
    bool isPossible(vector<int>& position, int m, int mid){
        int numOballs=1;    //base case
        int firstPosi=position[0];  //by def placing the first ball on the 0th index and then we'll place                                       //one by one  until we place all the balls
        for(int i=0; i<position.size(); i++){
            if(position[i]-firstPosi>=mid){
                numOballs++;
                if(numOballs==m)return true;
                firstPosi=position[i];
            }
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int s=0;
        int ans=-1, maxi=-1;
        
        for(auto it:position){
            maxi=max(maxi,it);
        }
        int e=maxi;
        int mid=(s+e)>>1;
        
        while(s<e){
            if(isPossible(position, m, mid)){   //hypothesis +ve, since +ve we can aim for much higher 
                                                //values of force therefore bs again in higher value array 
                ans=mid;                        //dont forget to store the recent possible answer
                s=mid+1;
            }
            else{
                e=mid-1;                        //hypothesis failed, lowering expectations.
                                                // bs the smaller search space
            }
            mid=(s+e)>>1;                       //dont forget to update the mid
        }
        return ans;                     
        
    }
};









//Rgiht answer
class Solution {
    public:
            bool isPossible(vector<int> &stalls, int k, int mid, int n) {

                int cowCount = 1;
                int lastPos = stalls[0];

                for(int i=0; i<n; i++ ){

                    if(stalls[i]-lastPos >= mid){
                        cowCount++;
                        if(cowCount==k)
                        {
                            return true;
                        }
                        lastPos = stalls[i];
                    }
                }
                return false;
            }

            int maxDistance(vector<int> &stalls, int k)
            {
                sort(stalls.begin(), stalls.end());
                int s = 0;
                int n = stalls.size();
                int e=stalls[n-1];
                int ans = -1;
                int mid = s + (e-s)/2;

                while(s<=e) {
                    if(isPossible(stalls, k, mid, n)) {
                        ans = mid;
                        s = mid + 1;
                    }
                    else
                    {
                        e = mid - 1;
                    }
                    mid = s + (e-s)/2;
                }
                return ans;
            }
};
