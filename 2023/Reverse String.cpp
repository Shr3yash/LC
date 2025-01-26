//recur
void recur(string& s, int sr, int see){
    int sr=0,e=s.size()-1;
    if(sr>e)
      return;

    swap(s[sr],s[e]);
    sr++;
    e--;
    recur(s, sr, e);
}



//ey
class Solution {
public:
    void reverseString(vector<char>& s) {
        int sr=0,e=s.size()-1;
        while(sr<e)
        {
         swap(s[sr],s[e]);
         sr++;
         e--;
        }
        
    }
};
