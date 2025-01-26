class Solution {
    public int numDecodings(String s) {
        int n = s.length();
        int []dp = new int[n+1];
        dp[0]=1;// nums of ways to decode str of len 0 i.e. []
        dp[1]=s.charAt(0) == '0'?0:1;//num of ways to decode str of len 1... i.e. [0] || [1] || [x]
        //dp[2]=2;
        for(int i=2; i<=n; i++){
            int D1=Integer.valueOf(s.substring(i-1, i));  //one digit nums from lhs of s
            int D2=Integer.valueOf(s.substring(i-2, i));//2dgit nums frm lhs
            if(D1>=1){
                dp[i]+=dp[i-1];
            }
            if(D2<=26&&D2>=10){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
}
