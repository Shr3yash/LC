   
    typedef long long ll;
    ll mod = 1e9+7;
    int count(int n,  vector<long long int>& dp){
        
        if(n==1) return dp[n]=2; // as two arrangements available when there's one free block
        if(n==2) return dp[n]=3;
        
        if(dp[n]!=-1)return dp[n];
        
        long long int pick, npick;
        pick=count(n-2, dp); //as after picking we are leavng a space
        npick=count(n-1, dp); //if didn't pick we can always choose anything over next ind

        return dp[n]=(pick*npick)%mod;
    }
    int countHousePlacements(int n) {
        
        
        //vector<vector<int>> dp(2 , vector<int> (n, 0));
        //cout<<dp.size()<<" col"<<dp[0].size();
        vector<long long int> dp(n+1, -1); //counts arrangement possibilities for upto n
        return (count(n, dp)*count(n, dp))%mod;
    }
