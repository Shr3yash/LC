Time complexity: O(n * logSIZE), where SIZE is the size of the search space (sum of weights - max weight).
Space complexity: O(1).

public int shipWithinDays(int[] weights, int d) {
    int lo = getMax(weights);
    int hi = getSum(weights);
    while (lo < hi) {
        int capacity = (lo + hi) >>> 1; // avoid overflow. same as (lo + hi) / 2
        int requiredDays = getRequiredDays(weights, capacity);

        if (requiredDays > d) {
            lo = capacity + 1;
        } else {
            hi = capacity;
        }
    }
    return lo;
}

private int getRequiredDays(int[] weights, int maxCapacity) {
    int requiredDays = 1;
    int capacity = 0;
    for (int weight : weights) {
        capacity += weight;
        if (capacity > maxCapacity) {
            requiredDays++;
            capacity = weight;
        }
    }
    return requiredDays;
}

private int getSum(int[] arr) {
    int sum = 0;
    for (int val : arr) {
        sum += val;
    }
    return sum;
}

private int getMax(int[] arr) {
    int max = Integer.MIN_VALUE;
    for (int val : arr) {
        max = Math.max(max, val);
    }
    return max;
}
