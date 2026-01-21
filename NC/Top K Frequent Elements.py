class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
      hashmap = {}
      for num in nums:
        hashmap[num] = hashmap.get(num, 0) + 1
      buffer = []
      for key, freq in hashmap.items():
        buffer.append([freq, key])
      buffer.sort(reverse=True)        
      return [key for freq, key in buffer[:k]]
