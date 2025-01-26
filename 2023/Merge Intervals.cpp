class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> oput;
        sort(intervals.begin(), intervals.end());
        int i = intervals[0][0], j = intervals[0][1];
        for(auto iter:intervals) {
            if(iter[0] <= j) {
                j = max(j, iter[1]);
            } else {
                oput.push_back({i, j});
                i = iter[0];
                j = iter[1];
            }
        }
        oput.push_back({i, j});
        return oput;
