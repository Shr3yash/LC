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
