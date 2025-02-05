class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        bool delta1 =  false, delta2 = false;
        char seen1, seen2;
        for(int i = 0; i<s2.size(); ++i){
            if(s1[i] != s2[i]) {
                if(!delta1){
                    seen1 = s1[i];
                    seen2 = s2[i];
                    delta1 = true;
                }
                //again 
                else if(delta1 && !delta2){
                    if(seen1 == s2[i] && seen2 == s1[i]){
                        delta2 = true;
                    }
                    else return false;
                }
                else{
                    return false;
                }
            }
        }
        if( delta1 == delta2) return true;
        else return false;
    }
};