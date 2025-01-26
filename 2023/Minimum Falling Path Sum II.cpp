class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        // vector<int> sopti(n, 0), current(n,0);
//         for(int i =0; i<n; i++){
//             sopti[i]=grid[0][i];
//         }
        
//         for(int i=1; i<n;i++){
//             for (int j=0; j<n; j++){
                
//             }
//         }

        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int temp=grid[i-1][j];
                grid[i-1][j]=INT_MAX;
                grid[i][j]+=*min_element(grid[i-1].begin(),grid[i-1].end());
                grid[i-1][j]=temp;
            }
        }
        
        return *min_element(grid[n-1].begin(),grid[n-1].end());

    }
};
