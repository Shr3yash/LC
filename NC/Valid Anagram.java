class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        // Map<String, List<String>> ans = new HashMap<>();
        // for(String s:strs){
        //     char[] cur = s.toCharArray();
        //     Arrays.sort(cur);
        //     String key = new String(cur);
        //     ans.computeIfAbsent(key, k->new ArrayList<>()).add(s);
        // }
        // return new ArrayList<>(ans.values());

        Map<String, List<String>> hm = new HashMap<>();
        for(String s:strs){
            int[] box = new int[26];
            for(char c:s.toCharArray()){
                box[c-'a']++;
            }
            String key = Arrays.toString(box);
            hm.putIfAbsent(key, new ArrayList<>());
            hm.get(key).add(s);
        }
        return new ArrayList<>(hm.values());
    }
}
