public private Stack<Integer> st;
private Stack<Integer> productStack;

public ProductOfNumbers() {
    st = new Stack<>();
    productStack = new Stack<>();
}

public void add(int num) {
    st.push(num);
    if (num == 0) {
        productStack.push(1);
    } else if (productStack.isEmpty()) {
        productStack.push(num);
    } else {
        productStack.push(productStack.peek() * num);
    }
}

public int getProduct(int k) {
    if (k > st.size()) {
        return 0;
    }
    int productBeforeK = (st.size() - k - 1 >= 0) ? productStack.get(st.size() - k - 1) : 1;
    return productStack.peek() / productBeforeK;
} {
    
}
