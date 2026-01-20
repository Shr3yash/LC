class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> ans = new HashMap<>();
        for(String s:strs){
            char[] cur = s.toCharArray();
            Arrays.sort(cur);
            String key = new String(cur);
            ans.computeIfAbsent(key, k->new ArrayList<>()).add(s);
        }
        return new ArrayList<>(ans.values());
    }
}
