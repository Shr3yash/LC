class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        HashMap <Character, Integer> HSQ = new HashMap<>();
        HashMap <Character, Integer> HSW = new HashMap<>();

        for(int i = 0; i < s.length(); ++i){
            HSQ.put(s.charAt(i), HSQ.getOrDefault(s.charAt(i), 0)+1);
            HSW.put(t.charAt(i), HSW.getOrDefault(t.charAt(i), 0)+1);
        }
        for(char num : HSQ.keySet()){
            if(!HSQ.get(num).equals(HSW.get(num))) return false;
        }
        return true;
    }
}
