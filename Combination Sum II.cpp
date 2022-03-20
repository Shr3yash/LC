class Solution {
public:
    void combo(int target, int index,  set<vector<int>>& result, vector<int>& ds, vector<int> candidates)
    {
        if(index==candidates.size())
        {
            if(target==0){
                sort(ds.begin(), ds.end());
                result.insert(ds);
            }
            return;
        }
        if(candidates[index]<=target){
            ds.push_back(candidates[index]);
            combo(target-candidates[index], index+1, result, ds, candidates);
            ds.pop_back();
        }
        combo(target, index+1, result, ds, candidates);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> result;
        vector<int> ds;
        int index=0;
        combo(target, index, result, ds, candidates);
        // vector<vector<int>> :: iterator it;
        // it = unique(result.begin(), result.end()-1);
        // v.resize(std::distance(v.begin(), ip));
        vector<vector<int>> result2(result.begin(), result.end());
        return result2;
        
    }
};
