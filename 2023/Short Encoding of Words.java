class Solution {
    public int minimumLengthEncoding(String[] words) {
        Arrays.sort(words,(a,b)->b.length()-a.length());//lambda expression to sort biggest length wali string first.
        StringBuilder encoded = new StringBuilder();
        
        for(String s:words)
            if(encoded.indexOf(s+"#")==-1)
                encoded.append(s+"#");
            
        return encoded.length();
    }
}
