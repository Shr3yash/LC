class Solution {
public:
    void comb(vector<vector<int>>& res, vector<int>& ds, int index, int t, vector<int> c){
        
        if(index==c.size())
        {
            if(t==0){
                res.push_back(ds);
            }
            return; //?
        }
        if(c[index]<=t){
            ds.push_back(c[index]);
            comb(res, ds, index, t-c[index], c);
            ds.pop_back();
        }
        comb(res, ds, index+1, t, c);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> res;
        vector<int> ds;
        comb(res, ds, 0, t, c);
        return res;
        
        
    }
};
