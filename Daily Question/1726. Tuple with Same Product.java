import java.util.HashMap;

public class Solution {
    public int tupleSameProduct(int[] A) {
        int n = A.length;
        var m = new HashMap<Integer, Integer>();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                m.merge(A[i] * A[j], 1, Integer::sum);

        return m.values()
                .stream()
                .mapToInt(Solution::count)
                .sum();
    }

    private static int count(int n) { 
        return 8 * (n * (n - 1)) / 2;
    }
}