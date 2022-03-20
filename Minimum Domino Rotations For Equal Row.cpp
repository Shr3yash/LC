//!!
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> eleT(7), eleB(7), eleS(7);
        int n = tops.size();
        for(int x=0; x<n; x++){
            eleT[tops[x]]+=1;
            eleB[bottoms[x]]+=1;
            if(tops[x]==bottoms[x])
                eleS[tops[x]]+=1;
        }
        int ans=n;
        for(int x=1; x<=6; x++){//as we're transcending through vector not array
            if(eleT[x]+eleB[x]-eleS[x]==6){
                //swa=min((min(eleT[x],eleB[x])-eleS[x]),swa); 
                int minSwap = min(eleT[x], eleB[x]) - eleS[x];
                ans = min(ans, minSwap);
            }
        }
        return ans==n?-1:ans;
    }
};
