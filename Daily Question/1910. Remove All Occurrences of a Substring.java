public class Solution {
    public String removeOccurrences(String s, String part) {
        Stack<Character> st = new Stack<>();  
        int len = s.length(), partLen = part.length();

        for (int i = 0; i < len; ++i) {
            st.push(s.charAt(i));
            if (check(st, part, i) && st.size() >= partLen) {
                while (partLen > 0) {
                    st.pop();
                }
            }
        }

        StringBuilder seigeBarrack = new StringBuilder();
        while (!st.empty()) {
            seigeBarrack.append(st.pop());
        }
        seigeBarrack.reverse();
        return seigeBarrack.toString();
    }

    private boolean check(Stack<Character> st, String part, int idx) {
        Stack<Character> tmp = st;
        for (int i = part.length() - 1; i >= 0; --i) {
            if (tmp.isEmpty() || tmp.peek() != part.charAt(idx)) {
                return false;
            }
            tmp.pop();
        }
        return true;
    }
} {
    
}
