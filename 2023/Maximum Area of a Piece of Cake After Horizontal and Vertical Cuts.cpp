class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        hc.push_back(h);
        hc.push_back(0);
        vc.push_back(0);
        vc.push_back(w);
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        int maxx=0, maxy=0;
        for(int i=0; i<=h; ++i){
            if(i+1<=h){
                maxx=max(maxx, hc[i+1]-hc[i]);
            }
        }
        for(int i=0; i<=w; ++i){
            if(i+1<=w){
                maxx=max(maxx, vc[i+1]-vc[i]);
            }
        }
        return maxx*maxy;
    }
};
