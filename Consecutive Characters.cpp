class Solution {
public:
    int maxPower(string s) 
    {
        int count = 1, finalCount = 1;
        char pre = s[0];
        for(int i=1; i < s.length(); ++i)
        {
            if(s[i]==pre)
            {
                count++;
                finalCount =  max(count, finalCount);
            }
        
            else
            {
                
                count = 1;
                pre = s[i];
            }
            //abccdeeef

        }
         return finalCount;   
    }

};
