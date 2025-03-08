class Solution {
    public int minimumRecolors(String blocks, int k) {
        int currentWhite = 0;
        for (int i = 0; i < k; i++) {
            if (blocks.charAt(i) == 'W') {
                currentWhite++;
            }
        }
        int minWhite = currentWhite;
        for (int i = 1; i <= blocks.length() - k; i++) {
            if (blocks.charAt(i - 1) == 'W') {
                currentWhite--;
            }
            if (blocks.charAt(i + k - 1) == 'W') {
                currentWhite++;
            }
            if (currentWhite < minWhite) {
                minWhite = currentWhite;
            }
        }
        return minWhite;
    }
}
