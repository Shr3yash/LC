from collections import defaultdict
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        countPairs = defaultdict(int)
        ans = 0
        
        for x, y in dominoes:
            key = tuple(sorted((x, y)))
            ans += countPairs[key]
            countPairs[key] += 1

        return ans
