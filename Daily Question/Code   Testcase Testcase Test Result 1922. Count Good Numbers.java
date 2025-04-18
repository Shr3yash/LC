class Solution {
private final long MOD = 1_000_000_007;

public int countGoodNumbers(long n) {
        long evenPositions = (n + 1) / 2; // 5 options
        long oddPositions = n / 2;        //4

        long result = lognMul(5, evenPositions) * lognMul(4, oddPositions);
        return (int)(result % MOD);
    }

private long lognMul(int base, long exponent) {
        long result = 1;
        long power = base;

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * power) % MOD;
            }
            power = (power * power) % MOD;
            exponent /= 2;
        }

        return result;
    }

}
