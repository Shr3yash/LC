class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hm;
        int longestSeq = 0;
        int localMax = 0;
        int left = 0;

        for (int right = 0; right < (int)s.size(); right++) {
            char c = s[right];

            if (hm.find(c) != hm.end()) {
                // shrink window from the left until c is not in the set
                while (hm.find(c) != hm.end()) {
                    hm.erase(s[left]);
                    left++;
                    localMax--;
                }
            }

            hm.insert(c);
            localMax++;
            longestSeq = max(longestSeq, localMax);
        }

        return longestSeq;
    }
};
