class Solution {
public:
    bool isSubsequence(string s, string t) {
        int y=0;
        for(int x=0;y<s.length()&&x<t.length();x++)
            if(s[y]==t[x])
                y++;
        return (y==s.length());
        
    }
};

//Wrecursion

class Solution {
public:
    bool recur(string& x, string& y, int n, int m)
    {
        if(n==0)
            return true;
        if(m==0)
            return false;
        if(x[n-1]==y[m-1])
            return recur(x,y,n-1,m-1);
        return recur(x,y,n,m-1);
    }
    bool isSubsequence(string s, string t) {

        if(recur(s,t,s.length(),t.length()))
            return true;
        return false;
        
    }
};
